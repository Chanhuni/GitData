/*
    2018/5/15
    Ŀ�ģ���1~100֮�����������
*/
#include <stdio.h>
int main (void)
{
    int i;
    int sum = 0;
    for(i = 1; i <= 10; i+= 2)
    {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
