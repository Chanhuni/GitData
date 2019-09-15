/*
    互换两个数字
*/
#include <stdio.h>
int main (void)
{
    int i = 3;
    int j = 5;
    int t;

    /*互换两个数字的正确方法*/
    t = i;
    i = j;
    j = t;

    printf("i = %d, j = %d\n", i, j);
    return 0;
}
