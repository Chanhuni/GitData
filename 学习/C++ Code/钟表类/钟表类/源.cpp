#include <iostream>
using namespace std;

class Clock {
public:
	Clock(int newH, int newM, int newS);   //���캯��
	Clock();  //Ĭ�Ϲ��캯��
	void setTime(int newH = 0, int newM = 0, int nowS = 0);
	void showTime();
private:
	int hour, minute, second;
};

//Ĭ�Ϲ��캯��
Clock::Clock() :hour(0), minute(0), second(0) {

}

//���캯����ʵ��
Clock::Clock(int newH, int newM, int newS) :
	hour(newH),minute(newM),second(newS){
}

//ί�й��캯��
Clock::Clock():Clock(0,0,0){}

void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second;
}

int main() {
	//Clock myClock;
	//myClock.setTime(8,30,30);
	//myClock.showTime();
	Clock c(8,10,0);	//�Զ������в����Ĺ��캯��
	Clock c2;   //�����޲����Ĺ��캯��
	c.showTime();
	c2.showTime();
	return 0;
}