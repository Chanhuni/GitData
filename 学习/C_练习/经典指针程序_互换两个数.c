/*
        2018/5/18

*/

#include <stdio.h>

//void huhuan_1(int, int);
//void huhuan_2(int *, int *);
void huhuan_3(int *, int *);

int main (void)
{
    int a = 3;
    int b = 5;

    huhuan_3(&a, &b); //huhuan_3(*p,*q);�Ǵ���ģ�huhuan_3(a,b);Ҳ�Ǵ����
    printf("a = %d, b = %d", a, b);

    return 0;
}

/*
//������ɻ���
void huhuan_1(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

//Ҳ������ɻ���
void huhuan_2(int * p, int * q)
{
    int * t;
    t = p;
    p = q;
    q = t;
}
*/

void huhuan_3(int * p, int * q)
{
    int  t;     //���Ҫ��*p��*q��ֵ����t���붨���int�����ܶ����int *
    t = * p;
    * p = * q;
    * q = t;
    return ;
}
