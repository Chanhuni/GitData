/*
    2018/5/15
    功能：求奇数的个数、奇数和、偶数和、奇数的平均数
    目的：练习for、if的使用
*/
#include <stdio.h>
int main (void)
{
    int i;
    int jige=0;           //奇数的个数
    int sumji = 0;     //奇数和
    int sumou = 0;     //偶数和
    float avg;        //奇数的平均数
    for(i = 1; i <= 100; i++)
    {
        if(i%2!=0)
        {
            jige++;
            sumji = sumji + i;
        }
        if(i%2==0)
            sumou = sumou + i;
    }

    avg =1.0*sumji/jige;      //1.0默认是double类型
    printf("%d, %d, %f, %d", jige, sumji, avg, sumou);

    return 0;
}
/*
------------------------------
在CodeBlocks中的运行结果是：
50, 2500, 50.000000, 2550
总结：
------------------------------
*/
