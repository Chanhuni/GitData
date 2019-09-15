/*
    日期：2018年5月13日
    目的：练习scanf的第二种用法
*/
#include <stdio.h>
int main (void)
{
    int i, j, k;
    printf ("请输入三个数字，第一个数字前加m,数字间中间以逗号隔开\n");
    scanf ("m%d,%d,%d",&i,&j,&k); //m , 都是非输入控制符
    printf ("i=%d,j=%d,k=%d\n",i,j,k);
    return 0;
}
/*
-------------------------------
在CodeBlock中的输出结果：
请输入三个数字，第一个数字前加m,数字间中间以逗号隔开
m31,56,78
i=31,j=56,k=78

Process returned 0 (0x0)   execution time : 20.252 s
Press any key to continue.
总结：
-------------------------------
*/

