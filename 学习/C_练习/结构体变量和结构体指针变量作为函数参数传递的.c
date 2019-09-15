#include<stdio.h>
#include <string.h>

struct Student
{
    int age;
    char sex;
    char name[100];
};  //分号不能省

void InputStudent (struct Student * pstu)
{
    (*pstu).age = 10;
    strcpy (pstu->name, "张三");
    pstu->sex = 'F';
}

void OutputStudent(struct Student ss)
{
    printf ("%d %c %s\n", ss.age, ss.sex, ss.name);
}

int main (void)
{
    struct Student st;

    InputStudent(&st);
    OutputStudent(st);

    return 0;
}

