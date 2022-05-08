#include "MyFunctions.h"
#include <iostream>
#include<cmath>
using namespace std;
void nhapmang(int a[], int& n)
{
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
int Sump(int b[], int m)
{
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		if (b[i] >= 0)
		{
			sum += b[i];
		}
	}
	return sum;
}
int Sumdiv(int b[], int m)
{int i;
	int sdiv = 0;
	for ( i= 1; i <= m; i++)
	{
		if (b[i] % 3 == 0)
		{
			sdiv += b[i];
		}
	}
	return sdiv;
}
int sumodd(int b[], int m)
{int i;
	int sodd = 0;
	for ( i = 1; i <= m; i++)
	{
		int t = b[i];
		while (abs(b[i]) > 9)
		{
			b[i] = b[i] / 10;
		}
		if (b[i] % 2 != 0)
			sodd += t;
	}
	return sodd;
}
