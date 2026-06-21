#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int T1;
int T2;
int T3;
int T4;
int T5;

int main()
{
T1 = 2;
T2 = T1 == 1;
T3 = !T2;
if (T3) goto L2;
printf("%d\n", 111);
goto L1;
goto L1;
L2:
T4 = T1 == 2;
T5 = !T4;
if (T5) goto L3;
printf("%d\n", 222);
goto L1;
goto L1;
L3:
printf("%d\n", 333);
L1:
printf("%d\n", 999);
    return 0;
}
