#include <stdio.h>

int main(void)
{
    float score;  //score分数

    printf ("请输入您的分数：");
    scanf ("%f", &score);

    if (score > 100)
        printf ("你在做梦！\n");
    else if (score>=90 )
        printf ("优秀！\n");
    else if (score>=80)
        printf ("良好！\n");
     else if (score>=60)
        printf ("及格！\n");
    else if (score<0)
        printf("输入的分数过低，不要如此自卑！\n");
    else
        printf ("不及格！继续努力！/n");
    return 0;
}
