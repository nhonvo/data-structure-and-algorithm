#include "MyFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;
int used[1001];
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
int dem_6(int b[], int m)
{
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int t = b[i] % 10;
		if (t == 6 && b[i] % 6 == 0)
			cnt++;
	}
	return cnt;
}
bool checksnt(int k)
{
	int c = 0;
	for (int i = 2; i < k; i++)
	{
		if (k % i == 0)
			c++;
	}
	if (k < 2) return false;
	return (c == 0);
}
double tbsnt(int b[], int m)
{
	double sum = 0;
	int dem = 0;
	for (int i = 1; i <= m; i++)
	{
		if (checksnt(b[i]))
		{
			sum += b[i];
			dem++;
		}
	}
	return (sum / dem);
}
void dempb(int b[], int m)
{
	int pb = 0;
	for (int i = 1; i <= m; i++)
	{
		if (checksnt(b[i]) && used[b[i]] == 0)
		{
			used[b[i]]++;
			pb++;
		}
	}
	cout << pb << endl;
}