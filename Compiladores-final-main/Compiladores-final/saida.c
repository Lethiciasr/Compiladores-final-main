#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
int T1[3];
int T2;
int T3;
int T4;

T1[0] = 10;
T1[1] = 20;
T1[2] = 30;
T2 = T1[0];
printf("%d\n", T2);
T3 = T1[1];
printf("%d\n", T3);
T4 = T1[2];
printf("%d\n", T4);
    return 0;
}
