#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int T1[4];
float T2[3];
float T3;
float T4;
float T5;
int T6;
int T7;
int T8;
float T9;
int T10;
int T11;
int T12;
int T13;
int T14;
int T15;

int main()
{
T1[0] = 10;
T1[1] = 20;
T1[2] = 30;
T1[3] = 40;
T3 = 7.5;
T2[0] = T3;
T4 = 8.0;
T2[1] = T4;
T5 = 9.5;
T2[2] = T5;
T7 = T1[1];
printf("%d\n", T7);
T1[1] = 99;
T8 = T1[1];
printf("%d\n", T8);
T9 = T2[2];
printf("%f\n", T9);
T6 = 0;

L1:
T10 = T6 < 4;
T11 = !T10;
if (T11) goto L3;
T12 = T1[T6];
T13 = T12 == 30;
T14 = !T13;
if (T14) goto L4;

goto L2;
L4:
T15 = T1[T6];
printf("%d\n", T15);
L2:
T6 = T6 + 1;
goto L1;
L3:

    return 0;
}
