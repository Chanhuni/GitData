#include <stdio.h>

struct Student
{
    int age;
    float score;
    char sex;
};

int main (void)
{
    struct Student st = {80, 66.6F, 'F'};   //��ʼ��  �����ͬʱ����ֵ
    struct Student * pst = &st; //&st���ܸĳ�st

    pst->age = 88;  //�ڶ��ַ�ʽ����
    st.score = 66.6f;   //��һ�ַ�ʽ����  66.6��c������Ĭ����double����
    printf("%d %f\n", st.age, pst->score);

    return 0;
}
