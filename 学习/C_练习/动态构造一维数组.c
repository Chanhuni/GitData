#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int a[5];
    int len;
    int *pArr;
    int i;

    //��̬����һά����
    printf("��������Ҫ��ŵ�Ԫ�صĸ���:");
    scanf("%d", & len);
    pArr = (int *)malloc(4*len);

    //��һά������в����� ���һά������и�ֵ
    for(i=0; i<len; i++)
        scanf("%d", &pArr[i]);

    //��һά����������
    printf("һά�����������:\n");
    for(i=0; i<len; ++i)
        printf("%d\n", pArr[i]);

    free(pArr);  //�ͷŶ�̬���������
    return 0;
}
