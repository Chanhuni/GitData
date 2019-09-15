/*
    2018/5/17
    判断一个数是不是素数
*/
#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int val)
{
    int i;

    for(i = 2; i < val; i++)
    {
        if (0 == val%i)
            break;
    }
    if (i == val)
        return true;
    else
        return false;
}

int main (void)
{
    int val;
    printf ("请输入一个数：");
    scanf ("%d/n", &val);
    if(IsPrime(val))
        printf("Yes!");
    else
        printf("No!");
    return 0;
}
