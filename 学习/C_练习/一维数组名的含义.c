#include <stdio.h>

int main (void)
{
    int a[5];
    int b[5];
    int c[5] = {1,2,3,4,5};

    //a = b;        //error 因为a是常量
    printf("%#X\n", &a[0]);
    printf("%#X\n", a);
    printf("%d\n",*c);
    printf("%d\n",*(c+3));  //猜想？这里应该输出4

    if(c[2] == *(c+2))
    {
        printf("您的推导是正确的！\n");
    }
    else
    {
        printf("您的推导是错误的！\n");
    }
    return 0;
}

/*
---------------------------
在CodeBlocks中的输出结果是：
0X28FF0C
0X28FF0C
1
4
您的推导是正确的！

---------------------------
    结论：
        一维数组名是个指针常量
        它存放的是一维数组第一个元素的地址
        a是a[0]的地址

        推导出：c[i] = *(c+i)
*/
