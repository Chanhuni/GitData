#include<stdio.h>
int main(void)
{
    int i;
    int m;
    int sum = 0;
    printf("请输入一个数字：");
    scanf("%d", &i);

    m = i;
    while(m)
    {
        sum = sum * 10 +m%10;
        m /= 10;
    }
    if (sum == i)
        printf("该数字是回文数！");
    else
        printf("该数字不是回文数！");
    return 0;
}
