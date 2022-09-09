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
	printf("\nArray : \n");
	for (int i = 0; i < n; i++)
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
	void doantang_lt_longest(int a[], int n)
	{
		int dem = 1, i0 = 0, max = 1;
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
		printf("\nDoan tang lien tiep dai nhat:");
		for (int i = i0; i < i0 + max; i++)
		{
			printf("\t%d", a[i]);
		}
	}
int main()
{
	int a[100]; // a[0],a[1],...a[99]
	int n;
	printf("n =");
	scanf("%d", &n);

	Nhap_mang(a, n);

	Xuat_mang(a, n);

	doantang_lt_longest(a, n);

	printf("\nTong:%d", doantang_lt_summax(a, n));
	getch();
	return 0;
}
