#include <stdio.h>
#include <math.h>
#include <conio.h>

void Nhap_mang(int a[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
//------------------------------
void Xuat_mang(int a[100], int n)
{
	printf("\nMang a la: \n");
	for (int i = 0; i < n; i++)
		printf("\t%d", a[i]);
}

// xem lai maxchan v minle
int maxchan(int a[], int n)
{
	int max = -1;
	int i;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			max = a[i];
		}
	}
	for (int j = i + 1; j < n; j++)
	{
		if (a[j] % 2 == 0 && a[j] > max)
		{
			max = a[j];
		}
	}
	return max;
}
int minle(int a[], int n)
{
	int max = -1;
	int i;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			max = a[i];
		}
	}
	for (int j = i + 1; j < n; j++)
	{
		if (a[j] % 2 != 0 && a[j] < max)
		{
			max = a[j];
		}
	}
	return max;
}

bool checknt(int n)
{
	int dem = 0;
	if (n < 2)
	{
		return false;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				dem++;
			}
		}
		if (dem == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void nguyento(int a[], int n)
{
	int i, cnt = 0, m;
	printf("\nSo nguyen to:");
	for (i = 0; i < n; i++)
	{
		if (checknt(a[i]))
		{
			printf("\t%d", a[i]);
		}
	}
}
bool checkchinhphuong(int n)
{
	int m = sqrt(n);
	if (n == m * m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void chinhphuong(int a[], int n)
{
	int i, cnt = 0, m;
	printf("\nSo chinh phuong:");
	for (i = 1; i < n; i++)
	{

		if (checkchinhphuong(a[i]))
		{
			printf("\t%d", a[i]);
		}
	}
}

int lonnhat(int a[], int n)
{
	int max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}
int nhonhat(int a[], int n)
{
	int max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (max > a[i])
		{
			max = a[i];
		}
	}
	return max;
}
int hieumin(int a[], int n)
{
	int s1 = lonnhat(a, n), s2 = nhonhat(a, n);
	printf("\nHai so tru vs nhau duoc ket qua nho nhat:");
	printf("\t%d\t%d", s1, s2);
}

int tichmax(int a[], int n)
{
	int max = a[0];
	int s1, s2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] * a[j] > max)
			{

				max = a[i] * a[j];
				s1 = a[i];
				s2 = a[j];
			}
		}
	}
	printf("\nHai so nhan vs nhau duoc ket qua lon nhat:");
	printf("\t%d\t%d", s1, s2);
}

int swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int sapxepchangiamdangiuanguyenle(int a[], int n)
{ // giam dan -chan
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] % 2 == 0 && a[i] < a[j])
				{
					swap(a[i], a[j]);
				}
			}
		}
	}
}

int sapxeplegiuanguyenchan(int a[], int n)
{ // tang dan -le
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] % 2 != 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] % 2 != 0 && a[i] > a[j])
				{
					swap(a[i], a[j]);
				}
			}
		}
	}
}
void doantang_lt_longest(int a[], int n)
{
	int dem = 1, max = 1, i0 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
		{
			dem++;
		}
		else
		{
			if (dem > max)
			{
				max = dem;
				i0 = i - dem + 1;
			}
			dem = 1;
		}
	}
	printf("\nDoan tang dai nhat la:\n");
	for (int i = i0; i < i0 + max; i++)
		printf("\t%d", a[i]);
}

// co 3 ve: ve 1 sum +=a[i]; ve 2 xet dk sum>sum_max gan lai gtri max; ve 3 xe dk dau 2 so cong voi nhau <0
int doantang_lt_summax(int a[], int n)
{
	int sum = 0, sum_max = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + sum_max < 0)
		{
			sum = 0;
		}
		else
		{
			sum = sum + a[i];
		}
		if (sum > sum_max)
		{
			sum_max = sum;
		}
		sum = sum + a[i];
		if (sum > sum_max)
		{
			sum = sum_max;
		}
		if (sum < 0)
		{
			sum = 0;
		}
	}
	return sum_max;
}

/*
		 0	1 2 3  4 5 6  7
		-1 -2 6 1 -5 3 5 -5
		 0  0 6 7 -2 1 6 end
		-1+0=>sum=0
		-2+0=>sum =0
		6+1 >0 => 7
		7+(-5)=>2
		2+3=>5
		5+5
*/

int main()
{
	int a[100]; // a[0],a[1],...a[99]
	int n;
	printf("n =");
	scanf("%d", &n);

	Nhap_mang(a, n);

	Xuat_mang(a, n);

	chinhphuong(a, n);
	nguyento(a, n);

	maxchan(a, n);

	int max = maxchan(a, n);
	printf("\nChan lon nhat:%d", max);
	int min = minle(a, n);
	printf("\nLe nho nhat:%d", min);

	tichmax(a, n);
	hieumin(a, n);

	doantang_lt_longest(a, n);
	printf("\nDoan tang lien tiep tong lon nhat:%d", doantang_lt_summax(a, n));

	printf("\nSap xep cac so le tang dan:");
	sapxeplegiuanguyenchan(a, n);
	Xuat_mang(a, n);
	printf("\nSap xep cac so chan giam dan:");
	sapxepchangiamdangiuanguyenle(a, n);
	Xuat_mang(a, n);

	getch();
	return 0;
}
