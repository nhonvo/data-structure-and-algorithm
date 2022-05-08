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
bool checkActive(int n, int a[])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			printf("true");
			return true;
		}
		else
		{
			printf("false");
			return false;
		}
	}
}

int bothActive(int n, int a[])
{
	int i, j, cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			cnt++;
		}
	}
	if (cnt == n)
	{
		printf("Day toan duong");
	}
	else
	{
		for (j = 1; j <= n; j++)
		{
			if (a[j] > 0)
			{
				a[j] = -a[j];
			}
			printf("a[%d]=%d\t", j, a[j]);
		}
	}
}

int main()
{
	int n, a[MAX_SIZE];
	printf("Nhap n=");
	scanf("%d", &n);
	nhapMang(n, a);
	bothActive(n, a);
	return 0;
}
