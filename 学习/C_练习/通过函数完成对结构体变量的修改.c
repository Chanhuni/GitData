#include <stdio.h>
#include <string.h>

struct Student
{
    int age;
    char sex;
    char name[100];
};

void InputStudent(struct Student *stu);
void OutputStudent(struct Student *);

int main(void)
{
    struct Student st;
    //printf("%d\n", sizeof(st));

    InputStudent(&st);
    OutputStudent(&st);  // �Խṹ�������������Է���st�ĵ�ַҲ����ֱ�ӷ���st������ָ����Կ��ٵĴ������ݣ�ʡ�ڴ�
    return 0;
}

void InputStudent(struct Student *pstu)
{
    (*pstu).age = 10;
    strcpy(pstu->name,"����");
    pstu->sex = 'F';
}

void OutputStudent(struct Student *pst)
{
     printf("%d %c %s\n", pst->age, pst->sex, pst->name);
}

/*�������޷��޸�����������st��ֵ
void InputStudent(struct Student stu)
{
    stu.age = 10;
    strcpy(stu.name, "����");  //����д��stu.name = ��������
    stu.sex = 'F';
}*/
