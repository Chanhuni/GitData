#include <stdio.h>

int main(void)
{
    float score;  //score����

    printf ("���������ķ�����");
    scanf ("%f", &score);

    if (score > 100)
        printf ("�������Σ�\n");
    else if (score>=90 )
        printf ("���㣡\n");
    else if (score>=80)
        printf ("���ã�\n");
     else if (score>=60)
        printf ("����\n");
    else if (score<0)
        printf("����ķ������ͣ���Ҫ����Ա���\n");
    else
        printf ("�����񣡼���Ŭ����/n");
    return 0;
}
