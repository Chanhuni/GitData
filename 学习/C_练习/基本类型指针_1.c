#include <stdio.h>

int main(void)
{
    int * p;
    int i = 5;
    char ch ='A';

    p = &i;     //*p 以p的内容为地址的变量
    //p = &ch;  error p保存整型变量的地址
    printf("%d %d %c", i, *p, ch);
    return 0;
}
