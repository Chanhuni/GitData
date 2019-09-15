#include<stdio.h>

void exchange_1 (int *p, int *q)
{
    int * t;
    t = p;
    p = q;
    q = t;
    /*
        互换之前：p保存的是a的地址,q保存的是b的地址
        互换之后：p保存的是b的地址,q保存的是a的地址
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
