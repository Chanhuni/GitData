/*
    2018/5/15
    ���ܣ��������ĸ����������͡�ż���͡�������ƽ����
    Ŀ�ģ���ϰfor��if��ʹ��
*/
#include <stdio.h>
int main (void)
{
    int i;
    int jige=0;           //�����ĸ���
    int sumji = 0;     //������
    int sumou = 0;     //ż����
    float avg;        //������ƽ����
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

    avg =1.0*sumji/jige;      //1.0Ĭ����double����
    printf("%d, %d, %f, %d", jige, sumji, avg, sumou);

    return 0;
}
/*
------------------------------
��CodeBlocks�е����н���ǣ�
50, 2500, 50.000000, 2550
�ܽ᣺
------------------------------
*/
