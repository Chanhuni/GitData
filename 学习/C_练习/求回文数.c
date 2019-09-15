/*
    2018/5/16
    功能：判断一段数字是不是回文数
    目的：
*/

#include <stdio.h>
int main (void)
{
    int val;
    int sum=0;
    int m;
    printf("请输入您要判断的数字：");
    scanf("%d", &val);

    m = val;
    while (m)
    {
        sum = sum*10 + m%10;
        m /= 10;
    }
    if (sum == val)
        printf("是回文数！\n");
    else
        printf("不是回文数！\n");
    return 0;
}

/*
---------------------
在CodeBlocks中的运行结果是：
请输入您要判断的数字：12321
是回文数！

---------------------
*/
