#include<stdio.h>

int main(void)
{
    int i = -5;
    int j = 0XFFFFFFFB;
    char ch;
    ch = 128;

    printf("%d\n", ch);     //Ҫ����Ϊʲô��������-128,'128'������int�ͣ�2����ΪFFFFFFF10000000
                            //��ת��Ϊchar��ʱFFFFFFF��ʧ10000000Ϊ����
    printf("%#X\n", i);
    printf("%d\n", j);
    return 0;
}
