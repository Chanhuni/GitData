/*
    2018/5/17
    求1到某个数之间（包括该数字）所有的素数，并将其输出
    只用main函数实现，有局限性：
        1,代码的重用性不高；
        2，代码不容易理解
*/

#include <stdio.h>

int main (void)
{
    int val;
    int i;
    int j;

    printf("请输入一个数：");
    scanf("%d", &val);
    for (i = 2; i <= val; ++i)
    {
        //判断一个数是不是素数，是就输出，不是不输出
        for (j = 2; j < i; ++j)
        {
            if (0 == i%j)
                break;
        }
        if (j == i)
            printf("%d  ", i);
    }
    return 0;
}
