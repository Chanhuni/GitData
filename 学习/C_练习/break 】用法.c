/*
    2018/5/16
    目的：break的用法
*/

#include <stdio.h>

int main (void)
{
    int i;
    for(i = 0; i < 3; i++)
    {
        if(3>2)
            break ;     //break 虽然是if内的语句，但是终止的是for 循环
        printf("哈哈哈！\n");       //永远不会输出
    }
    return 0;
}
