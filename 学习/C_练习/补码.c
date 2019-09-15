#include<stdio.h>

int main(void)
{
    int i = -5;
    int j = 0XFFFFFFFB;
    char ch;
    ch = 128;

    printf("%d\n", ch);     //要明白为什么输出结果是-128,'128'本身是int型，2进制为FFFFFFF10000000
                            //在转换为char型时FFFFFFF丢失10000000为负数
    printf("%#X\n", i);
    printf("%d\n", j);
    return 0;
}
