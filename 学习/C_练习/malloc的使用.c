#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int i = 5;
    int *p = (int *)malloc(4);
            /*
                1.Ҫʹ��malloc�������������malloc.h���ͷ�ļ�
                2.malloc����ֻ��һ���βΣ������β�������
                3.4��ʾ����ϵͳΪ���������4���ֽ�
                4.malloc����ֻ�ܷ���һ���ֽڵĵ�ַ
            */
    *p = 5;
    free(p);    //free(p)��ʾ��p��ָ����ڴ���ͷŵ���p������ڴ��Ǿ�̬��
    printf("��������������\n");

    return 0;
}

