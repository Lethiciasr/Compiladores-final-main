#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
int T1;
int T2;
bool T3;
bool T4;
int T5;
int T6;

T1 = 1;
T2 = 1;

L1:
T3 = T2 <= 10;
T4 = !T3;
if (T4) goto L2;
T5 = T2 + 1;
printf("%d\n", T2);
T6 = 2;
T2 = T5;
goto L1;
L2:

T1 = 3;
    return 0;
}
