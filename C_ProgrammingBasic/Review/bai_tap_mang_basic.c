#include <stdio.h>
#include <conio.h>

int nhapMang(int n, int a[100001])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("a[%d]:", i);
		scanf("%d", &a[i]);
	}
}

int mang(int a[10001], int n)
{
	int i;
	printf("Cac so chia het cho 3:");
	for (i = 1; i <= n; i++)
	{
		if (a[i] % 3 == 0)
		{
			printf("%d ", a[i]);
		}
	}
}

int dem(int a[10001], int n)
{
	int i, s = 0;
	printf("\nSo cac phan tu duong:");
	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
			s++;
	}
	printf("%d", s);
}

int tong(int a[10001], int n)
{
	int i, s = 0;
	printf("\ntong cua mang:");
	for (i = 1; i <= n; i++)
	{
		s += a[i];
	}
	printf("%d", s);
}

int trungBinhCong(int a[10001], int n)
{
	int i;
	float s = 0;
	printf("\nTrung binh cong cua mang:");
	for (i = 1; i <= n; i++)
	{
		s += a[i];
	}
	s = s / n;
	printf("%f", s);
}

int trungBinhCongDuong(int a[10001], int n)
{
	int i, u = 0;
	float s = 0;
	printf("\nTrung binh cong ptu duong cua mang:");

	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			s += a[i];
			u++;
		}
	}
	s /= u;
	printf("%f", s);
}

int ptuDuong(int a[10001], int n)
{
	int i;
	printf("phan tu duong dau tien");

	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			printf(" %d ", a[i]);
			return 0;
		}
	}
}

int ptuDuonglast(int a[10001], int n)
{
	int i;
	printf("phan tu duong cuoi cung");
	for (i = n; i >= 0; i--)
	{
		if (a[i] > 0)
		{
			printf(" %d ", a[i]);
			return 0;
		}
	}
}

int XuatMang(int a[100001], int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		printf("  %d  ", a[i]);
	}
}

int Max(int a[10001], int n)
{
	int i, max = 0;

	for (i = 1; i <= n; i++)
	{
		if (a[i] >= max)
			max = a[i];
	} // max
	printf("max= %d", max);
}
int Min(int a[10001], int n)
{
	int i;
	int min;
	for (i = 1; i <= n; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	printf("min= %d", min);
}
int main()
{
	int n, a[10001];
	printf("Enter N:");
	scanf("%d", &n);
	nhapMang(n, a);

	mang(a, n);
	dem(a, n);
	tong(a, n);
	trungBinhCong(a, n);
	trungBinhCongDuong(a, n);
	nt(a, n);
	Min(a, n);
	ptuDuonglast(a, n);
	return 0;
}
