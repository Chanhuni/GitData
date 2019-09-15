#include <stdio.h>

struct Student
{
    int age;
    float score;
    char sex;
};

int main(void)
{
    struct Student st = {10, 66.6, 'F'};
    struct Student *pst = &st;  //&st不能写成st
    pst->age = 88;  //第二种方式，pst->age 在计算机内部会被转化为(*pst).age
                    //通常使用第二种方式
    st.score = 20.2f;  //第一种方式
    printf("%d %f\n", st.age, pst->score);
    return 0;
}
