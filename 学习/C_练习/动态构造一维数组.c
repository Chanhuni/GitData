#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int a[5];
    int len;
    int *pArr;
    int i;

    //动态构造一维数组
    printf("请输入你要存放的元素的个数:");
    scanf("%d", & len);
    pArr = (int *)malloc(4*len);

    //对一维数组进行操作， 如对一维数组进行赋值
    for(i=0; i<len; i++)
        scanf("%d", &pArr[i]);

    //对一维数组进行输出
    printf("一维数组的内容是:\n");
    for(i=0; i<len; ++i)
        printf("%d\n", pArr[i]);

    free(pArr);  //释放动态分配的数组
    return 0;
}
