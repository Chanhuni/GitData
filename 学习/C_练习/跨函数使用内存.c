#include <stdio.h>

void f(int **q)
{
    int i = 5;
    //*q�ȼ���p
    *q = i; //error, ��Ϊ*q=i���ȼ���p=i;����д�Ǵ��
}

int main(void)
{
    int *p;
    f(&p);

    return 0;
}
