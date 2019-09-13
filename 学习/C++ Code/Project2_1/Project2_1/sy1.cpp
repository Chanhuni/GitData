// 求数据类型的长度
#include <iostream>
using namespace std;

int main()
{
	//cout << "The size of an int is:\t\t" << sizeof(int) << "  bytes.\n";
	//cout << "The size of an long is:\t\t" << sizeof(long) << "  bytes.\n";
	unsigned int x;
	unsigned int y = 100;
	unsigned int z = 50;
	x = y - z;
	cout << "Difference is:" << x;
	x = z - y;
	cout << "\n Now difference is:" << x;

	return 0;
}