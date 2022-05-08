#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

void nhapMang(int n, int a[])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("a[%d]:", i);
		scanf("%d", &a[i]);
	}
}

void mang(int n, int a[10001])
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

int dem(int n, int a[10001])
{
	int i, cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			cnt++;
		}
	}
	return cnt;
}

void tong(int n, int a[10001])
{
	int i, s = 0;
	printf("\ntong cua mang:");
	for (i = 1; i <= n; i++)
	{
		s += a[i];
	}
	return s;
}

float trungBinhCong(int n, int a[10001])
{
	int i, cnt = 0;
	float s = 0, tb;
	for (i = 1; i <= n; i++)
	{
		s += a[i];
		cnt++;
	}
	tb = s / cnt;
	return tb;
}

float trungBinhCongDuong(int n, int a[10001])
{
	int i, u = 0;
	float s = 0, tb;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			s += a[i];
			u++;
		}
	}
	tb = s / u;
	return tb;
}

bool ktnt(int n)
{
	int i;
	int cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0 && n > 2)
		{
			cnt++;
		}
	}
	if (cnt == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
	return n;
}

void xuatnt(int n, int a[10001])
{
	int i;
	printf("\nCac so nguyen to trong mang:");
	for (i = 1; i <= n; i++)
	{
		if (ktnt(a[i]))
		{
			printf("  %d  ", a[i]);
		}
	}
}

int demnt(int n, int a[10001])
{
	int i, cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (ktnt(a[i]))
		{
			cnt++;
		}
	}
	return cnt;
}

int tongnt(int n, int a[10001])
{
	int i, s = 0;
	for (i = 1; i <= n; i++)
	{
		if (ktnt(a[i]))
		{
			s += a[i];
		}
	}
	return s;
}

float tbcnt(int n, int a[10001])
{
	int i, tbc, s, cnt;
	for (i = 1; i <= n; i++)
	{
		if (ktnt(a[i]))
		{
			tbc = tongnt(n, a) / demnt(n, a);
		}
	}
	return tbc;
}

void ptuDuong(int n, int a[10001])
{
	int i;
	printf("\nPhan tu duong dau tien");

	for (i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			printf(" %d ", a[i]);
			return 0;
		}
	}
}

void ptuDuonglast(int n, int a[10001])
{
	int i;
	printf("\nPhan tu duong cuoi cung");
	for (i = n; i >= 0; i--)
	{
		if (a[i] > 0)
		{
			printf(" %d ", a[i]);
			return 0;
		}
	}
}

int Max(int n, int a[])
{
	int i, max = a[0];
	for (i = 1; i <= n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}
int Min(int n, int a[])
{
	int i, min = a[0];
	for (i = 1; i <= n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}
int main()
{
	int n, a[10001];
	do
	{
		printf("Enter N:");
		scanf("%d", &n);
		if (n <= 0 || n > 10)
		{
			printf("Nhap sai");
		}
	} while (n <= 0 || n > 10);

	nhapMang(n, a);
	mang(n, a); // chia het 3
	printf("\nSo cac phan tu duong:");
	printf("%d", dem(n, a));
	printf("\nTrung binh cong cua mang:");
	printf("%f", trungBinhCong(n, a));
	printf("\nTrung binh cong ptu duong cua mang:");
	printf("%f", trungBinhCongDuong(n, a));
	xuatnt(n, a);
	printf("\nSo cac phan tu nt co trong mang:%d", demnt(n, a));
	printf("\nTong cac so nguyen to co trong mang:%d", tongnt(n, a));
	printf("\nTrung binh cong cac so nguyen to co trong mang:%f", tbcnt(n, a));
	ptuDuong(n, a);
	ptuDuonglast(n, a);
	printf("\nPhan tu lon nhat:%d", Max(n, a));
	printf("\nPhan tu lon nhat:%d", Min(n, a));
}
