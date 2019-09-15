#include<stdio.h>

void huhuan(int *p, int *q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;
    printf("a=%d, b=%d", *p, *q);
}

int main(void)
{
    int a = 3;
    int b = 5;
    huhuan(&a, &b);
    printf("\na=%d, b=%d", a, b);
    return 0;
}
