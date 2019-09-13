#include <iostream>
using namespace std;

class Clock {
public:
	Clock(int newH, int newM, int newS);   //构造函数
	Clock();  //默认构造函数
	void setTime(int newH = 0, int newM = 0, int nowS = 0);
	void showTime();
private:
	int hour, minute, second;
};

//默认构造函数
Clock::Clock() :hour(0), minute(0), second(0) {

}

//构造函数的实现
Clock::Clock(int newH, int newM, int newS) :
	hour(newH),minute(newM),second(newS){
}

//委托构造函数
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
	Clock c(8,10,0);	//自动调用有参数的构造函数
	Clock c2;   //调用无参数的构造函数
	c.showTime();
	c2.showTime();
	return 0;
}