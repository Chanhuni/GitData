/*
    2018/5/17
    求1到某个数字之间（包括该数字本身）所有的素数，并将其输出
    用一个函数来判断一个数是否是素数
*/

#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int val)
{
   int i;
   for(i = 2; i < val; ++i)
   {
       if(0 == val%i)
            break;
   }
   if(val == i)
        return true;
    else
        return false;
}

int main (void)
{
    int val;
    int i;

    scanf("%d", &val);
    for(i=2; i<=val; ++i)
    {
        if ( IsPrime(i))
            printf("%-5d", i);
    }
    return 0;
}
