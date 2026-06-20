#ifndef IO_DINAMICO_H
#define IO_DINAMICO_H

#include <stdio.h>
#include <stdlib.h>

char* ler_string_dinamica() {
    int capacidade = 16;
    int tamanho = 0;
    char* str = (char*)malloc(capacidade * sizeof(char));
    int c;
    while ((c = getchar()) != EOF && (c == ' ' || c == '\n' || c == '\t' || c == '\r'));
    if (c != EOF) {
        str[tamanho++] = c;
        while ((c = getchar()) != EOF && c != ' ' && c != '\n' && c != '\t' && c != '\r') {
            str[tamanho++] = c;
            if (tamanho == capacidade) {
                capacidade *= 2;
                str = (char*)realloc(str, capacidade * sizeof(char));
            }
        }
        if (c != EOF) ungetc(c, stdin);
    }
    str[tamanho] = '\0';
    return str;
}

#endif