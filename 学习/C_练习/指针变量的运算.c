#include <stdio.h>

int main(void)
{
    int *p;
    int *q;
    int a[5];
    p = &a[4], q = &a[1];
    printf("p和q相隔%d个单元", (p-q));

    return 0;
}
