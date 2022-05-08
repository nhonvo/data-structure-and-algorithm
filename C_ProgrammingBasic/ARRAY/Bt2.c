#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 100

int nhapMang(int n, int a[])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("Nhap a[%d]=", i);
		scanf("%d", &a[i]);
	}
}

int squareNumber(int n, int a[])
{
	int i, j, s = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (sqrt(a[i]) == j)
			{
				s += a[i];
			}
		}
	}
	printf("  %d  ", s);
}

bool isPrime(int m)
{
	int i;
	if (m < 2)
	{
		return false;
	}
	else
	{
		if (m % i == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int prime(int n, int a[])
{
	int i, cnt = 0, m;
	for (i = 1; i <= n; i++)
	{
		if (isPrime(a[i]))
		{
			cnt += a[i];
		}
	}
	return cnt;
}

int duongDx(int n, int a[10001])
{
	int i, j, s = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = n; j > 0; j--)
		{
			if (a[i] == a[j])
			{
				s += a[i];
			}
		}
	}
	printf("s=%d", s);
}

int main()
{
	int n, a[MAX_SIZE], cnt;
	printf("Nhap n=");
	scanf("%d", &n);
	nhapMang(n, a);
	prime(n, a);
	printf("tong cac so nguyen to snt=%d", cnt);
	return 0;
}
