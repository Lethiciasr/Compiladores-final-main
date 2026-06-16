#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
char T1[7];
char T2[7];

strcpy(T1, "Teste ");
strcpy(T2, T1);
printf("%s\n", T2);
    return 0;
}
