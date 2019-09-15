#include<stdio.h>

enum WeekDay
{
    MonDay, TuesDay, WednesDay, ThurDay, FriDay, SaturDay, SunDay
};

void f(enum WeekDay i)
{
    switch (i)
    {
    case 0:
        printf("MonDay!\n");
        break;
    case 1:
        printf("TuesDay!\n");
        break;
    case 2:
        printf("WednesDay!\n");
        break;
    case 3:
        printf("ThursDay!\n");
        break;
    case 4:
        printf("FriDay!\n");
        break;
    case 5:
        printf("SaturDay!\n");
        break;
    case 6:
        printf("SunDay!\n");
        break;
    }
}

int main(void)
{
    f(FriDay);

    return 0;
}

