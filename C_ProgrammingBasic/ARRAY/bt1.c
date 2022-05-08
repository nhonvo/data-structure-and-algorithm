#include <stdio.h>
#include <math.h>

int nhapMang(int n, int a[10001])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("Nhap a[%d]=", i);
		scanf("%d", &a[i]);
	}
}

int arrayactive(int n, int a[10001])
{
	int i, s = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			s += a[i];
		}
	}
	printf("%d", s);
}
int divthree(int n, int a[10001])
{
	int i, s = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] % 3 == 0)
		{
			s += a[i];
		}
	}
	printf("\n%d", s);
}
int sumodd(int n, int a[10001])
{
	int i, s = 0, u;
	for (i = 1; i <= n; i++)
	{
		if (abs(a[i]) > 9)
			u = a[i] / 10;
		if (u % 2 != 0)
		{
			s += a[i];
		}
	}
	printf("\n%d", s);
}
int main()
{
	int n, a[10001];
	printf("Nhap n=");
	scanf("%d", &n);
	nhapMang(n, a);
	sumodd(n, a);

	//	divthree(n,a);//arrayactive(n,a);
}
