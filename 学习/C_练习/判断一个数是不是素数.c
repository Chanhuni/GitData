/*
    ʱ�䣺2018��7��17��20:44:13
    Ŀ�ģ���Ϥ������ʹ��
*/

#include <stdio.h>
#include<stdbool.h> //bool������ͷ�ļ�

bool IsPrime(int val)
{
    int i;

    for(i=2; i<val; ++i)
    {
        if(val%i == 0)
            break;
    }
    if(i == val)
        return true;
    else
        return false;
}

int main(void)
{
    int m;

    printf("������һ������");
    scanf("%d", &m);
    if(IsPrime(m))
        printf("�������������\n");
    else
        printf("���������������\n");

    return 0;
}


/*
��CodeBlocks�����еĽ���ǣ�
----------------------------
������һ������123
���������������
----------------------------
*/
