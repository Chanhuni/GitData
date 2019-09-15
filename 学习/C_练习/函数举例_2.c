#include<stdio.h>

int f(void)
{
    return 10;
}

int main (void)
{
    int j = 88;

    j = f();
    printf("%d\n", j);
    return 0;
}
