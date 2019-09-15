#include <stdio.h>
int main (void)
{
    if(3>2)
        printf("aaaaaaaaaaa\n");
    if(0)
        printf("BBBBBBBB\n");
    if(1>2)
        printf("CCCCCCCCCC\n");
        printf("DDDDDDDDDDDDDDD\n");  //不属于if内的语句
    return 0;
}
/*
    在CodeBlock中的运行结果是：
----------------------------------
aaaaaaaaaaa
DDDDDDDDDDDDDDD
----------------------------------
*/
