#include <stdio.h>

//ֻ������һ���������ͣ���û�ж�����������������͵������� enum WeekDay
enum WeekDay
{
    MonDay, TuseDay, WednesDay, ThursDay, FriDay, SaturDay, SunDay  //Ĭ�ϵ�һ��Ϊ0��Ҳ�����޸�����MonDay=4
};

int main (void)
{
    //int day;  //day�����int���Ͳ�����
    enum WeekDay day = SunDay;
    printf("%d\n", day);
    return 0;
}
