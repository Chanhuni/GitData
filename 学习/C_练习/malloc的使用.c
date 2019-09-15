#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int i = 5;
    int *p = (int *)malloc(4);
            /*
                1.要使用malloc函数，必须添加malloc.h这个头文件
                2.malloc函数只有一个形参，并且形参是整型
                3.4表示请求系统为本程序分配4个字节
                4.malloc函数只能返回一个字节的地址
            */
    *p = 5;
    free(p);    //free(p)表示把p所指向的内存给释放掉，p本身的内存是静态的
    printf("哈哈哈啊哈哈！\n");

    return 0;
}

