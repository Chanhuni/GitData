#include<stdio.h>
int main(void)
{
    int i;
    int m;
    int sum = 0;
    printf("������һ�����֣�");
    scanf("%d", &i);

    m = i;
    while(m)
    {
        sum = sum * 10 +m%10;
        m /= 10;
    }
    if (sum == i)
        printf("�������ǻ�������");
    else
        printf("�����ֲ��ǻ�������");
    return 0;
}
