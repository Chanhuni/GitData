/*
    ʱ�䣺2018��7��16��19:49:38
    Ŀ�ģ�����continue���÷�
    ���ܣ����û��ķǷ�����������
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
��CodeBlocks�����еĽ���ǣ�
--------------------------
123fdgsdg
i = 123
456gfdsg
j = 456

--------------------------
*/
