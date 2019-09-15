#include <stdio.h>

int main(void)
{
    int a[5] = {0};
    //int b[3][4];

    printf("%#X %#X", &a[0], a);

    return 0;
}
