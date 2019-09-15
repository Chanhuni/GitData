/*
    日期：2018年5月13日 18:44
    目的：验证运算符的运算结果
*/
#include <stdio.h>
int main (void)
{
    int i=10;
    int k=20;
    int m;
    m=(1>2)&&(k=8); //&&左边是假的时候，右边不执行
    printf("m = %d, k = %d\n", m, k);
    return 0;
}
/*
-------------------------------
m = 0, k = 20
总结：
&&左边是假的时候，右边不执行
||左边为真的时候，右边不执行
（因为根据左边的表达式就已经能够确定整个表达式的真假了，不需要再执行右边的表达式了）
-------------------------------
*/
