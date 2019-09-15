#include <iostream>
using namespace std;

int main()
{
	int number_of_pods, peas_per_pod, total_peas;
	double price = 7.54560000;
	cout.setf(ios::fixed);	
	cout.setf(ios::showpoint);
	cout.precision(2);	//这三句会使double按小数点后2位来输出
	cout << "Press return after entering a number.\n";
	cout << "Enter the number of pods:\n";
	cin >> number_of_pods;
	cout << "Enter the number of peas in apod:\n";
	cin >> peas_per_pod;
	total_peas = number_of_pods * peas_per_pod;
	cout << "If you have ";
	cout << number_of_pods;
	cout << " pea pods\n";
	cout << "and ";
	cout << peas_per_pod;
	cout << " peas in each pod, then\n";
	cout << "you have ";
	cout << total_peas;
	cout << " peas in all the pods.\n";
	cout << "\n\n";
	cout << "*******************************************\n\n";
	cout << "         c c c         s s s s        !!\n";
	cout << "       c       c     s         s      !!\n";
	cout << "      c             s                 !!\n";
	cout << "     c               s                !!\n";
	cout << "     c                 s s s s        !!\n";
	cout << "     c                         s      !!\n";
	cout << "      c                         s     !!\n";
	cout << "       c       c               s      !!\n";
	cout << "         c c c         s s s s        !!\n";
	cout << "*******************************************\n\n" << "\n\n";
	cout << R"(c:\files\)" << endl;	//输出结果是c:\files\ 
	cout << "The price is $" << price << endl;
	system("pause");
	return 0;
}