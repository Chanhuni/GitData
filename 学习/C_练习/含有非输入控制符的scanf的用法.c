/*
    时间：2018年7月7日23:03:15
    目的：测试scanf中非输入控制符的用法
*/

#include<stdio.h>

int main(void)
{
    int i;
    scanf("m%d", &i);
    printf("i = %d", i);
    return 0;
}


/*
在CodeBlocks中运行的结果是：
-----------------------
m123
i = 123
-----------------------
*/
