#include<stdio.h>
int main (void)
{
    int i;
    //int sum = 0;
    for(i = 1; i <= 100; i++)
    {
        if(0 == i%3)
            printf("%d  ", i);
    }
    return 0;
}
