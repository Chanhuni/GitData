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

    huhuan_3(&a, &b); //huhuan_3(*p,*q);是错误的，huhuan_3(a,b);也是错误的
    printf("a = %d, b = %d", a, b);

    return 0;
}

/*
//不能完成互换
void huhuan_1(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

//也不能完成互换
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
    int  t;     //如果要换*p和*q的值，则t必须定义成int，不能定义成int *
    t = * p;
    * p = * q;
    * q = t;
    return ;
}
