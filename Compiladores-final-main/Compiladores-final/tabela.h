#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL, T_STRING, T_VOID } Tipo;

typedef enum { C_VAR, C_FUNC } Categoria;

// Estrutura do nó da tabela de símbolos (lista encadeada)
typedef struct Simbolo {
    char nome[50];
    char temp[50]; //codigo intermediario
    Tipo tipo;
    Categoria cat;
    int nivel;
    int dimensoes;     
    int tamanho_dim1;  
    int tamanho_dim2;
    struct Simbolo *proximo;
} Simbolo;

// Funções de gerenciamento da tabela e variáveis temporárias
char* novo_temp(Tipo tipo); // gerar um novo nome de variavel temporaria
Simbolo* inserir(char *nome, Tipo tipo, int nivel); //add uma nova variavel na tabela quando declarada
Simbolo* inserir_array(char *nome, Tipo tipo, int nivel, int tamanho);
Simbolo* inserir_array2d(char *nome, Tipo tipo, int nivel, int dim1, int dim2);
char* novo_temp_array2d(Tipo tipo, int dim1, int dim2);
Simbolo* inserir_funcao(char *nome, Tipo tipo, int nivel);
Simbolo* buscar(char *nome); // vê se a variavel ja foi declarada
Simbolo* buscar_no_escopo(char *nome, int nivel);
void remover_simbolos_do_nivel(int nivel);

// Nova função auxiliar para conversão de tipos
char* gerar_cast(char* temp_origem, Tipo tipo_destino);

// Buffers para armazenar o código intermediário gerado
extern char declaracoes[5000];
extern char instrucoes[5000];
extern char c_code_decl[5000];
extern char c_code_body[5000];

extern int l_cont;
char* novo_label();
char* novo_temp_str(int tamanho_exato);
char* novo_temp_array(Tipo tipo, int tamanho);

extern int tamanhos_t[1000]; 
extern int eh_dinamico[1000];
extern int dimensoes_t[1000]; 
extern int tamanhos_t2[1000];
void gerar_declaracoes_finais();

#endif
