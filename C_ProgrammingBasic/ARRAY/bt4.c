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

bool doiXung(int n, int a[])
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = n; j <= n; j--)
		{
			if (a[i] == a[j])
			{
				printf("ham doi xung");
				return true;
			}
			return false;
		}
	}
}

bool amDuong(int n, int a[])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] * a[i + 1] < 0)
		{
			printf("Mang dan xen am duong");
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool different(int n, int a[])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] != a[i + 1])
		{
			printf("true");
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool CSC(int n, int a[])
{
	int i;
	for (i = 1; i <= n; i++)
	{

		if ((a[i] + a[i + 2]) == a[i + 1] * 2)
		{
			printf("mang la cap so cong");
			return true;
		}
		else
		{
			return false;
		}
	}
}
int soAm(int n, int a[])
{
	int i, cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] < 0)
			cnt++;
	}
	printf("so so am=%d", cnt);
}

int nhiPhan(int n)
{

	printf("n=%s", n);
}
int main()
{
	int n, a[MAX_SIZE];
	printf("Nhap n=");
	scanf("%d", &n);
	//	nhapMang(n,a);
	nhiPhan(n);
	return 0;
}
