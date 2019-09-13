#include <iostream>
using namespace std;

int main(void)
{
	cout << "This size of an int is :\t" << sizeof(int) << "  byte!\n";
	cout << "This size of an int short :\t" << sizeof(short) << "  byte!\n";

	cout << "This size of an long is :\t" << sizeof(long) << "  byte!\n";
	cout << "This size of an char is :\t" << sizeof(char) << "  byte!\n";
	cout << "This size of an float is :\t" << sizeof(float) << "  byte!\n";
	cout << "按任意键继续……";

	cin.clear();

	cin.sync();

	cin.get();
	return 0;
}