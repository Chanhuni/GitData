/*
    2018/5/17
    �ж�һ�����ǲ�������
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
    printf ("������һ������");
    scanf ("%d/n", &val);
    if(IsPrime(val))
        printf("Yes!");
    else
        printf("No!");
    return 0;
}
