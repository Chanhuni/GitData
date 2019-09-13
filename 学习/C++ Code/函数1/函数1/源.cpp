#include <iostream>
using namespace std;

float Convert(float F)
{
	float C;
	C = (F - 32) * 5 / 9;
	return C;
}

int main() {
	float F;
	cout << "请输入一个华氏温度：\n";
	cin >> F;
	cout << "转化为摄氏温度是：\n";
	cout << Convert(F);
	return 0;
}