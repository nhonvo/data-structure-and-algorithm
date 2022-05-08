#include <stdio.h>

int nhapMang(int a[100], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
}

int xuatMang(int a[100], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("a[%d]=%d", i, a[i]);
	}
}

int main()
{
	int n;
	int a[100];
	printf("n:");
	scanf("%d", &n);
	nhapMang(a, n);
	xuatMang(a, n);
	return 0;
}
