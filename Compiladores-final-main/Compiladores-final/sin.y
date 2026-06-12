%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabela.h"

int cont_read = 0;
int houve_erro = 0;
int dentro_switch = 0;
extern int yylex();
void yyerror(const char *s) {printf("Erro: %s\n", s);
houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char declaracoes_temp[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

int escopo_atual = 0;
%}

%union {
    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
        int tam_str;
    } info;
}

%token TOKEN_FOR
%token TOKEN_MAIN
%token <valor_str> ID NUM_INT NUM_FLOAT CHAR_LIT BOOL_LIT STRING_LIT
%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL TOKEN_STRING ASSIGN PLUS
%token TOKEN_PRINT TOKEN_READ TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_DO
%token TOKEN_SWITCH TOKEN_CASE TOKEN_DEFAULT TOKEN_BREAK
%token TOKEN_CONTINUE
%token AND OR EQ NE LE GE NOT

%left OR
%left AND
%left EQ NE '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right NOT
%right CAST
%right UMINUS

%type <info> expressao
%type <valor_str> if_cond
%type <valor_str> incremento_for
%type <valor_str> for_init

%%

programa : declaracoes_globais TOKEN_MAIN '(' ')' bloco
    ;

declaracoes_globais
    : declaracao ';' declaracoes_globais
    |
    ;

bloco : '{' { escopo_atual++; } comandos_bloco '}' {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
    ;

comandos_bloco : comando comandos_bloco
                |
                ;

/* --- REGRA AUXILIAR DO IF --- */
if_cond : TOKEN_IF '(' expressao ')' {
    if ($3.tipo_val != T_BOOL) {
        yyerror("Erro Semantico: A condicao do 'if' deve ser booleana.");
    }
    char* l_false = novo_label();
    
    /* --- INICIO DA MODIFICACAO --- */
    char* t_inv = novo_temp(T_BOOL);
    
    // 1. Nega o resultado original
    sprintf(buf, "%s = !%s;\n", t_inv, $3.temp);
    strcat(instrucoes, buf);
    
    // 2. Verifica se a negacao eh verdadeira para pular
    sprintf(buf, "if (%s) goto %s;\n", t_inv, l_false);
    strcat(instrucoes, buf);

    strcat(instrucoes, "\n");
    /* --- FIM DA MODIFICACAO --- */
    
    sprintf(buf, "if (%s) {\n", $3.c_expr);
    strcat(c_body, buf);
    
    $<valor_str>$ = l_false; /* Passa o label pra frente */
}
;

/* --- REGRAS AUXILIARES DO FOR --- */
for_init : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada na inicializacao do for.");
    } else {
        // Gera o 3AC direto
        sprintf(buf, "%s = %s;\n", s->temp, $3.temp);
        strcat(instrucoes, buf);
        
        // Em vez de imprimir no C, retorna a string formatada
        char* init_str = (char*) malloc(256);
        sprintf(init_str, "%s = %s", s->nome, $3.c_expr);
        $$ = init_str;
    }
}
;

incremento_for : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
    } else {
        // Guarda o 3AC na variavel temporaria
        sprintf(inc_3ac, "%s = %s;\n", s->temp, $3.temp);
        
        // Em vez de imprimir no C, retorna a string formatada
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s = %s", s->nome, $3.c_expr);
        $$ = inc_str;
    }
}
;

casos_lista : caso casos_lista
            | default_caso
            | /* vazio */
            ;

caso : TOKEN_CASE expressao ':' {
        // 1. Gera rótulo pro próximo case (se este falhar)
        char* l_proximo = novo_label();

        // 2. Compara a expressão do Switch com a expressão do Case
        char* t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t_cmp, switch_exp, $2.temp);
        strcat(instrucoes, buf);

        /* --- INICIO DA MODIFICACAO --- */
        char* t_inv = novo_temp(T_BOOL);
        
        // 3. Nega a comparacao
        sprintf(buf, "%s = !%s;\n", t_inv, t_cmp);
        strcat(instrucoes, buf);

        // 4. Se a negacao for verdadeira, pula pro proximo case
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_proximo);
        strcat(instrucoes, buf);
        /* --- FIM DA MODIFICACAO --- */

        // 5. Código C
        sprintf(buf, "case %s:\n", $2.c_expr);
        strcat(c_body, buf);

        $<valor_str>$ = l_proximo;

    } comandos_bloco {

        // 5. Fim do case: pula pro fim do switch
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);

        // 6. Imprime o rótulo do próximo case
        sprintf(buf, "%s:\n", $<valor_str>4);
        strcat(instrucoes, buf);
    }
    ;

default_caso : TOKEN_DEFAULT ':' {
        strcat(c_body, "default:\n");
    } comandos_bloco {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
    ;

comando : declaracao ';'
        | atribuicao ';'
        | expressao ';' 
        | bloco 
        | TOKEN_PRINT '(' expressao ')' ';'
        {
            // Descobre o formato para o printf do C
            char* formato = "";
            if ($3.tipo_val == T_INT || $3.tipo_val == T_BOOL) formato = "%d";
            else if ($3.tipo_val == T_FLOAT) formato = "%f";
            else if ($3.tipo_val == T_CHAR) formato = "%c";
            else if ($3.tipo_val == T_STRING) formato = "%s";

            // Gera o Código Intermediário já como printf válido no C
            sprintf(buf, "printf(\"%s\\n\", %s);\n", formato, $3.temp);
            strcat(instrucoes, buf);
        }
            /* --- COMANDO DE ENTRADA (READ) --- */
            | TOKEN_READ '(' ID ')' ';' {
                Simbolo *s = buscar($3);
                if (!s) {
                    char erro_msg[100];
                    sprintf(erro_msg, "Erro: Variavel '%s' nao declarada para leitura.", $3);
                    yyerror(erro_msg);
                } else {
                    // 1. Descobre o formato para o scanf do C
                    char* formato = "";
                    if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
                    else if (s->tipo == T_FLOAT) formato = "%f";
                    else if (s->tipo == T_CHAR) formato = " %c"; 

                    // 2. Gera o scanf correspondente direto na variável 'instrucoes'
                    if (s->tipo == T_STRING) {
                        // Limita o scanf a 255 letras para evitar que estoure o array de 256
                        sprintf(buf, "scanf(\"%%255s\", %s);\n", s->temp);
                        strcat(instrucoes, buf);
                    } else {
                        sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->temp);
                        strcat(instrucoes, buf); 
                    }
                }
            }
        | if_cond comando {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", $<valor_str>1); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
        | if_cond comando TOKEN_ELSE {
            // METADE DO ELSE
            char* l_fim = novo_label();
            
            // 1. O 'true' pula pro fim
            sprintf(buf, "goto %s;\n", l_fim);
            strcat(instrucoes, buf);
            
            // 2. Imprime o label do 'false' (que veio do if_cond)
            sprintf(buf, "%s:\n", $<valor_str>1);
            strcat(instrucoes, buf);
            
            // 3. Código C
            strcat(c_body, "} else {\n");
            
            // Passa o label de fim para o próximo bloco
            $<valor_str>$ = l_fim; 
            
        } comando {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", $<valor_str>4); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        } 
        | TOKEN_WHILE {
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        } '(' expressao ')' {
            if ($4.tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao deve ser booleana.");
            
            char* l_fim = novo_label();
            
            /* --- INICIO DA MODIFICACAO --- */
            char* t_inv = novo_temp(T_BOOL);
            
            sprintf(buf, "%s = !%s;\n", t_inv, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
            strcat(instrucoes, buf);

            strcat(instrucoes, "\n");
            /* --- FIM DA MODIFICACAO --- */
            
            sprintf(buf, "while (%s) {\n", $4.c_expr);
            strcat(c_body, buf);
            $<valor_str>$ = l_fim; 
            
            // --- LINHAS NOVAS 2 e 3: Salva o fim e sobe a pilha ---
            strcpy(pilha_fim[topo_laco], l_fim);
            topo_laco++;
        } comando { 
            
            // 1. Desce o topo da pilha para recuperar os labels deste laço
            topo_laco--; 
            
            // 2. No final do bloco, o TAC precisa voltar para o início do teste condicional
            sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco]);
            strcat(instrucoes, buf);
            
            // 3. Imprime o rótulo de FIM (O L2 que estava faltando!)
            sprintf(buf, "%s:\n", pilha_fim[topo_laco]);
            strcat(instrucoes, buf);
            
            // 4. Fecha as chaves do bloco no código C
            strcat(c_body, "}\n");
        }
        | TOKEN_DO {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio;
            strcat(c_body, "do {\n");
        } comando TOKEN_WHILE '(' expressao ')' ';' {
            // Agora a expressao é o $6, porque:
            // 1=TOKEN_DO, 2={...}, 3=comando, 4=WHILE, 5='(', 6=expressao
            
            if ($6.tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'do-while' deve ser booleana.");
            }
            
            // Pula para o início se for verdadeiro
            sprintf(buf, "if (%s) goto %s;\n", $6.temp, $<valor_str>2);
            strcat(instrucoes, buf);
            
            // Código C
            sprintf(buf, "} while (%s);\n", $6.c_expr);
            strcat(c_body, buf);
        }
        | TOKEN_FOR '(' for_init ';' {
            // 1. Marca visualmente no 3AC que é um FOR
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            char* l_incremento = novo_label(); // NOVO RÓTULO: Para o incremento!
            
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio; // Salva o início (condicional) na posição $5
            
            // ALTERAÇÃO: Salva o rótulo do INCREMENTO na pilha para o 'continue' pular pra cá
            strcpy(pilha_inicio[topo_laco], l_incremento);
            
        } expressao ';' {
            // 2. Verifica a CONDIÇÃO
            if ($6.tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'for' deve ser booleana.");
            }
            char* l_fim = novo_label();
            
            /* --- INICIO DA MODIFICACAO (TAC INVERSO) --- */
            char* t_inv = novo_temp(T_BOOL);
            sprintf(buf, "%s = !%s;\n", t_inv, $6.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
            strcat(instrucoes, buf);
            /* --- FIM DA MODIFICACAO --- */
            
            $<valor_str>$ = l_fim; // Salva na posição $8
            
            // Salva o fim na pilha para o 'break' e sobe a pilha
            strcpy(pilha_fim[topo_laco], l_fim);
            topo_laco++; 
            
            // GERA O 'FOR' LITERAL NO CÓDIGO C
            sprintf(buf, "for (%s; %s; ", $3, $6.c_expr);
            strcat(c_body, buf);
            
        } incremento_for ')' {
            // 3. Fecha os parênteses do FOR no C
            sprintf(buf, "%s) {\n", $9);
            strcat(c_body, buf);
            
        } comando {
            // 4. Chegamos no final do laço!
            topo_laco--; // Desce a pilha de laços
            
            // --- NOVO PASSO: Imprime o rótulo do INCREMENTO aqui ---
            // Recuperamos o l_incremento lendo a própria pilha_inicio!
            sprintf(buf, "%s:\n", pilha_inicio[topo_laco]);
            strcat(instrucoes, buf);
            
            // Imprime o incremento do 3AC que estava guardado
            strcat(instrucoes, inc_3ac);
            
            // Pula de volta pro início (A condicional no $5) no 3AC
            sprintf(buf, "goto %s;\n", $<valor_str>5);
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM no 3AC
            sprintf(buf, "%s:\n", $<valor_str>8);
            strcat(instrucoes, buf);
            strcat(instrucoes, "\n");
            
            // Fecha a chave no C
            strcat(c_body, "}\n");
        }
        |TOKEN_SWITCH '(' expressao ')' {
            // Marca que entrou em um switch
            dentro_switch++;

            // Salva a expressão do switch e o label de saída
            strcpy(switch_exp, $3.temp);
            strcpy(switch_fim, novo_label());

            strcpy(pilha_fim[topo_laco], switch_fim);
            strcpy(pilha_inicio[topo_laco], "ERRO_CONTINUE_SWITCH");
            topo_laco++;

            // Código C
            sprintf(buf, "switch (%s) {\n", $3.c_expr);
            strcat(c_body, buf);

        } '{' casos_lista '}' {

            // Saiu do switch
            dentro_switch--;

            topo_laco--;

            // Label de saída do switch no código intermediário
            sprintf(buf, "%s:\n", switch_fim);
            strcat(instrucoes, buf);

            // Fecha o switch no C
            strcat(c_body, "}\n");
        }
        /* --- COMANDOS DE PULO --- */
        | TOKEN_BREAK ';' {

            if (topo_laco > 0) {

                // break dentro de while/for/do-while
                sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
                strcat(instrucoes, buf);

            } else if (dentro_switch > 0) {

                // break dentro de switch
                sprintf(buf, "goto %s;\n", switch_fim);
                strcat(instrucoes, buf);

            } else {

                yyerror("Erro Semantico: 'break' usado fora de um laco ou switch.");

            }

            strcat(c_body, "break;\n");
        }
        | TOKEN_CONTINUE ';' {
            if (topo_laco == 0) {
                yyerror("Erro Semantico: 'continue' usado fora de um laco de repeticao.");
            } else {
                // Pula para o rótulo de INÍCIO do laço atual
                sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
                strcat(instrucoes, buf);
                strcat(c_body, "continue;\n");
            }
        }

declaracao : TOKEN_INT   ID {
                inserir($2, T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_FLOAT ID {
                inserir($2, T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_CHAR  ID {
                inserir($2, T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_BOOL ID {
                 inserir($2, T_BOOL, escopo_atual);
                 sprintf(buf, "int %s;\n", $2);
                 strcat(c_decl, buf);
             }
            | TOKEN_STRING ID {
                inserir($2, T_STRING, escopo_atual);
                sprintf(buf, "char %s[256];\n", $2);
                strcat(c_decl, buf);
             }
           ;

atribuicao : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        char erro_msg[100];
        sprintf(erro_msg, "Erro: Variavel '%s' nao declarada.", $1);
        yyerror(erro_msg);
    } else {
        char* valor_final  = $3.temp;
        char* c_expr_final = $3.c_expr;
        int sem_erro = 1;

        if (s->tipo == T_FLOAT && $3.tipo_val == T_INT) {
            valor_final = gerar_cast($3.temp, T_FLOAT);
            char *tmp = (char*) malloc(256);
            strcpy(tmp, "(float)(");
            strcat(tmp, c_expr_final);
                strcat(tmp, ")");
            c_expr_final = tmp;

        } else if (s->tipo == T_INT && $3.tipo_val == T_FLOAT) {
        valor_final = gerar_cast($3.temp, T_INT);
        char *tmp = (char*) malloc(256);
        strcpy(tmp, "(int)(");
        strcat(tmp, c_expr_final);
        strcat(tmp, ")");
        c_expr_final = tmp;

        } else if (s->tipo != $3.tipo_val) {
            yyerror("Erro Semantico: Atribuicao com tipos incompativeis.");
            sem_erro = 0;
        }

        if (sem_erro) {
            if (s->tipo == T_STRING) {
                int id_temp;

                sscanf(s->temp, "T%d", &id_temp); 

                tamanhos_t[id_temp] = $3.tam_str;

                sprintf(buf, "strcpy(%s, %s);\n", s->temp, valor_final);
            } else {
                sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            }
            strcat(instrucoes, buf);

            // Código C original
            if (s->tipo == T_STRING) {
                sprintf(buf, "strcpy(%s, %s);\n", s->nome, c_expr_final);
            } else {
                sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
            }
            strcat(c_body, buf);
        }
    }
};

expressao : NUM_INT {
                $$.tipo_val = T_INT;
                $$.temp = strdup($1);
                $$.c_expr = strdup($1);
            }
          | NUM_FLOAT {
                $$.tipo_val = T_FLOAT;
                $$.temp   = novo_temp(T_FLOAT);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | CHAR_LIT {
                $$.tipo_val = T_CHAR;
                $$.temp   = novo_temp(T_CHAR);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | BOOL_LIT {
                $$.tipo_val = T_BOOL;
                $$.temp   = novo_temp(T_BOOL);
                $$.c_expr = strdup($1);
                sprintf(buf, "%s = %s;\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
            | STRING_LIT {
                $$.tipo_val = T_STRING;
                int tamanho_calculado = strlen($1) - 1; 
                $$.tam_str = tamanho_calculado;
                $$.temp = novo_temp_str(tamanho_calculado);
                $$.c_expr = strdup($1);
                sprintf(buf, "strcpy(%s, %s);\n", $$.temp, $1);
                strcat(instrucoes, buf);
            }
          | ID {
                Simbolo *s = buscar($1);
                if (s) {
                    $$.tipo_val = s->tipo;
                    $$.temp   = s->temp;
                    $$.c_expr = strdup(s->nome);

                    if (s->tipo == T_STRING) {
                        int id_temp;
                        sscanf(s->temp, "T%d", &id_temp);
                        $$.tam_str = tamanhos_t[id_temp]; 
                    } else {
                        $$.tam_str = 0;
                    }
                    
                } else {
                    yyerror("Var nao declarada");
                    $$.temp   = "ERRO";
                    $$.c_expr = strdup("ERRO");
                    $$.tipo_val = T_INT;
                    $$.tam_str = 0;
                }
            }

          /* --- ARITMÉTICA --- */
          | expressao PLUS expressao {
                // 1. Caso: String (String + String)
                if ($1.tipo_val == T_STRING && $3.tipo_val == T_STRING) {
                    $$.tipo_val = T_STRING;

                    int tamanho_soma = $1.tam_str + $3.tam_str - 1;
                    $$.tam_str = tamanho_soma;

                    $$.temp = novo_temp_str(tamanho_soma);

                    sprintf(buf, "strcpy(%s, %s);\n"
                                 "strcat(%s, %s);\n", 
                                 $$.temp, $1.temp, 
                                 $$.temp, $3.temp);
                    strcat(instrucoes, buf);
                    
                    char *ce = (char*) malloc(tamanho_soma);
                    sprintf(ce, "(%s + %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;

                    free($1.c_expr);
                    free($3.c_expr);
                }
                // 2. Caso: Numérico (Int ou Float)
                else if (($1.tipo_val == T_INT || $1.tipo_val == T_FLOAT) && 
                        ($3.tipo_val == T_INT || $3.tipo_val == T_FLOAT)) {
                    
                    char *ce1 = $1.c_expr;
                    char *ce3 = $3.c_expr;

                    if ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) {
                        $$.tipo_val = T_FLOAT;
                    } else {
                        $$.tipo_val = T_INT;
                    }

                    if ($$.tipo_val == T_FLOAT) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT);
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1);
                            ce1 = tmp;
                        }
                        if ($3.tipo_val == T_INT) {
                            $3.temp = gerar_cast($3.temp, T_FLOAT);
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3);
                            ce3 = tmp;
                        }
                    }

                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s + %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s + %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
                // 3. Caso: Tipos incompatíveis (Erro Semântico)
                else {
                    yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                }
            }
          | expressao '-' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de subtracao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s - %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s - %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
            }
          | expressao '*' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    if ($1.tipo_val == T_INT) {
                        $1.temp = gerar_cast($1.temp, T_FLOAT);
                        $1.tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce1);
                        ce1 = tmp;
                    } else {
                        $3.temp = gerar_cast($3.temp, T_FLOAT);
                        $3.tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce3);
                        ce3 = tmp;
                    }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s * %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s + %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
          | expressao '/' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                   if ($1.tipo_val == T_INT) {
                        $1.temp = gerar_cast($1.temp, T_FLOAT);
                        $1.tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce1);
                        ce1 = tmp;
                    } else {
                        $3.temp = gerar_cast($3.temp, T_FLOAT);
                        $3.tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce3);
                        ce3 = tmp;
                    }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s / %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s + %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }

          /* --- RELACIONAIS (C/ Checagem de Tipo) --- */
          | expressao EQ expressao {
                if (($1.tipo_val == T_BOOL && $3.tipo_val != T_BOOL) ||
                    ($1.tipo_val != T_BOOL && $3.tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '==' entre tipos incompativeis.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s == %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s == %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao NE expressao {
                if (($1.tipo_val == T_BOOL && $3.tipo_val != T_BOOL) ||
                    ($1.tipo_val != T_BOOL && $3.tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '!=' entre tipos incompativeis.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s != %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s < %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao '>' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s > %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                   char *ce = (char*) malloc(256);
                   sprintf(ce, "(%s > %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao '<' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s < %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s < %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao GE expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>=' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s >= %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s >= %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao LE expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<=' exige operandos numericos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s <= %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s <= %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }

          /* --- LÓGICOS E PARÊNTESES --- */
          | expressao AND expressao {
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos booleanos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s && %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s && %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | expressao OR expressao {
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador OR requer operandos booleanos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s || %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s || %s)", $1.c_expr, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
          | NOT expressao {
                if ($2.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador NOT requer operando booleano.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_BOOL;
                } else {
                    $$.tipo_val = T_BOOL;
                    $$.temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = !%s;\n", $$.temp, $2.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(200);
                    sprintf(ce, "(!%s)", $2.c_expr);
                     $$.c_expr = ce;
                }
            }

                            | '(' TOKEN_INT ')' expressao %prec CAST {
                        char* temp_copia = novo_temp($4.tipo_val);
                        sprintf(buf, "%s = %s;\n", temp_copia, $4.temp);
                        strcat(instrucoes, buf);

                        $$.tipo_val = T_INT;
                        $$.temp = novo_temp(T_INT);

                        sprintf(buf, "%s = (int) %s;\n", $$.temp, temp_copia);
                        strcat(instrucoes, buf);

                        char *ce = (char*) malloc(256);

                        strcpy(ce, "(int)(");
                        strcat(ce, $4.c_expr);
                        strcat(ce, ")");

                        $$.c_expr = ce;
                    }
                    | '(' TOKEN_FLOAT ')' expressao %prec CAST {
                char* temp_copia = novo_temp($4.tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, $4.temp);
                strcat(instrucoes, buf);

                $$.tipo_val = T_FLOAT;
                $$.temp = novo_temp(T_FLOAT);

                sprintf(buf, "%s = (float) %s;\n", $$.temp, temp_copia);
                strcat(instrucoes, buf);

                char *ce = (char*) malloc(256);

                strcpy(ce, "(float)(");
                strcat(ce, $4.c_expr);
                strcat(ce, ")");

                $$.c_expr = ce;
            }
          | '(' expressao ')' {
                $$ = $2;
            }
                    | '-' expressao %prec UMINUS {
                $$.tipo_val = $2.tipo_val;
                $$.temp = novo_temp($$.tipo_val);
                sprintf(buf, "%s = -%s;\n", $$.temp, $2.temp);
                strcat(instrucoes, buf);

                char *ce = (char*) malloc(256);

                strcpy(ce, "(-");
                strcat(ce, $2.c_expr);
                strcat(ce, ")");

                $$.c_expr = ce;
            }
          ;

%%

#include <stdlib.h> // Necessário para a função system()

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    gerar_declaracoes_finais();

    /* 1. VISUALIZAÇÃO DO CÓDIGO INTERMEDIÁRIO (Terminal) */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");

    printf("int main()\n");
    printf("{\n");
    printf("%s\n", declaracoes);
    printf("%s", instrucoes);
    printf("    return 0;\n");
    printf("}\n");

    /* 2. GERAÇÃO DO CÓDIGO (Arquivo saida.c) */
    FILE *arquivo_c = fopen("saida.c", "w");
    if (!arquivo_c) {
        printf("Erro: Nao foi possivel criar o arquivo saida.c\n");
        return 1;
    }

    fprintf(arquivo_c, "#include <stdio.h>\n");
    fprintf(arquivo_c, "#include <stdlib.h>\n");
    fprintf(arquivo_c, "#include <string.h>\n");
    fprintf(arquivo_c, "#include <stdbool.h>\n\n");
    
    fprintf(arquivo_c, "int main()\n{\n");
    fprintf(arquivo_c, "%s\n", declaracoes);
    fprintf(arquivo_c, "%s", instrucoes);
    fprintf(arquivo_c, "    return 0;\n}\n");

    fclose(arquivo_c);

    int status_gcc = system("gcc saida.c -o programa.exe");
    if (status_gcc != 0) {
        printf("Erro no compilador\n");
    }

    return 0;
}