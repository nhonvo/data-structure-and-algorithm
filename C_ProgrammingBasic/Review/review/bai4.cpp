#include <stdio.h>

void nhap(int &n, int a[])
{
	do
	{
		printf("Nhap n=");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
		{
			printf("Nhap sai. Nhap lai.\n");
		}
	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]=", i + 1);
		scanf("%d", &a[i]);
	}
}

int ktnt(int &n)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			dem++;
		}
	}
	if (dem == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return n;
}
void xuatnt(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (ktnt(a[i]) == 1)
		{
			printf("a[%d]=%d\n", i + 1, a[i]);
		}
	}
}
int vtxoa(int &n, int a[], int vitrixoa)
{
	for (int i = vitrixoa; i <= n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}

int vitrixoa(int &n, int a[], int vtx)
{
	for (int i = vtx; i <= n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}

void xuat(int &n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d]=%d", i + 1, a[i]);
	}
}

int main()
{
	int n, a[101], vtx;
	scanf("%d", &vtx);
	nhap(n, a);
	vitrixoa(n, a, vtx);
	xuat(n, a);
}
