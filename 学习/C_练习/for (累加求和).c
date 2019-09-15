/*
    2018/5/15
    目的：熟悉for的执行顺序
*/
#include <stdio.h>
int main (void)
{
    int i;
    int sum = 0;
    for (i = 1; i <= 100; ++i)
        sum +=  i;   //等价于 sum = i + sum
    printf("%d\n", sum);
    return 0;
}
/*
----------------------
总结：一：“i=1”
    二：“i<=100”
    三：“++i”
    四：“sum+=i”
执行顺序是：一二四三、二四三、二四三.............
----------------------
*/
