/*
    日期：2018年5月13日
    目的：测试scanf的作用
*/
#include <stdio.h>

int main (void)
{
    int i;
    scanf ("%d", &i); //&i表示取i的地址，&是一个取地址符
    printf ("i=%d\n", i);
}
