#include <stdio.h>

int main(void)
{
    int * p;
    int i = 5;
    char ch ='A';

    p = &i;     //*p ��p������Ϊ��ַ�ı���
    //p = &ch;  error p�������ͱ����ĵ�ַ
    printf("%d %d %c", i, *p, ch);
    return 0;
}
