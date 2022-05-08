#include "MyFunctions.h"
#include <iostream>
using namespace std;
int used[101], c[101], past[101];
void nhapmang(int a[], int b[], int& n, int& m)
{
	cout << "Nhap so luong phan tu day A :";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << " a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "Nhap so luong phan tu day B :";
	cin >> m;
	for (int j = 1; j <= m; j++)
	{
		cout << " b[" << j << "] = ";
		cin >> b[j];
	}
}
void xuatpt(int a[], int b[], int& n, int& m)
{
	cout << "Phan tu co trong A ma khong co trong B : ";
	for (int i = 1; i <= m; i++)
	{
		used[b[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (used[a[i]] == 0)
			cout << a[i] << ' ';
	}
}
void day_c(int a[], int b[], int& n, int& m)
{
	cout << "Day C : ";
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (past[a[i]] == 0)
		{
			past[a[i]]++;
			k++;
			c[k] = a[i];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (past[b[i]] == 0)
		{
			past[b[i]]++;
			k++;
			c[k] = b[i];
		}
	}
	for (int i = 1; i <= k; i++)
		cout << c[i] << ' ';
}