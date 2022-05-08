#include <stdio.h>
#include <stdbool.h>

void nhap(int n)
{
	printf("Nhap n=");
	scanf("%d", &n);
}
bool ktsht(int m)
{
	int i, s = 0;
	for (i = 1; i <= (m / 2); i++)
	{
		if (m % i == 0)
		{
			s += i;
		}
	}
	if (s == m)
	{
		return true;
	}
	else
	{
		return false;
	}
	return m;
}

void ht(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (ktsht(i))
		{
			printf(" %d  ", i);
		}
	}
}
int main()
{
	int n;
	printf("Nhap n=");
	scanf("%d", &n);
	ht(n);
}
