#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int len, i;
    int *pArr;

    printf("��������Ҫ��ŵ�һά����ĸ���:");
    scanf("%d", &len);
    pArr = (int *)malloc(4*len);

    for (i=0; i<len; ++i)
        scanf("%d", &pArr[i]);
    printf("һά�����ǣ�\n");
    for(i=0; i<len; ++i)
        printf("%d  ", pArr[i]);
    return 0;
}
