#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char T1[27];
int T2;
int T3;
int T4;
int T5;
int T6;
char T7[16];
void imprimir_alerta() {
strcpy(T1, "Atencao: Calculo iniciado!");
printf("%s\n", T1);
}
int calcular_area(int T2, int T3) {
T4 = T2 * T3;
return T4;
}

int main()
{
imprimir_alerta();
T5 = calcular_area(5, 4);
T6 = T5;
strcpy(T7, "Area calculada:");
printf("%s\n", T7);
printf("%d\n", T6);
    return 0;
}
