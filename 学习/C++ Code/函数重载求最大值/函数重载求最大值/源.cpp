//float数输出有问题

#include <iostream>
#include <cmath>
using namespace std;

int max1(int x, int y);
int max1(int x, int y, int z);
float max(float x, float y);
float max(float x, float y,float z);

int main() {
	int a, b, c;
	double m, n, l;

	cout << "Enter int a:";
	cin  >> a;

	cout << "Enter int b:";
	cin >> b;

	cout << "Enter int c:";
	cin >> c;

	cout << "\n";

	cout << "Max of " << a << "and" << b << "is" << max1(a, b) << endl;
	cout << "Max of " << a << "," << b << "and" << c << "is" << max1(a, b,c) << endl;
	cout << "\n\n";

	cout << "Enter float m:";
	cin >> m;

	cout << "Enter float n:";
	cin >> n;

	cout << "Enter float l:";
	cin >> l;

	cout << "Max of " << m << "and" << n << "is" << max1(n, m) << endl;
	cout << "Max of " << m << "," << n << "and" << l << "is" << max1(m, n, l) << endl;

	return 0;
}

int max1(int x, int y) {
	if (x == y)return x;
	else if (x > y)
		return x;
	else
		return y;
}

int max1(int x, int y, int z) {
	return max1(max(x, y), z);
}

float max(float x, float y) {
	if (fabs(x - y) < 1e-10)return x;//判断两个浮点数是否相等的常见处理方式
	else if (x >= y)
		return x;
	else
		return y;
}

float max(float x, float y, float z) {
	return max1(max(x, y), z);
}