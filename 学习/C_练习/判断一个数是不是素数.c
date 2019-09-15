/*
    时间：2018年7月17日20:44:13
    目的：熟悉函数的使用
*/

#include <stdio.h>
#include<stdbool.h> //bool函数的头文件

bool IsPrime(int val)
{
    int i;

    for(i=2; i<val; ++i)
    {
        if(val%i == 0)
            break;
    }
    if(i == val)
        return true;
    else
        return false;
}

int main(void)
{
    int m;

    printf("请输入一个数：");
    scanf("%d", &m);
    if(IsPrime(m))
        printf("这个数是素数！\n");
    else
        printf("这个数不是素数！\n");

    return 0;
}


/*
在CodeBlocks中运行的结果是：
----------------------------
请输入一个数：123
这个数不是素数！
----------------------------
*/
