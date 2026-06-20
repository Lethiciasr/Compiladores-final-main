#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io_dinamico.h"

int T1;
float T2;
float T3;
int T4;
int T5;
char T6[2];
char T7[2];
char T8[9];
char T9[9];

int main()
{
T1 = 20;
T2 = 1500.00;
T3 = T2;
T4 = true;
T5 = T4;
strcpy(T6, "a");
strcpy(T7, T6);
strcpy(T8, "lethicia");
strcpy(T9, T8);
printf("%s\n", T9);
printf("%d\n", T1);
    return 0;
}
