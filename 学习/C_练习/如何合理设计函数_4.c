/*
    2018/5/17
    ��1��ĳ������֮�䣨���������ֱ������е����������������
    ��һ���������ж�һ�����Ƿ�������
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
