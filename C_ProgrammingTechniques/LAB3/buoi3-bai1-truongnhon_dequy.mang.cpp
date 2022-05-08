#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

int *c,n,*a;

int nhap(int *c, int n){
	for (int i = 0; i < n; i++)
		scanf("%d", c + i);
}


int xuat(int *c, int n){
	printf("\nMang da nhap là:");
    for(int i=0;i<n;i++)
        printf("\t%d ", *(c+i));
}

int maxchan(int *a, int n)
{
	int max = -1;
	int i;
	for (int i = 0; i < n; i++)
	{
		if(*(a+i) %2==0){
			max = *(a+i);
			break;
		}
	}
	for (int j=i+1;j<n;j++){
		if((*(a+j) %2 ==0 &&  *(a+j)>max)){
			max =*(a+j);
				break;
		}
	}
	return max;
}


int minle(int *a, int n)
{
	int min = -1;//fix fixx
	int i;
	for (int i = 0; i < n; i++)	{
		if(*(a+i) %2!=0){
			min = *(a+i);
//			break;
		}
	}
	for (int j=i+1;j<n;j++){
		if((*(a+j) %2 !=0&& *(a+j)<min)){
			min =*(a+j);
		}
	}
	return min;
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

void nguyento(int *c, int n)
{
	int i, cnt = 0, m;
	printf("\nSo nguyen to:");
	for (i = 0; i < n; i++)
	{
		if (checknt(*(c+i)))
		{
			printf("\t%d", *(c+i));
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

void chinhphuong(int *c, int n)
{
	int i, cnt = 0, m;
	printf("\nSo chinh phuong:");
	for (i = 1; i < n; i++)
	{

		if (checkchinhphuong(*(c+i)))
		{
			printf("\t%d", *(c+i));
		}
	}
}

int lonnhat(int *a, int n)
{
	int max = *(a+0);

	for (int i = 1; i < n; i++)
	{
		if (max < *(a+i))
		{
			max = *(a+i);
		}
	}
	return max;
}

int nhonhat(int *a, int n)
{
	int min = *(a+0);

	for (int i = 1; i < n; i++)
	{
		if (min > *(a+i))
		{
			min = *(a+i);
		}
	}
	return min;
}

int hieumin(int *a, int n)
{
	int s1 = lonnhat(a, n), s2 = nhonhat(a, n);
	printf("\nHai so tru vs nhau duoc ket qua nho nhat:");
	printf("\t%d\t%d", s1, s2);
}

int tichmax(int *a, int n)
{
	int max = *(a+0);
	int s1, s2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a+i) * *(a+j) > max)
			{

				max = *(a+i) * *(a+j);
				s1 = *(a+i);
				s2 = *( a+j);
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
int sapxepchangiamdangiuanguyenle(int *a, int n)
{ //giam dan -chan
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (*(a+j) % 2 == 0 && *(a+i) < *(a+j))
				{
					swap(*(a+i), *(a+j));
				}
			}
		}
	}
}

int sapxeplegiuanguyenchan(int *a, int n)
{ //tang dan -le
	for (int i = 0; i < n - 1; i++)
	{
		if (*(a+i) % 2 != 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (*(a+j) % 2 != 0 && *(a+i) > *(a+j))
				{
					swap(*(a+i), *(a+j));
				}
			}
		}
	}
}

void doantang_lt_longest(int *a, int n)
{
	int dem = 1, max = 1, i0 = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) < *(a+i+1))
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
		printf("\t%d", *(a+i));
}

int doantang_lt_summax(int *a, int n)
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
			sum = sum + *(a+i);
		}
		if (sum > sum_max)
		{
			sum_max = sum;
		}
		sum = sum + *(a+i);
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


int main()
{
    printf("n = ");
    scanf("%d", &n);
    c = (int *)malloc(n * sizeof(int));
    nhap(c,n);
    xuat(c,n);
    
	
	

	int max = maxchan(c, n);
	printf("\nChan lon nhat:%d", max);
	int min = minle(c, n);
	printf("\nLe nho nhat:%d", min);

	nguyento(c,n);
	chinhphuong(c,n);
	tichmax(c, n);
	hieumin(c, n);

	doantang_lt_longest(c, n);
	printf("\nDoan tang lien tiep tong lon nhat:%d", doantang_lt_summax(c, n));

	printf("\n\tSap xep cac so le tang dan");
	sapxeplegiuanguyenchan(c, n);
	xuat(c, n);
	printf("\n\tSap xep cac so chan giam dan");
	sapxepchangiamdangiuanguyenle(c, n);
	xuat(c, n);
	
	getch();
    return 0;
}
