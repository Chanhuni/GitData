#include<stdio.h>
#include<malloc.h>

int main (void)
{
    int *p = (int*)malloc(8);
    * p = 1;
    *(p+1) = 2;
    printf("%d  %d", *p, *(p+1));
    return 0;
}
