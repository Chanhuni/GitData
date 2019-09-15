#include<stdio.h>

struct Student
{
    int age;
    char sex;
    char name[100];
};  //分号不能省


int main (void)
{
    struct Student st = {20, 'F', "小娟"};
    struct Student * pst = &st;

    printf("%d %c %s\n", st.age, st.sex, st.name);
    printf("%d %c %s\n", pst->age, pst->sex, pst->name);
    return 0;
}

/*
---------------------------
在CodeBlocks中运行的结果是：
20 F 小娟
20 F 小娟

Process returned 0 (0x0)   execution time : 0.272 s
Press any key to continue.

---------------------------
*/
