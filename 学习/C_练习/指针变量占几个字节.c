#include <stdio.h>

int main(void)
{
    char ch = 'A';
    int i = 99;
    double x = 66.6;
    char *p = &ch;
    int *q = &i;
    double *r = &x;

    printf("%d %d %d", sizeof(p), sizeof(q), sizeof(r));
    return 0;
}

/*
��CodeBlocks�����еĽ���ǣ�
-------------------------
4 4 4
-------------------------
*/
