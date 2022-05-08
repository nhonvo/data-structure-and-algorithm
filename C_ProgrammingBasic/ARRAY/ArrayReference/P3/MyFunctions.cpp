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
bool checkp(int b[], int m)
{
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (b[i] > 0)
			cnt++;
	}
	return (cnt != 0);
}
bool checkpall(int b[], int m)
{
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (b[i] > 0)
			cnt++;
	}
	return (cnt == m);
}
void hoandoi(int b[], int m)
{
	for (int i = 1; i <= m; i++)
	{
		if (!checkpall(b, m) && b[i] > 0)
			b[i] = -b[i];
	}
	for (int i = 1; i <= m; i++)
		cout << b[i] << endl;
}