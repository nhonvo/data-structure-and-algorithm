#include "MyFunctions.h"
#include <iostream>
#include <cmath>
using namespace std;
int r[1001];
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
int sumcp(int b[], int m)
{
	int scp = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int k = 1; k <= b[i]; k++)
		{
			if (sqrt(b[i]) == k)
			{
				scp += b[i];
				break;
			}
		}
	}
	return scp;
}
bool checkshc(int q)
{
	int s = 0;
	for (int i = 1; i < q; i++)
	{
		if (q % i == 0)
		{
			s += i;
		}
	}
	return (s == q);
}
int sumhc(int b[], int m)
{
	int shc = 0;
	for (int i = 1; i <= m; i++)
	{
		if (checkshc(b[i]))
			shc += b[i];
	}
	return shc;
}
bool checksnt(int k)
{
	int cnt = 0;
	if (k < 2) return false;
	for (int i = 2; i < k; i++)
	{
		if (k % i == 0)
		{
			cnt++;
		}
	}
	return (cnt == 0);
}
int sumsnt(int b[], int m)
{
	int snt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (checksnt(b[i]))
		{
			snt += b[i];
		}
	}
	return snt;
}
bool checksdx(int e)
{
	int c = 0;
	while (e > 0)
	{
		int t = e % 10;
		c++;
		r[c] = t;
		e = e / 10;
	}
	int i = 1;
	int j = c;
	while (i <= j)
	{
		if (r[i] != r[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int sumdx(int b[], int m)
{
	int sdx = 0;
	for (int i = 1; i <= m;i++)
	{
		if (checksdx(b[i]) && b[i] > 0)
			sdx += b[i];
	}
	return sdx;
}