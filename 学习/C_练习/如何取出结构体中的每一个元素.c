#include <stdio.h>

struct Student
{
    int age;
    float score;
    char sex;
};

int main (void)
{
    struct Student st = {80, 66.6F, 'F'};   //初始化  定义的同时赋初值
    struct Student * pst = &st; //&st不能改成st

    pst->age = 88;  //第二种方式定义
    st.score = 66.6f;   //第一种方式定义  66.6在c语言中默认是double类型
    printf("%d %f\n", st.age, pst->score);

    return 0;
}
