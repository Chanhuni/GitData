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
    struct Student *pst = &st;  //&st����д��st
    pst->age = 88;  //�ڶ��ַ�ʽ��pst->age �ڼ�����ڲ��ᱻת��Ϊ(*pst).age
                    //ͨ��ʹ�õڶ��ַ�ʽ
    st.score = 20.2f;  //��һ�ַ�ʽ
    printf("%d %f\n", st.age, pst->score);
    return 0;
}
