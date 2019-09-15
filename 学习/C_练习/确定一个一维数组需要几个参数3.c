/*
        2018/5/21
        一定要明白第10行的pArr[3]和第17行 19行的是同一个变量
*/

#include<stdio.h>

void f(int * pArr, int len)
{
    pArr[3] = 88;     //10行
}

int main (void)
{
    int a[6] = {1,2,3,4,5,6};

    printf("%d\n", a[3]);   //17行
    f(a,6);
    printf("%d\n", a[3]);       //19行
    return 0;
}

/*
-------------------------
在CodeBlocks中的运行结果是：
4
88

-------------------------
*/
