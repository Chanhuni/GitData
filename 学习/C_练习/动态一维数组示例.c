#include <stdio.h>
#include <malloc.h>

int main (void)
{
    int a[5];    //���intռ4���ֽڣ��������ܹ�������20���ֽڣ�
                //ÿ�ĸ��ֽڱ�������һ��int������ʹ��
    int len;
    int *pArr;
    int i;

    printf("��������Ҫ��ŵ�Ԫ�صĸ�����");
    scanf("%d", &len);
    pArr = (int *)malloc(4 * len);  //���ж�̬�Ĺ�����һ��һά���飬��һά����ĳ�����len�����������������pArr��
                                    //�������ÿ��Ԫ����int���� �������� int pArr[len]
    //��һά������в���
    for (i = 0; i < len; ++i)
        scanf("%d", &pArr[i]);

    //��һά����������
    for(i = 0; i < len; ++i)
        printf("%d\n", pArr[i]);

    free(pArr);   //�ͷŵ���̬���������

    return 0;
}
