/*
    2018/5/16
    ���ܣ��ж�һ�������ǲ��ǻ�����
    Ŀ�ģ�
*/

#include <stdio.h>
int main (void)
{
    int val;
    int sum=0;
    int m;
    printf("��������Ҫ�жϵ����֣�");
    scanf("%d", &val);

    m = val;
    while (m)
    {
        sum = sum*10 + m%10;
        m /= 10;
    }
    if (sum == val)
        printf("�ǻ�������\n");
    else
        printf("���ǻ�������\n");
    return 0;
}

/*
---------------------
��CodeBlocks�е����н���ǣ�
��������Ҫ�жϵ����֣�12321
�ǻ�������

---------------------
*/
