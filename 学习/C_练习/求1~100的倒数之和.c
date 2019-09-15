#include <stdio.h>
int main (void)
{
    int i;
    float sum=0;
    for(i = 1; i <= 100; i++)
    {
        sum = sum + 1/(float) (i);  //是OK的  （不推荐）
        //sum = sum + (float)(1/i); 这样写是不对的
        //更简单的写法是：sum =sum + 1.0/i;   （推荐）
    }
    printf("%f\n", sum);   //float必须要用%f输出
    return 0;
}
