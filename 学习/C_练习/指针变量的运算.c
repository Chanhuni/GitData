#include <stdio.h>

int main(void)
{
    int *p;
    int *q;
    int a[5];
    p = &a[4], q = &a[1];
    printf("p��q���%d����Ԫ", (p-q));

    return 0;
}
