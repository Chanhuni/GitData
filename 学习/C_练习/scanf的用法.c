/*
    时间：2018年7月7日22:45:07
    目的：测试scanf的用法
    功能：将从键盘输入的字符转化为输入控制符所规定的格式的数据，
          然后存入以输入参数位地址的变量中
*/
#include <stdio.h>

int main (void)
{
    int i;
    printf("请输入整数i:");
    scanf("%d", &i);
    printf("i = %d\n", i);
    return 0;
}
