#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
int T1[5];
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
int T12;
int T13;
int T14;

T3 = 0;
T4 = 64;
T2 = 0;

L1:
T5 = T2 < 5;
T6 = !T5;
if (T6) goto L3;
T7 = T2 * T4;
T1[T2] = T7;
L2:
T2 = T2 + 1;
goto L1;
L3:

T2 = 0;

L4:
T8 = T2 < 5;
T9 = !T8;
if (T9) goto L6;
T10 = T1[T2];
printf("%d\n", T10);
T11 = T1[T2];
T12 = T3 + T11;
T3 = T12;
L5:
T2 = T2 + 1;
goto L4;
L6:

T13 = T1[3];
T14 = T13;
printf("%d\n", T14);
printf("%d\n", T3);
    return 0;
}
