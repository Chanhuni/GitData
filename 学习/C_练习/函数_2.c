/*
    2018/5/17
    ��1��ĳ����֮�䣨���������֣����е����������������
    ֻ��main����ʵ�֣��о����ԣ�
        1,����������Բ��ߣ�
        2�����벻�������
*/

#include <stdio.h>

int main (void)
{
    int val;
    int i;
    int j;

    printf("������һ������");
    scanf("%d", &val);
    for (i = 2; i <= val; ++i)
    {
        //�ж�һ�����ǲ����������Ǿ���������ǲ����
        for (j = 2; j < i; ++j)
        {
            if (0 == i%j)
                break;
        }
        if (j == i)
            printf("%d  ", i);
    }
    return 0;
}
