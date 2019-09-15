#include<stdio.h>
int main(void)
{
    int i, j;
    char ch;
    scanf("%d", &i);
    printf("i = %d\n", i);
    while((ch=getchar()) != '\n')
        continue;
    scanf("%d", &j);
    printf("j = %d\n", j);
    return 0;
}
