#include <stdio.h>

void g(int *p, int *q)
{
    *p = 1;
    *q = 2;
    return;
}

int main(void)
{
    int a = 5, b = 8;
    g(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
