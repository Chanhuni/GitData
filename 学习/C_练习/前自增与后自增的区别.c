/*
    2018/5/15
    目的：测试前自增与后自增的相同与不同点
*/
#include <stdio.h>
int main (void)
{
    int i, n, j, k;
    i=n=3;
    j = ++i;
    k = n++;
    printf("%d, %d, %d, %d", i, n, j, k);
    return 0;
}
/*
-------------------
在CodeBlocks中的输出结果为：
4, 4, 4, 3
总结：
分类：
        前自增：    ++i
        后自增：    i++
前自增与后自增的异同：
    相同：
        最终都使i的值加1
    不同：
        前自增整体表达式的值是i加1之后的值
        后自增整体表达式的值是i加1之前的值
-------------------
*/
