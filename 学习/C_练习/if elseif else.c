/*
    2018/5/13
    һ��Ҫ���׳���Ϊʲô�����
*/
#include<stdio.h>
int main (void)
{
    double delta=1;
    if (delta>0)
        printf("�����⣡\n");
        printf("������\n");  //�����ѡ�if elseif���ֿ���
    else if (delta=0)         //û���ԡ�else if����ͷ�����
        printf("Ψһ�⣡\n");
    else
        printf("�޽⣡\n");
    return 0;
}
