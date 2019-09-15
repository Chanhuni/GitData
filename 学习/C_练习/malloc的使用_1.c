/*
    2018/5 /19
*/

#include <stdio.h>
#include <malloc.h>

int main (void)
{
    int i = 5;  //分配了4个字节
    int * p = (int *)malloc(4);
        /*
            1.要使用malloc函数必须添加malloc.h这个头文件
            2.malloc函数只有一个形参，并且形参是整型
            3.4请求系统为本程序分配4个字节
            4.malloc函数只能返回一个字节的地址
            5.第10行分配了8个字节，p变量占4个字节，p所指向的内存是动态分配的
            6.p本身所占的内存是静态分配的，p所指向的内存是动态分配的
        */
    *p = 5;
    free (p);
    printf("同志们好！\n");
    return 0;
}

/*
------------------------
在CodeBlocks中运行的结果是：
------------------------
*/
