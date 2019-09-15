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
    OutputStudent(&st);  // 对结构体进行输出，可以发送st的地址也可以直接发送st，发送指针可以快速的传送数据，省内存
    return 0;
}

void InputStudent(struct Student *pstu)
{
    (*pstu).age = 10;
    strcpy(pstu->name,"张三");
    pstu->sex = 'F';
}

void OutputStudent(struct Student *pst)
{
     printf("%d %c %s\n", pst->age, pst->sex, pst->name);
}

/*本函数无法修改主调函数中st的值
void InputStudent(struct Student stu)
{
    stu.age = 10;
    strcpy(stu.name, "张三");  //不能写成stu.name = “张三”
    stu.sex = 'F';
}*/
