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
	cout << "������һ�������¶ȣ�\n";
	cin >> F;
	cout << "ת��Ϊ�����¶��ǣ�\n";
	cout << Convert(F);
	return 0;
}