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
extern int yylineno;
void yyerror(const char *s) {
    fprintf(stderr, "\n----------------------------------------\n");
    fprintf(stderr, "Erro na linha %d:\n", yylineno);
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "----------------------------------------\n");
    houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char declaracoes_temp[5000] = "";
char instrucoes_funcoes[5000] = "";
char instrucoes_globais[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

Simbolo *simbolo_array_atual = NULL;
int idx_array_atual = 0;
int tam_array_atual = 0;
int idx_dim1_atual = 0;
int idx_dim2_atual = 0;
int tam_dim1_atual = 0;
int tam_dim2_atual = 0;

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
%token TOKEN_VAR
%token TOKEN_PRINT TOKEN_READ TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_DO
%token TOKEN_SWITCH TOKEN_CASE TOKEN_DEFAULT TOKEN_BREAK
%token TOKEN_BREAK_ALL
%token TOKEN_CONTINUE
%token AND OR EQ NE LE GE NOT
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN
%token INC DEC
%token TOKEN_VOID TOKEN_RETURN

%define parse.error verbose

%left OR
%left AND
%left EQ NE '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right '^'
%right NOT
%right CAST
%right UMINUS

%type <info> expressao parametros parametro argumentos lista_args
%type <valor_str> if_cond
%type <info> incremento_for
%type <valor_str> for_init

%%

programa : elementos_globais { 
        strcpy(instrucoes_globais, instrucoes);
        instrucoes[0] = '\0';
    } TOKEN_MAIN '(' ')' bloco
    ;

elementos_globais
    : elemento_global elementos_globais
    | 
    ;

elemento_global
    : declaracao ';'
    | funcao
    ;

funcao : TOKEN_VOID ID '(' parametros ')' '{' {
            // 1. Salva o TAC global gerado até agora e limpa pro corpo da função
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 

            inserir_funcao($2, T_VOID, escopo_atual);
            
            sprintf(buf, "\nvoid %s(%s) {\n", $2, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nvoid %s(%s) {\n", $2, $4.c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         } comandos_bloco '}' {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            // 2. Salva a função pronta e limpa para o próximo elemento global
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
       | TOKEN_INT ID '(' parametros ')' '{' {
            // 1. Salva o TAC global gerado até agora e limpa pro corpo da função
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 

            inserir_funcao($2, T_INT, escopo_atual);
            
            sprintf(buf, "\nint %s(%s) {\n", $2, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nint %s(%s) {\n", $2, $4.c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         } comandos_bloco '}' {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            // 2. Salva a função pronta e limpa para o próximo elemento global
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
         | TOKEN_FLOAT ID '(' parametros ')' '{' {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao($2, T_FLOAT, escopo_atual);
            
            sprintf(buf, "\nfloat %s(%s) {\n", $2, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nfloat %s(%s) {\n", $2, $4.c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         } comandos_bloco '}' {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
         | TOKEN_CHAR ID '(' parametros ')' '{' {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao($2, T_CHAR, escopo_atual);
            
            sprintf(buf, "\nchar %s(%s) {\n", $2, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nchar %s(%s) {\n", $2, $4.c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         } comandos_bloco '}' {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
         | TOKEN_BOOL ID '(' parametros ')' '{' {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao($2, T_BOOL, escopo_atual);
            
            sprintf(buf, "\nint %s(%s) {\n", $2, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nint %s(%s) {\n", $2, $4.c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         } comandos_bloco '}' {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
       | TOKEN_STRING ID '(' parametros ')' '{' {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao($2, T_STRING, escopo_atual);
            
            sprintf(buf, "\nchar* %s(%s) {\n", $2, $4.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nchar* %s(%s) {\n", $2, $4.c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         } comandos_bloco '}' {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
       ;

/* --- REGRAS DE PARÂMETROS (Na Declaração) --- */
parametros : parametro { $$ = $1; }
           | parametros ',' parametro {
                $$.temp = (char*) malloc(strlen($1.temp) + strlen($3.temp) + 5);
                sprintf($$.temp, "%s, %s", $1.temp, $3.temp);

                $$.c_expr = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 5);
                sprintf($$.c_expr, "%s, %s", $1.c_expr, $3.c_expr);
           }
           | /* vazio */ { 
                $$.temp = strdup(""); 
                $$.c_expr = strdup(""); 
           }
           ;

parametro : TOKEN_INT ID {
                Simbolo* s = inserir($2, T_INT, escopo_atual + 1);
                $$.temp = (char*) malloc(50);
                sprintf($$.temp, "int %s", s->temp); 
                $$.c_expr = (char*) malloc(50);
                sprintf($$.c_expr, "int %s", s->nome);
            }
          | TOKEN_FLOAT ID {
                Simbolo* s = inserir($2, T_FLOAT, escopo_atual + 1);
                $$.temp = (char*) malloc(50);
                sprintf($$.temp, "float %s", s->temp); 
                $$.c_expr = (char*) malloc(50);
                sprintf($$.c_expr, "float %s", s->nome);
            }
          | TOKEN_STRING ID {
                Simbolo* s = inserir($2, T_STRING, escopo_atual + 1);
                $$.temp = (char*) malloc(50);
                // Strings em C são passadas como ponteiros (char*)
                sprintf($$.temp, "char* %s", s->temp); 
                $$.c_expr = (char*) malloc(50);
                sprintf($$.c_expr, "char* %s", s->nome);
            }
          | TOKEN_CHAR ID {
                Simbolo* s = inserir($2, T_CHAR, escopo_atual + 1);
                $$.temp = (char*) malloc(50);
                sprintf($$.temp, "char %s", s->temp); 
                $$.c_expr = (char*) malloc(50);
                sprintf($$.c_expr, "char %s", s->nome);
            }
          | TOKEN_BOOL ID {
                Simbolo* s = inserir($2, T_BOOL, escopo_atual + 1);
                $$.temp = (char*) malloc(50);
                // Booleano na sua linguagem vira int no C gerado
                sprintf($$.temp, "int %s", s->temp); 
                $$.c_expr = (char*) malloc(50);
                sprintf($$.c_expr, "int %s", s->nome);
            }
          ;

/* --- REGRAS DE ARGUMENTOS (Na Chamada) --- */
argumentos : lista_args { $$ = $1; }
           | /* vazio */ { 
                $$.temp = strdup(""); 
                $$.c_expr = strdup(""); 
           }
           ;

lista_args : expressao {
                $$.temp = strdup($1.temp);
                $$.c_expr = strdup($1.c_expr);
           }
           | lista_args ',' expressao {
                $$.temp = (char*) malloc(strlen($1.temp) + strlen($3.temp) + 5);
                sprintf($$.temp, "%s, %s", $1.temp, $3.temp);

                $$.c_expr = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 5);
                sprintf($$.c_expr, "%s, %s", $1.c_expr, $3.c_expr);
           }
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
    if (!s) { yyerror("Erro: Variavel nao declarada no incremento do for."); } 
    else {
        $$.temp = (char*) malloc(256);
        sprintf($$.temp, "%s = %s;\n", s->temp, $3.temp);
        $$.c_expr = (char*) malloc(256);
        sprintf($$.c_expr, "%s = %s", s->nome, $3.c_expr);
    }
}
| ID INC {
    Simbolo *s = buscar($1);
    if (!s) { yyerror("Erro: Variavel nao declarada no incremento do for."); } 
    else {
        $$.temp = (char*) malloc(256);
        sprintf($$.temp, "%s = %s + 1;\n", s->temp, s->temp);
        $$.c_expr = (char*) malloc(256);
        sprintf($$.c_expr, "%s++", s->nome);
    }
}
| ID DEC {
    Simbolo *s = buscar($1);
    if (!s) { yyerror("Erro: Variavel nao declarada no decremento do for."); } 
    else {
        $$.temp = (char*) malloc(256);
        sprintf($$.temp, "%s = %s - 1;\n", s->temp, s->temp);
        $$.c_expr = (char*) malloc(256);
        sprintf($$.c_expr, "%s--", s->nome);
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

                    // 2. Gera o código correspondente direto na variável 'instrucoes'
                    if (s->tipo == T_STRING) {
                        int id_temp;
                        sscanf(s->temp, "T%d", &id_temp);
                        eh_dinamico[id_temp] = 1; // Marca o T-temp como dinâmico para gerar char*
                        
                        sprintf(buf, "%s = ler_string_dinamica();\n", s->temp);
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
            char* l_inc = novo_label();
            
            // [REMOVIDO] char* l_incremento = novo_label(); 
            
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            $<valor_str>$ = l_inicio;
            
            // ALTERAÇÃO: Como não há mais l_incremento, o 'continue' 
            // terá que pular para o início do laço.
            strcpy(pilha_inicio[topo_laco], l_inc);
            
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
            sprintf(buf, "%s) {\n", $9.c_expr);
            strcat(c_body, buf);
            
        } comando {
            // 4. Chegamos no final do laço!
            topo_laco--; 
            
            sprintf(buf, "%s:\n", pilha_inicio[topo_laco]);
            strcat(instrucoes, buf);
            
            // Puxa o TAC do incremento (Substitui o antigo inc_3ac global)
            strcat(instrucoes, $9.temp);
            
            // Pula de volta pro início
            sprintf(buf, "goto %s;\n", $<valor_str>5);
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM
            sprintf(buf, "%s:\n", $<valor_str>8);
            strcat(instrucoes, buf);
            strcat(instrucoes, "\n");
            
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
        | TOKEN_BREAK_ALL ';' {

            if (topo_laco > 0) {

                // break_all: pula direto pro fim do laco/switch MAIS EXTERNO da pilha
                sprintf(buf, "goto %s;\n", pilha_fim[0]);
                strcat(instrucoes, buf);

            } else {

                yyerror("Erro Semantico: 'break_all' usado fora de um laco.");

            }

            strcat(c_body, "/* break_all */\n");
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
        | ID PLUS_ASSIGN expressao ';' {
                Simbolo *s = buscar($1);
                if (!s) yyerror("Erro: Variavel nao declarada.");
                else if (s->tipo != $3.tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
                else {
                    if (s->tipo == T_STRING) {
                        // Para strings, += significa concatenar no próprio destino usando strcat
                        int id_temp;
                        sscanf(s->temp, "T%d", &id_temp);
                        tamanhos_t[id_temp] += $3.tam_str; // Atualiza o limite de tamanho

                        // TAC
                        sprintf(buf, "strcat(%s, %s);\n", s->temp, $3.temp);
                        strcat(instrucoes, buf);
                        
                        // C Transpilado
                        sprintf(buf, "strcat(%s, %s);\n", s->nome, $3.c_expr);
                        strcat(c_body, buf);
                    } else {
                        // Lógica original para números (Int e Float)
                        char* t_op = novo_temp(s->tipo);
                        sprintf(buf, "%s = %s + %s;\n", t_op, s->temp, $3.temp);
                        strcat(instrucoes, buf);
                        
                        sprintf(buf, "%s = %s;\n", s->temp, t_op);
                        strcat(instrucoes, buf);
                        
                        sprintf(buf, "%s += %s;\n", s->nome, $3.c_expr);
                        strcat(c_body, buf);
                    }
                }
            }
            | ID MINUS_ASSIGN expressao ';' {
                Simbolo *s = buscar($1);
                if (!s) yyerror("Erro: Variavel nao declarada.");
                else if (s->tipo != $3.tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
                else {
                    char* t_op = novo_temp(s->tipo);
                    sprintf(buf, "%s = %s - %s;\n", t_op, s->temp, $3.temp);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s = %s;\n", s->temp, t_op);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s -= %s;\n", s->nome, $3.c_expr);
                    strcat(c_body, buf);
                }
            }
            | ID MULT_ASSIGN expressao ';' {
            Simbolo *s = buscar($1);
            if (!s) yyerror("Erro: Variavel nao declarada.");
            else if (s->tipo != $3.tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
            else {
                char* t_op = novo_temp(s->tipo);
                sprintf(buf, "%s = %s * %s;\n", t_op, s->temp, $3.temp);
                strcat(instrucoes, buf);
                sprintf(buf, "%s = %s;\n", s->temp, t_op);
                strcat(instrucoes, buf);
                sprintf(buf, "%s *= %s;\n", s->nome, $3.c_expr);
                strcat(c_body, buf);
            }
        }
        | ID DIV_ASSIGN expressao ';' {
            Simbolo *s = buscar($1);
            if (!s) yyerror("Erro: Variavel nao declarada.");
            else if (s->tipo != $3.tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
            else {
                char* t_op = novo_temp(s->tipo);
                sprintf(buf, "%s = %s / %s;\n", t_op, s->temp, $3.temp);
                strcat(instrucoes, buf);
                sprintf(buf, "%s = %s;\n", s->temp, t_op);
                strcat(instrucoes, buf);
                sprintf(buf, "%s /= %s;\n", s->nome, $3.c_expr);
                strcat(c_body, buf);
            }
        }
        | ID INC ';' {
            Simbolo *s = buscar($1);
            if (!s) yyerror("Erro: Variavel nao declarada para incremento.");
            else {
                // Atualiza o valor no TAC (x = x + 1)
                sprintf(buf, "%s = %s + 1;\n", s->temp, s->temp);
                strcat(instrucoes, buf);
                
                // Transpila para C
                sprintf(buf, "%s++;\n", s->nome);
                strcat(c_body, buf);
            }
        }
        | ID DEC ';' {
            Simbolo *s = buscar($1);
            if (!s) yyerror("Erro: Variavel nao declarada para decremento.");
            else {
                // Atualiza o valor no TAC (x = x - 1)
                sprintf(buf, "%s = %s - 1;\n", s->temp, s->temp);
                strcat(instrucoes, buf);
                
                // Transpila para C
                sprintf(buf, "%s--;\n", s->nome);
                strcat(c_body, buf);
            }
        }
        | ID '[' expressao ']' ASSIGN expressao ';' {
            Simbolo *s = buscar($1);
            if (!s) yyerror("Erro: Matriz nao declarada.");
            else if (s->dimensoes != 1) yyerror("Erro: Variavel nao e uma matriz.");
            else if ($3.tipo_val != T_INT) yyerror("Erro Semantico: Indice da matriz deve ser inteiro.");
            else {
                char* valor_final  = $6.temp;
                char* c_expr_final = $6.c_expr;
                int sem_erro = 1;

                if (s->tipo == T_FLOAT && $6.tipo_val == T_INT) {
                    valor_final = gerar_cast($6.temp, T_FLOAT);
                    char *tmp = (char*) malloc(256);
                    sprintf(tmp, "(float)(%s)", c_expr_final);
                    c_expr_final = tmp;
                } else if (s->tipo == T_INT && $6.tipo_val == T_FLOAT) {
                    valor_final = gerar_cast($6.temp, T_INT);
                    char *tmp = (char*) malloc(256);
                    sprintf(tmp, "(int)(%s)", c_expr_final);
                    c_expr_final = tmp;
                } else if (s->tipo != $6.tipo_val) {
                    yyerror("Erro Semantico: Atribuicao com tipo incompativel na matriz.");
                    sem_erro = 0;
                }

                if (sem_erro) {
                    sprintf(buf, "%s[%s] = %s;\n", s->temp, $3.temp, valor_final);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s[%s] = %s;\n", s->temp, $3.c_expr, c_expr_final);
                    strcat(c_body, buf);
                }
            }
        }
        | ID '[' expressao ']' '[' expressao ']' ASSIGN expressao ';' {
            Simbolo *s = buscar($1);
            if (!s) yyerror("Erro: Matriz nao declarada.");
            else if (s->dimensoes != 2) yyerror("Erro: Variavel nao e uma matriz 2D.");
            else if ($3.tipo_val != T_INT || $6.tipo_val != T_INT) yyerror("Erro Semantico: Indices da matriz devem ser inteiros.");
            else {
                char* valor_final  = $9.temp;
                char* c_expr_final = $9.c_expr;
                int sem_erro = 1;

                // Checagens de Cast similares as do 1D...
                if (s->tipo == T_FLOAT && $9.tipo_val == T_INT) {
                    valor_final = gerar_cast($9.temp, T_FLOAT);
                    char *tmp = (char*) malloc(256);
                    sprintf(tmp, "(float)(%s)", c_expr_final);
                    c_expr_final = tmp;
                } else if (s->tipo != $9.tipo_val) {
                    yyerror("Erro Semantico: Atribuicao com tipo incompativel na matriz 2D.");
                    sem_erro = 0;
                }

                if (sem_erro) {
                    sprintf(buf, "%s[%s][%s] = %s;\n", s->temp, $3.temp, $6.temp, valor_final);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s[%s][%s] = %s;\n", s->temp, $3.c_expr, $6.c_expr, c_expr_final);
                    strcat(c_body, buf);
                }
            }
        }
        | TOKEN_RETURN ';' {
            strcat(instrucoes, "return;\n");
            strcat(c_body, "return;\n");
        }
        | TOKEN_RETURN expressao ';' {
            sprintf(buf, "return %s;\n", $2.temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "return %s;\n", $2.c_expr);
            strcat(c_body, buf);
        }
        | ID '(' argumentos ')' ';' {
            Simbolo *s = buscar($1);
            if (!s) { yyerror("Erro: Funcao nao declarada."); } 
            else if (s->cat != C_FUNC) { yyerror("Erro: Nao e funcao."); } 
            else {
                
                // Manda o $3.temp pros argumentos do TAC
                sprintf(buf, "%s(%s);\n", s->temp, $3.temp);
                strcat(instrucoes, buf);
                
                sprintf(buf, "%s(%s);\n", s->nome, $3.c_expr);
                strcat(c_body, buf);
            }
        }

declaracao : TOKEN_INT ID {
                // DECLARAÇÃO SIMPLES (Já existia)
                inserir($2, T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_INT ID ASSIGN expressao {
                // DECLARAÇÃO COM INICIALIZAÇÃO (Novo)
                inserir($2, T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", $2);
                strcat(c_decl, buf);

                Simbolo *s = buscar($2);
                char* valor_final = $4.temp;
                char* c_expr_final = $4.c_expr;

                // Verificação de tipo (Cast de float para int)
                if ($4.tipo_val == T_FLOAT) {
                    valor_final = gerar_cast($4.temp, T_INT);
                    char *tmp = (char*) malloc(256);
                    strcpy(tmp, "(int)(");
                    strcat(tmp, c_expr_final);
                    strcat(tmp, ")");
                    c_expr_final = tmp;
                } else if ($4.tipo_val != T_INT) {
                    yyerror("Erro Semantico: Inicializacao de 'int' com tipo incompativel.");
                }

                // Gera o TAC e o código C da atribuição
                sprintf(buf, "%s = %s;\n", s->temp, valor_final);
                strcat(instrucoes, buf);
                
                sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
                strcat(c_body, buf);
             }
             |
           TOKEN_INT ID '[' NUM_INT ']' ASSIGN '{' {
                int tamanho = atoi($4);
                inserir_array($2, T_INT, escopo_atual, tamanho);
                
                // Configura o estado para a regra lista_valores usar
                simbolo_array_atual = buscar($2);
                tam_array_atual = tamanho;
                idx_array_atual = 0;
           } lista_valores '}' {
                // Limpa o estado após terminar a inicialização
                simbolo_array_atual = NULL; 
           }
           | TOKEN_INT ID '[' NUM_INT ']' {
                int tamanho = atoi($4);
                inserir_array($2, T_INT, escopo_atual, tamanho);
                sprintf(buf, "int %s[%d];\n", $2, tamanho);
                strcat(c_decl, buf);
             }
           | TOKEN_FLOAT ID '[' NUM_INT ']' {
                int tamanho = atoi($4);
                inserir_array($2, T_FLOAT, escopo_atual, tamanho);
                sprintf(buf, "float %s[%d];\n", $2, tamanho);
                strcat(c_decl, buf);
             }
           | TOKEN_CHAR ID '[' NUM_INT ']' {
                int tamanho = atoi($4);
                inserir_array($2, T_CHAR, escopo_atual, tamanho);
                sprintf(buf, "char %s[%d];\n", $2, tamanho);
                strcat(c_decl, buf);
             }
           | TOKEN_BOOL ID '[' NUM_INT ']' {
                int tamanho = atoi($4);
                inserir_array($2, T_BOOL, escopo_atual, tamanho);
                // 'bool' é tratado como 'int' no código transpilado
                sprintf(buf, "int %s[%d];\n", $2, tamanho);
                strcat(c_decl, buf);
             }
           |
           TOKEN_FLOAT ID {
                // DECLARAÇÃO SIMPLES
                inserir($2, T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_FLOAT ID ASSIGN expressao {
                // DECLARAÇÃO COM INICIALIZAÇÃO
                inserir($2, T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", $2);
                strcat(c_decl, buf);

                Simbolo *s = buscar($2);
                char* valor_final = $4.temp;
                char* c_expr_final = $4.c_expr;

                // Verificação de tipo (Cast de int para float)
                if ($4.tipo_val == T_INT) {
                    valor_final = gerar_cast($4.temp, T_FLOAT);
                    char *tmp = (char*) malloc(256);
                    strcpy(tmp, "(float)(");
                    strcat(tmp, c_expr_final);
                    strcat(tmp, ")");
                    c_expr_final = tmp;
                } else if ($4.tipo_val != T_FLOAT) {
                    yyerror("Erro Semantico: Inicializacao de 'float' com tipo incompativel.");
                }

                sprintf(buf, "%s = %s;\n", s->temp, valor_final);
                strcat(instrucoes, buf);
                
                sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
                strcat(c_body, buf);
             }
             |
           TOKEN_FLOAT ID '[' NUM_INT ']' ASSIGN '{' {
                int tamanho = atoi($4);
                inserir_array($2, T_FLOAT, escopo_atual, tamanho);
                
                simbolo_array_atual = buscar($2);
                tam_array_atual = tamanho;
                idx_array_atual = 0;
           } lista_valores '}' {
                simbolo_array_atual = NULL;
           }
             |
           TOKEN_CHAR ID {
                inserir($2, T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_CHAR ID ASSIGN expressao {
                inserir($2, T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", $2);
                strcat(c_decl, buf);

                Simbolo *s = buscar($2);
                if ($4.tipo_val != T_CHAR) {
                    yyerror("Erro Semantico: Inicializacao de 'char' com tipo incompativel.");
                } else {
                    // TAC
                    sprintf(buf, "%s = %s;\n", s->temp, $4.temp);
                    strcat(instrucoes, buf);
                    // C
                    sprintf(buf, "%s = %s;\n", s->nome, $4.c_expr);
                    strcat(c_body, buf);
                }
             }
           |
           TOKEN_BOOL ID {
                 inserir($2, T_BOOL, escopo_atual);
                 sprintf(buf, "int %s;\n", $2);
                 strcat(c_decl, buf);
             }
           | TOKEN_BOOL ID ASSIGN expressao {
                 inserir($2, T_BOOL, escopo_atual);
                 sprintf(buf, "int %s;\n", $2);
                 strcat(c_decl, buf);

                 Simbolo *s = buscar($2);
                 if ($4.tipo_val != T_BOOL) {
                     yyerror("Erro Semantico: Inicializacao de 'boolean' com tipo incompativel.");
                 } else {
                     // TAC
                     sprintf(buf, "%s = %s;\n", s->temp, $4.temp);
                     strcat(instrucoes, buf);
                     // C
                     sprintf(buf, "%s = %s;\n", s->nome, $4.c_expr);
                     strcat(c_body, buf);
                 }
             }
            |
           TOKEN_STRING ID {
                inserir($2, T_STRING, escopo_atual);
                sprintf(buf, "char %s[256];\n", $2);
                strcat(c_decl, buf);
             }
           | TOKEN_STRING ID ASSIGN expressao {
                inserir($2, T_STRING, escopo_atual);
                sprintf(buf, "char %s[256];\n", $2);
                strcat(c_decl, buf);

                Simbolo *s = buscar($2);
                if ($4.tipo_val != T_STRING) {
                    yyerror("Erro Semantico: Inicializacao de 'string' com tipo incompativel.");
                } else {
                    // Atualiza o tamanho no array de temporarios
                    int id_temp;
                    sscanf(s->temp, "T%d", &id_temp);
                    tamanhos_t[id_temp] = $4.tam_str;

                    // TAC usando strcpy
                    sprintf(buf, "strcpy(%s, %s);\n", s->temp, $4.temp);
                    strcat(instrucoes, buf);
                    
                    // C usando strcpy
                    sprintf(buf, "strcpy(%s, %s);\n", s->nome, $4.c_expr);
                    strcat(c_body, buf);
                }
             }
             | TOKEN_VAR ID ASSIGN expressao {
                // Declaração implícita com inferência de tipo: o tipo da variável
                // vem direto do tipo da expressão à direita, sem palavra-chave de tipo.
                Tipo tipo_inferido = $4.tipo_val;
                inserir($2, tipo_inferido, escopo_atual);
                Simbolo *s = buscar($2);

                if (tipo_inferido == T_STRING) {
                    sprintf(buf, "char %s[256];\n", $2);
                    strcat(c_decl, buf);

                    int id_temp;
                    sscanf(s->temp, "T%d", &id_temp);
                    tamanhos_t[id_temp] = $4.tam_str;

                    sprintf(buf, "strcpy(%s, %s);\n", s->temp, $4.temp);
                    strcat(instrucoes, buf);

                    sprintf(buf, "strcpy(%s, %s);\n", s->nome, $4.c_expr);
                    strcat(c_body, buf);
                } else {
                    char* tipo_c = (tipo_inferido == T_FLOAT) ? "float" :
                                   (tipo_inferido == T_CHAR)  ? "char"  :
                                   "int"; // T_INT e T_BOOL viram int em C

                    sprintf(buf, "%s %s;\n", tipo_c, $2);
                    strcat(c_decl, buf);

                    sprintf(buf, "%s = %s;\n", s->temp, $4.temp);
                    strcat(instrucoes, buf);

                    sprintf(buf, "%s = %s;\n", s->nome, $4.c_expr);
                    strcat(c_body, buf);
                }
             }
           | TOKEN_INT ID '[' NUM_INT ']' '[' NUM_INT ']' {
                int dim1 = atoi($4);
                int dim2 = atoi($7);
                inserir_array2d($2, T_INT, escopo_atual, dim1, dim2);
                sprintf(buf, "int %s[%d][%d];\n", $2, dim1, dim2);
                strcat(c_decl, buf);
             }
           | TOKEN_FLOAT ID '[' NUM_INT ']' '[' NUM_INT ']' {
                int dim1 = atoi($4);
                int dim2 = atoi($7);
                inserir_array2d($2, T_FLOAT, escopo_atual, dim1, dim2);
                sprintf(buf, "float %s[%d][%d];\n", $2, dim1, dim2);
                strcat(c_decl, buf);
             }
           | TOKEN_CHAR ID '[' NUM_INT ']' '[' NUM_INT ']' {
                int dim1 = atoi($4);
                int dim2 = atoi($7);
                inserir_array2d($2, T_CHAR, escopo_atual, dim1, dim2);
                sprintf(buf, "char %s[%d][%d];\n", $2, dim1, dim2);
                strcat(c_decl, buf);
             }
           | TOKEN_BOOL ID '[' NUM_INT ']' '[' NUM_INT ']' {
                int dim1 = atoi($4);
                int dim2 = atoi($7);
                inserir_array2d($2, T_BOOL, escopo_atual, dim1, dim2);
                // No seu código transpilado, 'bool' é tratado como 'int'
                sprintf(buf, "int %s[%d][%d];\n", $2, dim1, dim2);
                strcat(c_decl, buf);
             }
           | TOKEN_STRING ID '[' NUM_INT ']' '[' NUM_INT ']' {
                int dim1 = atoi($4);
                int dim2 = atoi($7);
                inserir_array2d($2, T_STRING, escopo_atual, dim1, dim2);
                // Uma "matriz de strings" em C transpilado precisa do tamanho da string no final
                sprintf(buf, "char %s[%d][%d][256];\n", $2, dim1, dim2);
                strcat(c_decl, buf);
             }
             | TOKEN_INT ID '[' NUM_INT ']' '[' NUM_INT ']' ASSIGN '{' {
                int dim1 = atoi($4);
                int dim2 = atoi($7);
                inserir_array2d($2, T_INT, escopo_atual, dim1, dim2);
                
                sprintf(buf, "int %s[%d][%d];\n", $2, dim1, dim2);
                strcat(c_decl, buf);

                // Configura os rastreadores antes de processar as chaves aninhadas
                simbolo_array_atual = buscar($2);
                tam_dim1_atual = dim1;
                tam_dim2_atual = dim2;
                idx_dim1_atual = 0;
                
             } lista_linhas '}' {
                 
                // Limpa o estado de rastreamento após terminar
                simbolo_array_atual = NULL;
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
            | ID '(' argumentos ')' {
                Simbolo *s = buscar($1);
                if (!s) { yyerror("Erro: Funcao nao declarada."); $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); } 
                else if (s->cat != C_FUNC) { yyerror("Erro: Nao e funcao."); $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); } 
                else if (s->tipo == T_VOID) { yyerror("Erro: Funcao VOID."); $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); } 
                else {
                    $$.tipo_val = s->tipo;
                    $$.temp = novo_temp(s->tipo);
                    
                    // Manda o $3.temp pros argumentos do TAC
                    sprintf(buf, "%s = %s(%s);\n", $$.temp, s->temp, $3.temp);
                    strcat(instrucoes, buf);
                    
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "%s(%s)", s->nome, $3.c_expr);
                    $$.c_expr = ce;
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
                    
                    char *ce = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
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
            | expressao '^' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) || $3.tipo_val != T_INT) {
                    yyerror("Erro Semantico: Exponenciacao exige base numerica (int/float) e expoente inteiro.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    Tipo tipo_resultado = $1.tipo_val; // resultado tem o mesmo tipo da base

                    char *t_result = novo_temp(tipo_resultado);
                    char *t_i = novo_temp(T_INT);
                    char *t_cmp = novo_temp(T_BOOL);
                    char *l_inicio = novo_label();
                    char *l_fim = novo_label();

                    // T_result = 1; T_i = 0;
                    sprintf(buf, "%s = 1;\n", t_result);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s = 0;\n", t_i);
                    strcat(instrucoes, buf);

                    // L_inicio:
                    sprintf(buf, "%s:\n", l_inicio);
                    strcat(instrucoes, buf);

                    // se T_i >= expoente, encerra o laco
                    sprintf(buf, "%s = %s >= %s;\n", t_cmp, t_i, $3.temp);
                    strcat(instrucoes, buf);
                    sprintf(buf, "if (%s) goto %s;\n", t_cmp, l_fim);
                    strcat(instrucoes, buf);

                    // T_result = T_result * base; T_i = T_i + 1; goto L_inicio;
                    sprintf(buf, "%s = %s * %s;\n", t_result, t_result, $1.temp);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s = %s + 1;\n", t_i, t_i);
                    strcat(instrucoes, buf);
                    sprintf(buf, "goto %s;\n", l_inicio);
                    strcat(instrucoes, buf);

                    // L_fim:
                    sprintf(buf, "%s:\n", l_fim);
                    strcat(instrucoes, buf);

                    $$.tipo_val = tipo_resultado;
                    $$.temp = t_result;
                    $$.c_expr = strdup(t_result);
                }
            }
          | expressao '*' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    // Só converte se os tipos forem DIFERENTES
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT);
                            $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT);
                            $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    sprintf(buf, "%s = %s * %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s * %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
            }
          | expressao '/' expressao {
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) ||
                    ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                    $$.temp = "ERRO"; $$.c_expr = strdup("ERRO"); $$.tipo_val = T_INT;
                } else {
                    char *ce1 = $1.c_expr, *ce3 = $3.c_expr;
                    
                    // Só converte se os tipos forem DIFERENTES
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) {
                            $1.temp = gerar_cast($1.temp, T_FLOAT);
                            $1.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            $3.temp = gerar_cast($3.temp, T_FLOAT);
                            $3.tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val);
                    
                    // TAC
                    sprintf(buf, "%s = %s / %s;\n", $$.temp, $1.temp, $3.temp);
                    strcat(instrucoes, buf);
                    
                    // Código C (Corrigido de '+' para '/')
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s / %s)", ce1, ce3);
                    $$.c_expr = ce;
                }
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
            /* --- LEITURA DE MATRIZ --- */
          | ID '[' expressao ']' {
                Simbolo *s = buscar($1);
                if (!s) {
                    yyerror("Erro: Matriz nao declarada.");
                    $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO");
                } else if (s->dimensoes != 1) {
                    yyerror("Erro: Variavel nao e um vetor de 1 dimensao.");
                    $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO");
                } else if ($3.tipo_val != T_INT) {
                    yyerror("Erro Semantico: Indice da matriz deve ser inteiro.");
                    $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO");
                } else {
                    $$.tipo_val = s->tipo;
                    $$.temp = novo_temp(s->tipo);
                    
                    // TAC: T_novo = vetor[T_indice]
                    sprintf(buf, "%s = %s[%s];\n", $$.temp, s->temp, $3.temp);
                    strcat(instrucoes, buf);
                    
                    // Codigo C
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "%s[%s]", s->temp, $3.c_expr);
                    $$.c_expr = ce;
                }
            }
            | ID '[' expressao ']' '[' expressao ']' {
                Simbolo *s = buscar($1);
                if (!s) {
                    yyerror("Erro: Matriz nao declarada.");
                    $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO");
                } else if (s->dimensoes != 2) {
                    yyerror("Erro: Variavel nao e uma matriz 2D.");
                    $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO");
                } else if ($3.tipo_val != T_INT || $6.tipo_val != T_INT) {
                    yyerror("Erro Semantico: Indices da matriz devem ser inteiros.");
                    $$.tipo_val = T_INT; $$.temp = "ERRO"; $$.c_expr = strdup("ERRO");
                } else {
                    $$.tipo_val = s->tipo;
                    $$.temp = novo_temp(s->tipo);
                    
                    // TAC: T_novo = matriz[T_ind1][T_ind2]
                    sprintf(buf, "%s = %s[%s][%s];\n", $$.temp, s->temp, $3.temp, $6.temp);
                    strcat(instrucoes, buf);
                    
                    // Codigo C
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "%s[%s][%s]", s->temp, $3.c_expr, $6.c_expr);
                    $$.c_expr = ce;
                }
            }
          ;

          lista_valores : expressao {
        if (simbolo_array_atual) {
            if (idx_array_atual < tam_array_atual) {
                // Checagem estrita de tipo (você pode adicionar casts aqui depois, se quiser)
                if (simbolo_array_atual->tipo != $1.tipo_val) {
                    yyerror("Erro Semantico: Tipo incompativel na inicializacao da matriz.");
                } else {
                    // TAC
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, $1.temp);
                    strcat(instrucoes, buf);
                    // C Transpilado
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->nome, idx_array_atual, $1.c_expr);
                    strcat(c_body, buf);
                    
                    idx_array_atual++;
                }
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz.");
            }
        }
    }
    | lista_valores ',' expressao {
        if (simbolo_array_atual) {
            if (idx_array_atual < tam_array_atual) {
                if (simbolo_array_atual->tipo != $3.tipo_val) {
                    yyerror("Erro Semantico: Tipo incompativel na inicializacao da matriz.");
                } else {
                    // TAC
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, $3.temp);
                    strcat(instrucoes, buf);
                    // C Transpilado
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->nome, idx_array_atual, $3.c_expr);
                    strcat(c_body, buf);
                    
                    idx_array_atual++;
                }
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz.");
            }
        }
    }
    lista_linhas : linha_valores
             | lista_linhas ',' linha_valores
             ;

linha_valores : '{' { 
        // Toda vez que abre uma chave de linha, zera o contador de colunas
        idx_dim2_atual = 0; 
    } lista_colunas '}' {
        // Ao fechar a chave da linha, pula para a próxima linha
        idx_dim1_atual++;
    }
    ;

lista_colunas : expressao {
        if (simbolo_array_atual) {
            if (idx_dim1_atual < tam_dim1_atual && idx_dim2_atual < tam_dim2_atual) {
                if (simbolo_array_atual->tipo != $1.tipo_val) {
                    yyerror("Erro Semantico: Tipo incompativel na inicializacao da matriz 2D.");
                } else {
                    // TAC
                    sprintf(buf, "%s[%d][%d] = %s;\n", simbolo_array_atual->temp, idx_dim1_atual, idx_dim2_atual, $1.temp);
                    strcat(instrucoes, buf);
                    // C Transpilado
                    sprintf(buf, "%s[%d][%d] = %s;\n", simbolo_array_atual->nome, idx_dim1_atual, idx_dim2_atual, $1.c_expr);
                    strcat(c_body, buf);
                    
                    idx_dim2_atual++; // Avança a coluna
                }
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz 2D.");
            }
        }
    }
    | lista_colunas ',' expressao {
        if (simbolo_array_atual) {
            if (idx_dim1_atual < tam_dim1_atual && idx_dim2_atual < tam_dim2_atual) {
                if (simbolo_array_atual->tipo != $3.tipo_val) {
                    yyerror("Erro Semantico: Tipo incompativel na inicializacao da matriz 2D.");
                } else {
                    // TAC
                    sprintf(buf, "%s[%d][%d] = %s;\n", simbolo_array_atual->temp, idx_dim1_atual, idx_dim2_atual, $3.temp);
                    strcat(instrucoes, buf);
                    // C Transpilado
                    sprintf(buf, "%s[%d][%d] = %s;\n", simbolo_array_atual->nome, idx_dim1_atual, idx_dim2_atual, $3.c_expr);
                    strcat(c_body, buf);
                    
                    idx_dim2_atual++; // Avança a coluna
                }
            } else {
                yyerror("Erro Semantico: Excesso de elementos na matriz 2D.");
            }
        }
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
    printf("#include <stdbool.h>\n");
    printf("#include \"io_dinamico.h\"\n\n");
    
    // Globais e Funções SEMPRE antes do main
    printf("%s", declaracoes);
    printf("%s\n", instrucoes_funcoes);

    printf("int main()\n{\n");
    printf("%s", instrucoes_globais);
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
    fprintf(arquivo_c, "#include <stdbool.h>\n");
    fprintf(arquivo_c, "#include \"io_dinamico.h\"\n\n");

    // Globais e Funções SEMPRE antes do main no arquivo C também
    fprintf(arquivo_c, "%s", declaracoes);
    fprintf(arquivo_c, "%s\n", instrucoes_funcoes);
    
    fprintf(arquivo_c, "int main()\n{\n");
    fprintf(arquivo_c, "%s", instrucoes_globais);
    fprintf(arquivo_c, "%s", instrucoes);
    fprintf(arquivo_c, "    return 0;\n}\n");

    fclose(arquivo_c);

    int status_gcc = system("gcc saida.c -o programa.exe");
    if (status_gcc != 0) {
        printf("Erro no compilador\n");
    }

    return 0;
}