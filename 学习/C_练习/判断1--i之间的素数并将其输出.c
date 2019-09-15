/*

*/

#include<stdio.h>
#include<stdbool.h>

bool IsPrime(int val)
{
    int i;

    for(i=2; i<val; ++i)
    {
        if(val%i == 0)
            break;
    }
    if(i == val)
        return true;
    else
        return false;
}

int main(void)
{
    int val, i, j;

    printf("请输入一个数：");
    scanf("%d", &val);
    for(i=2; i<=val; ++i)
    {
        if(IsPrime(i))
            printf("%d\n", i);
    }
    return 0;
}
