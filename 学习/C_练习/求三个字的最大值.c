/*
    2018/5/13
    功能：将三个数降序排列
*/
#include <stdio.h>
int main(void)
{
    int a, b, c,t;
    printf("请输入三个整数（中间以空格隔开）");
    scanf("%d %d %d", &a, &b, &c);

    //编写代码完成a是最大值 b是中间值 c是最小值
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    if(a<c)
    {
        t=a;
        a=c;
        c=t;
    }
    if (b < c)
    {
        t=c;
        c=b;
        b=t;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}
