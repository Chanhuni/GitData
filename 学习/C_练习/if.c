#include <stdio.h>
int main (void)
{
    if(3>2)
        printf("aaaaaaaaaaa\n");
    if(0)
        printf("BBBBBBBB\n");
    if(1>2)
        printf("CCCCCCCCCC\n");
        printf("DDDDDDDDDDDDDDD\n");  //������if�ڵ����
    return 0;
}
/*
    ��CodeBlock�е����н���ǣ�
----------------------------------
aaaaaaaaaaa
DDDDDDDDDDDDDDD
----------------------------------
*/
