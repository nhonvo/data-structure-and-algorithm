#include "MyFunctions.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Nhap so nguyen n = ";
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	else if (n > 0)
	{
		henhiphand(n);
	}
	else if (n < 0) 
	{
		henhiphana(-n);
	}
}