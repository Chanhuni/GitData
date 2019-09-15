
/*

*/

#include<stdio.h>
#include<stdbool.h>
bool IsPrime(int val);

/*本函数的功能是输出2——n之间的所有素数*/
void TraverseVal(int n)
{
    int i;
    for(i=2; i<=n; ++i)
    {
        if(IsPrime(i))
            printf("%d\n", i);
    }
}

/*本函数的功能是判断val是不是素数*/
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
    int val, i;

    printf("请输入一个数：");
    scanf("%d", &val);
    TraverseVal(val);
    return 0;
}
