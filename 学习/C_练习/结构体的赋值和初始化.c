/*
        2018/5/22
        结构体变量的赋值和初始化
*/

#include<stdio.h>

struct Student
{
    int age;
    float score;
    char sex;
};

int main (void)
{
    struct Student st = {80, 66.6, 'F'};
    struct Student st2;
    st2.age = 10;
    st2.score = 88;
    st2.sex = 'F';

    printf("%d %f %c\n", st.age, st.score, st.sex);
    printf("%d %f %c\n", st2.age, st2.score, st2.sex);
    return 0;
}

/*
-------------------------
在CodeBlocks中运行的结果是：
80 66.599998 F
10 88.000000 F

Process returned 0 (0x0)   execution time : 0.376 s
Press any key to continue.

-------------------------
*/
