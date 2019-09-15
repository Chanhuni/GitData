/*
        2018/5/18
*/

#include <stdio.h>

void f(int * p, int *q)
{
    *p = 1;
    *q = 2;
    return ;
}

int main (void)
{
    int i = 3;
    int j = 5;
    f(&i, &j);
    printf("%d  %d\n",i, j);
    return 0;
}
