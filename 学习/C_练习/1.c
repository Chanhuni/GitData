#include <stdio.h>

struct Student
{
    int age;
    char sex;
    char name[20];
};

int main(void)
{
    struct Student st = {20, 'F', "Ð¡¾ê"};

    printf("%d %c %s\n", st.age, st.sex, st.name);

    struct Student *pst = &st;
    printf("%d %c %s\n", pst->age, pst->sex, pst->name);

    return 0;
}
