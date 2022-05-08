#include <stdio.h>
#include <math.h>
#include <conio.h>

typedef struct phanso
{
	int tu;
	int mau;
} Ps;

void NhapPs(Ps &a)
{
	scanf("%d%d", &a.tu, &a.mau);
}
void XuatPs(Ps a)
{
	printf("\t %d/%d ", a.tu, a.mau);
}
int UCLN(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return a + b;
	}
	while (a * b != 0)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a + b;
}

Ps toigian(Ps &a)
{
	Ps c;
	c.tu = a.tu / UCLN(a.tu, a.mau);
	c.mau = a.mau / UCLN(a.tu, a.mau);
	return c;
}

void nhap(int n, Ps a[])
{
	int i = 0;
	while (i < n)
	{
		printf("Nhap phan so thu %d: ", i);
		NhapPs(a[i]);
		i++;
	}
}
void xuat(int n, Ps a[])
{
	int i = 0;
	printf("\nDay cac phan so la: ");
	while (i < n)
	{
		XuatPs(toigian(a[i]));
		i++;
	}
}
int timkiem(int n, Ps a[], float x)
{
	for (int i = 0; i < n; i++)
	{
		float u = a[i].tu / a[i].mau;
		if (x == u)
		{
			return i;
			printf("%d", i);
		}
	}
	return -1;
}

void swap(Ps &a, Ps &b)
{
	Ps c = a;
	a = b;
	b = c;
}
// sap xep chen
void insertionSort(int n, Ps a[])
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i].tu / a[i].mau;
		j = i - 1;

		while (j >= 0 && a[j].tu / a[j].mau > key)
		{
			float x = a[j + 1].tu / a[j + 1].mau;
			float y = a[j].tu / a[j].mau;
			x = y;
			j = j - 1;
		}
		float z = a[j + 1].tu / a[j + 1].mau;
		z = key;
	}
}
// sap xep nhanh

int partition(Ps a[], int left, int right)
{
	int i = left;
	int j = right - 1;
	int pivot = a[right].tu / a[right].mau;
	while (true)
	{
		while (pivot > a[i].tu / a[i].mau && i <= j)
			i++;
		while (pivot < a[j].tu / a[j].mau && i <= j)
			j--;
		if (i >= j)
		{
			break;
		}
		else
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	swap(a[i], a[right]);
	return i;
}
void quicksort(Ps a[], int left, int right)
{
	if (left <= right)
	{
		int pi = partition(a, left, right);
		quicksort(a, left, pi - 1);
		quicksort(a, pi + 1, right);
	}
}
int main()
{

	int n;
	Ps a[100];
	printf("\nNhap so luong phan so: ");
	scanf("%d", &n);
	nhap(n, a);
	xuat(n, a);
	float x;
	printf("\nNhap gia tri x can tim: ");
	scanf("%.2f", &x);
	int cau3 = timkiem(n, a, x);
	if (cau3 == -1)
	{
		printf("\nKhong tim thay.");
	}
	else
	{
		printf("Gia tri can tim nam o vi tri: %d", cau3);
	}
	insertionSort(n, a);
	quicksort(a, 0, n - 1);
	xuat(n, a);
}
