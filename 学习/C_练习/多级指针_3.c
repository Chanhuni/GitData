#include <stdio.h>

void f(int**q)
{
    **q =1;
}

void g()
{
    int i = 10;
    int *p = &i;

    f(&p);  //p��int*����,&p��int**����
    printf("%d", i);
}


int main (void)
{
    g();

    return 0;
}
