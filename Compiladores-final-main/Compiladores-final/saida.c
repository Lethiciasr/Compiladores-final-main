#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io_dinamico.h"

int T1;
float T2;
float T3;
char T4[4];
char T5[4];
int T6;
int T7;

int main()
{
T1 = 5;
T2 = 3.14;
T3 = T2;
strcpy(T4, "Ana");
strcpy(T5, T4);
printf("%d\n", T1);
printf("%f\n", T3);
printf("%s\n", T5);
T6 = T1 + 10;
T7 = T6;
printf("%d\n", T7);
    return 0;
}
