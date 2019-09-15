/*
    时间：2018年7月16日21:18:25
    目的：熟悉数组
    功能：把一个数组中的所有元素全部倒过来
*/

#include<stdio.h>

int main(void)
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int i, j;
    int t;

    i = 0;
    j = 6;
    while(i < j)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }

    for (i=0; i<7; ++i)
        printf("%d  ", a[i]);
    return 0;
}

/*
在CodeBlocks中运行的结果是：
--------------------------
7  6  5  4  3  2  1
--------------------------
*/
