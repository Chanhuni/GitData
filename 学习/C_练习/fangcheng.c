#include<stdio.h>
#include<math.h>

int main (void)
{
    int a=1;
    int b=21;
    int c=5;
    double delta;
    double x1; //存放一元二次方程的两个解
    double x2;
    delta=b*b-4*a*c;
    if(delta>0)
    {
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
        printf("该方程有两个解\n‘x1=%f,x2=%f\n",x1,x2);
    }
    else if(delta==0)
    {
        x1=(-b+sqrt(delta))/(2*a);
        x2=x1;
        printf("该一元二次方程有一个解，x1=x2=%f\n",x1);
    }
    else
    {
        printf("该方程无解\n");
    }
    return 0;
}
