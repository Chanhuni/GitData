#include<stdio.h>

struct Student
{
    int age;
    char sex;
    char name[100];
};  //�ֺŲ���ʡ


int main (void)
{
    struct Student st = {20, 'F', "С��"};
    struct Student * pst = &st;

    printf("%d %c %s\n", st.age, st.sex, st.name);
    printf("%d %c %s\n", pst->age, pst->sex, pst->name);
    return 0;
}

/*
---------------------------
��CodeBlocks�����еĽ���ǣ�
20 F С��
20 F С��

Process returned 0 (0x0)   execution time : 0.272 s
Press any key to continue.

---------------------------
*/
