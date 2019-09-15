#include <stdio.h>

void f(int **q)
{
    int i = 5;
    //*q等价于p
    *q = i; //error, 因为*q=i，等价于p=i;这样写是错的
}

int main(void)
{
    int *p;
    f(&p);

    return 0;
}
