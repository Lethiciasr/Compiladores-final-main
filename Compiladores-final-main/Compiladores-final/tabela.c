#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo *tabela_global = NULL;
int t_cont = 1; 
int l_cont = 1;
int tipos_t[1000];
int tamanhos_t[1000];


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
    
    t_cont++;
    return t;
}

// Anota o tamanho cirurgicamente calculado
char* novo_temp_str(int tamanho_exato) {
    char* t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    
    tipos_t[t_cont] = T_STRING;
    tamanhos_t[t_cont] = tamanho_exato; 
    
    t_cont++;
    return t;
}

// NOVA FUNÇÃO: Imprime todas as variáveis de uma vez só!
void gerar_declaracoes_finais() {
    for (int i = 1; i < t_cont; i++) {
        char linha[100];
        switch(tipos_t[i]) {
            case T_INT:   sprintf(linha, "int T%d;\n", i); break;
            case T_FLOAT: sprintf(linha, "float T%d;\n", i); break;
            case T_CHAR:  sprintf(linha, "char T%d;\n", i); break;
            case T_BOOL:  sprintf(linha, "int T%d;\n", i); break;
            case T_STRING: sprintf(linha, "char T%d[%d];\n", i, tamanhos_t[i]); break;
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

Simbolo* inserir(char *nome, Tipo tipo, int nivel) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    char *nome_t = novo_temp(tipo); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    novo->tipo = tipo;
    novo->nivel = nivel;
    novo->proximo = tabela_global;
    tabela_global = novo;
    return novo;
}

Simbolo* buscar(char *nome) {
    Simbolo *atual = tabela_global;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
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