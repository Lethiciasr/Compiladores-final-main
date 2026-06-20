#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io_dinamico.h"

int T1[3][3];
int T2;
int T3;
int T4;
int T5;
int T6;
int T7;
int T8;
int T9;
int T10;
int T11;

int main()
{
T4 = 1;
T2 = 0;

L1:
T5 = T2 < 3;
T6 = !T5;
if (T6) goto L3;
T3 = 0;

L4:
T7 = T3 < 3;
T8 = !T7;
if (T8) goto L6;
T1[T2][T3] = T4;
T4 = T4 + 1;
L5:
T3 = T3 + 1;
goto L4;
L6:

L2:
T2 = T2 + 1;
goto L1;
L3:

T9 = T1[0][0];
printf("%d\n", T9);
T10 = T1[1][1];
printf("%d\n", T10);
T11 = T1[2][2];
printf("%d\n", T11);
    return 0;
}
