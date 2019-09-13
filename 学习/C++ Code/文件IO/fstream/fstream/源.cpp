#include <fstream>
#include <iostream>
#include <cstdlib>

int main()
{
	using namespace std;
	ifstream in_stream;
	ofstream out_stream;

	in_stream.open("infile.dat");	//位置和源文件在一个目录
	if (in_stream.fail())
	{
		cout << "Input file opening failed.\n";
		//exit(1);		//实参1表示因为一个错误而调用exit(),否则使用实参0
	}
	out_stream.open("outfile.txt",ios::app);	//采用追加的方式,位置和源文件在一个目录
	//if (out_stream.fail)
	//{
	//	cout << "Output file opening failed.\n";
	//	//exit(1);
	//}
	int first, second, third;
	in_stream >> first >> second >> third;
	out_stream << "The sum of the frist 3\n" << "numbers in infile.dat\n"
		<< "is " << (first + second + third)
		<< endl;
	in_stream.close();
	out_stream.close();

	system("pause");

	return 0;
}