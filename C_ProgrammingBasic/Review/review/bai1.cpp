#include <stdio.h>

void nhap(int &n, int &m, int a[][101])
{
	printf("Nhap n:");
	scanf("%d", &n);
	printf("Nhap m:");
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Nhap a[%d][%d]=", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
}
void xuat(int &n, int &m, int a[][101])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("\na[%d][%d]=%d", i + 1, j + 1, a[i][j]);
		}
	}
}

int tong(int n, int m, int a[][101])
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				s += a[i][j];
			}
		}
	}
	return s;
}
int main()
{
	int n, m, a[101][101];
	nhap(n, m, a);
	xuat(n, m, a);
	printf("\nTong duong cheo=%d", tong(n, m, a));
}
