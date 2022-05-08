#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 100

int nhapMang(int n, int a[])
{
	int i;
	{
		for (i = 1; i <= n; i++)
		{
			printf("Nhap a[%d]=", i);
			scanf("%d", &a[i]);
		}
	}
}
int dem(int n, int a[])
{
	int i, s, cnt = 0;
	for (i = 1; i <= n; i++)
	{
		s = a[i] % 10;
		a[i] = a[i] / 10;
		if (s == 6 && a[i] % 6 == 0)
			cnt++;
	}
	return cnt;
}
int main()
{
	int n, a[MAX_SIZE];
	do
	{
		printf("Nhap n=");
		scanf("%d", &n);
		if (n < 1 || n > 15)
			printf("nhap lai.");
	} while (n < 1 || n > 15);

	nhapMang(n, a);

	printf("%d", dem(n, a));
	return 0;
}
