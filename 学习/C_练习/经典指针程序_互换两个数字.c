#include<stdio.h>

void exchange_1 (int *p, int *q)
{
    int * t;
    t = p;
    p = q;
    q = t;
    /*
        ����֮ǰ��p�������a�ĵ�ַ,q�������b�ĵ�ַ
        ����֮��p�������b�ĵ�ַ,q�������a�ĵ�ַ
    */
}

void exchange (int *p, int *q)
{
    int  t;
    t = *p;
    *p = *q;
    *q = t;
}

int main (void)
{
    int a = 3;
    int b = 5;
    exchange(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
