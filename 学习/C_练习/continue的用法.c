/*
    时间：2018年7月16日19:49:38
    目的：检验continue的用法
    功能：对用户的非法输入进行清除
*/
#include<stdio.h>

int main(void)
{
    int i;
    char ch;

    scanf("%d", &i);
    printf("i = %d\n", i);

    while (ch = getchar() != '\n')
        continue;
    int j;
    scanf("%d", &j);
    printf("j = %d\n", j);
    return 0;
}

/*
在CodeBlocks中运行的结果是：
--------------------------
123fdgsdg
i = 123
456gfdsg
j = 456

--------------------------
*/
