#include <stdio.h>

//只定义了一个数据类型，并没有定义变量，该数据类型的名字是 enum WeekDay
enum WeekDay
{
    MonDay, TuseDay, WednesDay, ThursDay, FriDay, SaturDay, SunDay  //默认第一个为0，也可以修改例如MonDay=4
};

int main (void)
{
    //int day;  //day定义成int类型不合适
    enum WeekDay day = SunDay;
    printf("%d\n", day);
    return 0;
}
