#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io_dinamico.h"

int T1;
int T2;
int T3;
int T4;
int T5;
int T6;
int T7;

int main()
{
T1 = 2;
T2 = T1 == 1;
T3 = !T2;
if (T3) goto L2;
printf("%d\n", 100);
goto L1;
goto L1;
L2:
T4 = T1 == 2;
T5 = !T4;
if (T5) goto L3;
printf("%d\n", 200);
goto L1;
goto L1;
L3:
T6 = T1 == 3;
T7 = !T6;
if (T7) goto L4;
printf("%d\n", 300);
goto L1;
goto L1;
L4:
printf("%d\n", 400);
L1:
    return 0;
}
