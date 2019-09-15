#include <stdio.h>

void f(int**q)
{
    **q =1;
}

void g()
{
    int i = 10;
    int *p = &i;

    f(&p);  //p是int*类型,&p是int**类型
    printf("%d", i);
}


int main (void)
{
    g();

    return 0;
}
