#include <iostream>
using namespace std;
int main()
{
    const double pi(3.14159);  //定义符号变量pi  符号常量定义时要初始化
    int radius(0);   //定义变量， int表示变量是整数类型
    cout<<"Please enter the radius!\n";
    cin>>radius;    //从标准输入设备读入一个整数存入radius中
    cout<<"The radius is:"<<pi<<'\n';
    cout<<"Please enter a different radius!\n";
    cin>>radius;
    cout<<"Now the radius is changed to:"<<radius<<'\n';
    cout<<"Pi is still:"<<pi<<'\n';
    return 0;
}
