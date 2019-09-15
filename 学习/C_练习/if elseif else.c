/*
    2018/5/13
    一定要明白程序为什么会出错！
*/
#include<stdio.h>
int main (void)
{
    double delta=1;
    if (delta>0)
        printf("两个解！\n");
        printf("哈哈！\n");  //该语句把“if elseif”分开了
    else if (delta=0)         //没有以“else if”开头的语句
        printf("唯一解！\n");
    else
        printf("无解！\n");
    return 0;
}
