#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io_dinamico.h"

int T1;
int T2;
int T3;
char T4[3];
int T5;
int T6;
char T7[5];
char T8[6];

int main()
{
T1 = 2;
T2 = T1 == 1;
T3 = !T2;
if (T3) goto L2;
strcpy(T4, "Um");
printf("%s\n", T4);
goto L1;
goto L1;
L2:
T5 = T1 == 2;
T6 = !T5;
if (T6) goto L3;
strcpy(T7, "Dois");
printf("%s\n", T7);
goto L1;
goto L1;
L3:
strcpy(T8, "Outro");
printf("%s\n", T8);
L1:
    return 0;
}
