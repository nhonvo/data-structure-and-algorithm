#include "MyFunctions.h"
#include <iostream>
using namespace std;
int a[1001], cnt, b[1001];
void henhiphand(int k)
{
	while (k > 0)
	{
		int t = k % 2;
		cnt++;
		a[cnt] = t;
		k /= 2;
	}
	for (int i = cnt; i >= 1; i--)
		cout << a[i];
}
void henhiphana(int k)
{
	while (k > 0)
	{
		int t = k % 2;
		cnt++;
		a[cnt] = t;
		k /= 2;
	}
	a[cnt + 1] = 0;
	for (int i = cnt + 1; i >= 1; i--)
	{
		if (a[i] == 0)
			a[i] = 1;
		else if (a[i] == 1)
			a[i] = 0;
	}
	b[1] = 1;
	for (int i = 1; i <= cnt + 1; i++)
	{
		if (a[i] == 0 && b[i] == 0)
			a[i] = 0;
		else if (a[i] == 0 && b[i] == 1)
			a[i] = 1;
		else if (a[i] == 1 && b[i] == 0)
			a[i] = 1;
		else if (a[i] == 1 && b[i] == 1)
		{
			a[i] = 0;
			a[i + 1] = 1;
		}
	}
	for (int i = cnt + 1; i >= 1; i--)
		cout << a[i];
}