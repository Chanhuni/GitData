#include<stdio.h>
#include <string.h>

struct Student
{
    int age;
    char sex;
    char name[100];
};  //�ֺŲ���ʡ

void InputStudent (struct Student * pstu)
{
    (*pstu).age = 10;
    strcpy (pstu->name, "����");
    pstu->sex = 'F';
}

void OutputStudent(struct Student * pst)
{
    printf ("%d %c %s\n", pst->age, pst->sex, pst->name);
}

int main (void)
{
    struct Student st;

    InputStudent(&st);
    OutputStudent(&st);

    return 0;
}

/*
�ܽ᣺
    ���͵�ַ���Լ����ڴ����ģ����ٴ�������
*/
