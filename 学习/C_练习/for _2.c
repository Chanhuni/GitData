/*
    2018/5/15
    目的：求1~100之间的所有奇数
*/
#include <stdio.h>
int main (void)
{
    int i;
    int sum = 0;
    for(i = 1; i <= 10; i+= 2)
    {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
