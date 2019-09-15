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
总结：
    发送地址可以减少内存消耗，快速传递数据
*/
