
/*

*/

#include<stdio.h>
#include<stdbool.h>
bool IsPrime(int val);

/*�������Ĺ��������2����n֮�����������*/
void TraverseVal(int n)
{
    int i;
    for(i=2; i<=n; ++i)
    {
        if(IsPrime(i))
            printf("%d\n", i);
    }
}

/*�������Ĺ������ж�val�ǲ�������*/
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

    printf("������һ������");
    scanf("%d", &val);
    TraverseVal(val);
    return 0;
}
