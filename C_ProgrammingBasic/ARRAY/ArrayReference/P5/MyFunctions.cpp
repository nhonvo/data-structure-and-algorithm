#include "MyFunctions.h"
#include <iostream>
using namespace std;
void nhapmang(float a[], int& n)
{
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
int dem(float b[], int m)
{
	int cnt = 0;
	for (int i = 1; i <= m;i++)
	{
		if (b[i] < 0)
			cnt++;
	}
	return cnt;
}