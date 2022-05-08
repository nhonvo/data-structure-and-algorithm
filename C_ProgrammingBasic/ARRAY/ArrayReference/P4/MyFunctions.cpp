#include "MyFunctions.h"
#include <iostream>
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
bool checkdx(int b[], int m)
{
	int i = 1;
	int j = m;
	while (i <= j)
	{
		if (b[i] != b[j])
			return false;
		i++;
		j--;
	}
	return true;
}
bool checknp(int b[], int m)
{
	for (int i = 1; i < m; i++)
	{
		if (b[i] * b[i + 1] > 0)
			return false;
	}
	return true;
}
bool check(int b[], int m)
{
	for (int i = 1; i <= m; i++)
	{
		if (b[i] == b[i + 1])
			return false;
	}
	return true;
}
bool checkcsc(int b[], int m)
{
	for (int i = 2; i < m; i++)
	{
		if (b[i - 1] + b[i + 1] != b[i] * 2)
			return false;
	}
	return true;
}