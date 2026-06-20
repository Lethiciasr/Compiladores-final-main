#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo *tabela_global = NULL;
int t_cont = 1; 
int l_cont = 1;
int tipos_t[1000];
int tamanhos_t[1000];
int eh_dinamico[1000];
int dimensoes_t[1000]; 
int tamanhos_t2[1000]; 

char* novo_label() {
    char *l = (char*) malloc(10);
    sprintf(l, "L%d", l_cont++);
    return l;
}

char declaracoes[5000] = "";
char instrucoes[5000] = "";
char c_code_decl[5000] = "";   
char c_code_body[5000] = "";   

// Silenciamos o strcat! Agora ele só anota o tipo e o tamanho base.
char* novo_temp(Tipo tipo) {
    char *t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    
    tipos_t[t_cont] = tipo;
    // T_STRING ganha 256 provisório. Outros ganham 0.
    tamanhos_t[t_cont] = (tipo == T_STRING) ? 256 : 0; 
    dimensoes_t[t_cont] = 0;
    
    t_cont++;
    return t;
}

// Anota o tamanho cirurgicamente calculado
char* novo_temp_str(int tamanho_exato) {
    char* t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    
    tipos_t[t_cont] = T_STRING;
    tamanhos_t[t_cont] = tamanho_exato; 
    dimensoes_t[t_cont] = 0;
    
    t_cont++;
    return t;
}

char* novo_temp_array(Tipo tipo, int tamanho) {
    char* t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    tipos_t[t_cont] = tipo;
    dimensoes_t[t_cont] = 1;
    tamanhos_t[t_cont] = tamanho;
    dimensoes_t[t_cont] = 1;
    t_cont++;
    return t;
}

char* novo_temp_array2d(Tipo tipo, int dim1, int dim2) {
    char* t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    tipos_t[t_cont] = tipo;
    dimensoes_t[t_cont] = 2;
    tamanhos_t[t_cont] = dim1;
    tamanhos_t2[t_cont] = dim2;
    dimensoes_t[t_cont] = 2;
    t_cont++;
    return t;
}

void gerar_declaracoes_finais() {
    for (int i = 1; i < t_cont; i++) {
        char linha[100];

        // String lida via read(): vira ponteiro, sem tamanho fixo
        if (tipos_t[i] == T_STRING && eh_dinamico[i]) {
            sprintf(linha, "char* T%d = NULL;\n", i);
        }
        // Matriz 2D
        else if (dimensoes_t[i] == 2) {
            switch(tipos_t[i]) {
                case T_INT:   sprintf(linha, "int T%d[%d][%d];\n", i, tamanhos_t[i], tamanhos_t2[i]); break;
                case T_FLOAT: sprintf(linha, "float T%d[%d][%d];\n", i, tamanhos_t[i], tamanhos_t2[i]); break;
                case T_CHAR:  sprintf(linha, "char T%d[%d][%d];\n", i, tamanhos_t[i], tamanhos_t2[i]); break;
                case T_BOOL:  sprintf(linha, "int T%d[%d][%d];\n", i, tamanhos_t[i], tamanhos_t2[i]); break;
                case T_STRING: sprintf(linha, "char T%d[%d][%d][256];\n", i, tamanhos_t[i], tamanhos_t2[i]); break;
            }
        }
        // Vetor 1D
        else if (dimensoes_t[i] == 1 && tipos_t[i] != T_STRING) {
            switch(tipos_t[i]) {
                case T_INT:   sprintf(linha, "int T%d[%d];\n", i, tamanhos_t[i]); break;
                case T_FLOAT: sprintf(linha, "float T%d[%d];\n", i, tamanhos_t[i]); break;
                case T_CHAR:  sprintf(linha, "char T%d[%d];\n", i, tamanhos_t[i]); break;
                case T_BOOL:  sprintf(linha, "int T%d[%d];\n", i, tamanhos_t[i]); break;
            }
        } 
        // Variável comum ou string
        else {
            switch(tipos_t[i]) {
                case T_INT:   sprintf(linha, "int T%d;\n", i); break;
                case T_FLOAT: sprintf(linha, "float T%d;\n", i); break;
                case T_CHAR:  sprintf(linha, "char T%d;\n", i); break;
                case T_BOOL:  sprintf(linha, "int T%d;\n", i); break;
                case T_STRING: sprintf(linha, "char T%d[%d];\n", i, tamanhos_t[i]); break;
            }
        }
        strcat(declaracoes, linha); 
        strcat(c_code_decl, linha); 
    }
}

char* gerar_cast(char* temp_origem, Tipo tipo_destino) {
    char* t_destino = novo_temp(tipo_destino);
    char buf[100];
    const char* label_tipo = (tipo_destino == T_FLOAT) ? "float" : "int";

    sprintf(buf, "%s = (%s) %s;\n", t_destino, label_tipo, temp_origem);
    strcat(instrucoes, buf);
    return t_destino;
}

Simbolo* buscar_no_nivel(char *nome, int nivel) {
    Simbolo *atual = tabela_global;

    while (atual != NULL) {

        if (strcmp(atual->nome, nome) == 0 &&
            atual->nivel == nivel) {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

Simbolo* inserir(char *nome, Tipo tipo, int nivel) {
    if (buscar_no_nivel(nome, nivel) != NULL) {
        fprintf(stderr,
            "Erro Semantico: Variavel '%s' ja declarada neste escopo.\n",
            nome);
        exit(1);
    }
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    char *nome_t = novo_temp(tipo); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    novo->tipo = tipo;
    novo->cat = C_VAR;
    novo->nivel = nivel;
    novo->proximo = tabela_global;
    novo->dimensoes = 0;
    novo->tamanho_dim1 = 0;
    novo->tamanho_dim2 = 0;
    tabela_global = novo;
    return novo;
}

Simbolo* inserir_array(char *nome, Tipo tipo, int nivel, int tamanho) {
    if (buscar_no_nivel(nome, nivel) != NULL) {
        printf("Erro Semantico: Variavel '%s' ja declarada neste escopo.\n", nome);
        return NULL;
    }

    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);

    char *nome_t = novo_temp_array(tipo, tamanho); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    
    novo->tipo = tipo;
    novo->cat = C_VAR;
    novo->nivel = nivel;
    novo->proximo = tabela_global;
    novo->dimensoes = 1;
    novo->tamanho_dim1 = tamanho;
    novo->tamanho_dim2 = 0;
    tabela_global = novo;
    return novo;
}

Simbolo* inserir_funcao(char *nome, Tipo tipo, int nivel) { 
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    
    // Funções geralmente usam o próprio nome como label no TAC/Assembly
    strcpy(novo->temp, nome); 
    
    novo->tipo = tipo;
    novo->cat = C_FUNC;
    novo->nivel = nivel;
    novo->dimensoes = 0;
    novo->tamanho_dim1 = 0;
    novo->tamanho_dim2 = 0;
    novo->proximo = tabela_global;
    
    tabela_global = novo;
    return novo;
}

Simbolo* inserir_array2d(char *nome, Tipo tipo, int nivel, int dim1, int dim2) {
    if (buscar_no_nivel(nome, nivel) != NULL) {
        printf("Erro Semantico: Variavel '%s' ja declarada neste escopo.\n", nome);
        return NULL;
    }
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    char *nome_t = novo_temp_array2d(tipo, dim1, dim2); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    novo->tipo = tipo;
    novo->cat = C_VAR;
    novo->nivel = nivel;
    novo->dimensoes = 2;
    novo->tamanho_dim1 = dim1;
    novo->tamanho_dim2 = dim2;
    novo->proximo = tabela_global;
    tabela_global = novo;
    return novo;
}

Simbolo* buscar(char *nome) {
    Simbolo *atual = tabela_global;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0)
            return atual;

        atual = atual->proximo;
    }

    return NULL;
}

void remover_simbolos_do_nivel(int nivel) {
    while (tabela_global != NULL && tabela_global->nivel == nivel) {
        Simbolo *remover = tabela_global;
        tabela_global = tabela_global->proximo;
        free(remover); 
    }
}