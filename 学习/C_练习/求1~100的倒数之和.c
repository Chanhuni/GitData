#include <stdio.h>
int main (void)
{
    int i;
    float sum=0;
    for(i = 1; i <= 100; i++)
    {
        sum = sum + 1/(float) (i);  //��OK��  �����Ƽ���
        //sum = sum + (float)(1/i); ����д�ǲ��Ե�
        //���򵥵�д���ǣ�sum =sum + 1.0/i;   ���Ƽ���
    }
    printf("%f\n", sum);   //float����Ҫ��%f���
    return 0;
}
