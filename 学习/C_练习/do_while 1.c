/*
    2018/5/16
    功能：求一元二次方程的解
    目的：do while 用于人机交互
*/

#include<stdio.h>

int main (void)
{
    double a, b, c, x1, x2;
    double delta;
    char ch;
    do
    {
        printf("请输入一元二次方程的三个系数：\n");
        scanf("%lf %lf %lf", &a, &b, &c);
        delta = b*b - 4*a*c;
        if(delta > 0)
        {
            x1 = (-b + sqrt(delta))/ (2*a);
            x2 = (-b - sqrt(delta))/ (2*a);
            printf("有两个解, x1 = %lf, x2 = %lf\n", x1, x2);
        }
        else if (0 == delta)
        {
            x1 = x2 = (-b) / (2*a);
            printf("有唯一解， x1 = x2 = %lf\n", x1, x2);
        }
        else
        {
            printf("无实数解！\n");
        }
        printf("继续请输入Y/y,退出请输入任意键:");
        scanf(" %c", &ch);       //%c前面必须加一个空格，原因略！
    }
    while('Y' == ch || 'y' == ch);
    return 0;
}
/*
------------------------
在CodeBlocks中的运行结果是：
请输入一元二次方程的三个系数：
1 3 5
无实数解！
继续请输入Y/y,退出请输入任意键:y
请输入一元二次方程的三个系数：
7 9 1
有两个解, x1 = -0.122849, x2 = -1.162865
继续请输入Y/y,退出请输入任意键:Y
请输入一元二次方程的三个系数：
1 4 4
有唯一解， x1 = x2 = -2.000000
继续请输入Y/y,退出请输入任意键:d
-----------------------------
总结：
------------------------
*/
