#include <iostream>
using namespace std;
int main()
{
    const double pi(3.14159);  //������ű���pi  ���ų�������ʱҪ��ʼ��
    int radius(0);   //��������� int��ʾ��������������
    cout<<"Please enter the radius!\n";
    cin>>radius;    //�ӱ�׼�����豸����һ����������radius��
    cout<<"The radius is:"<<pi<<'\n';
    cout<<"Please enter a different radius!\n";
    cin>>radius;
    cout<<"Now the radius is changed to:"<<radius<<'\n';
    cout<<"Pi is still:"<<pi<<'\n';
    return 0;
}
