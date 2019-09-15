#include<stdio.h>
int main(void)
{
    int sum = 0;
    int i;
    /*for (i = 1; i <= 100; ++i)
    {
        sum += i;
    }*/
    i = 1;
    while(i <= 100)
    {
        sum += i;
        ++i;
    }
    printf("%d", sum);
    return 0;
}
