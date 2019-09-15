#include<stdio.h>

enum WeekDay
{
    MonDay=1, TuesDay, WednesDay, ThurDay, FriDay, SaturDay, SunDay
};

int main(void)
{
    enum WeekDay day = WednesDay;
    printf("%d\n", day);

    return 0;
}
