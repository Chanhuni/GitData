/*
    时间：2018年7月23日22:18:17
    一定要明白10行的pArr[3]与17行和19行的a[3]
    是同一个变量
*/

#include <stdio.h>

void f(int *pArr, int len)
{
    pArr[3] = 88;   //10行
    return;
}

int main(void)
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    printf("%d\n", a[3]);   //17行
    f(a,6);
    printf("%d\n", a[3]);   //19行

    return 0;
}

/*
在CodeBlocks中运行的结果是：
---------------------------
4
88

---------------------------
*/
