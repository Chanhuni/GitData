#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int len, i;
    int *pArr;

    printf("请输入你要存放的一维数组的个数:");
    scanf("%d", &len);
    pArr = (int *)malloc(4*len);

    for (i=0; i<len; ++i)
        scanf("%d", &pArr[i]);
    printf("一维数组是：\n");
    for(i=0; i<len; ++i)
        printf("%d  ", pArr[i]);
    return 0;
}
