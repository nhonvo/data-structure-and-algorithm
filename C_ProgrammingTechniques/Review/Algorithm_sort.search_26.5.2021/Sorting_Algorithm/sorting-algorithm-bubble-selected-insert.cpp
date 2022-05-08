#include <stdio.h>
#include <conio.h>
#define MAX 101

void swap(int &xp, int &yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}
void nhap(int &n, int a[])
{
	do
	{
		printf("Nhap N=");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
		{
			printf("Error.Enter again.");
		}

	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i + 1);
		scanf("%d", &a[i]);
	}
}

void xuat(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%d", a[i]);
	}
}
void bubblesort(int n, int a[])
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
void selectionsort(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		int min_dx = i;//gan min_dx bat ky
		for (int j = i + 1; j < n; j++)
		{
			if(a[j]<a[min_dx]){
				min_dx=j;//xac dinh vi tri ptu nho nhat va gan min_dx cho j
			}
			swap(a[min_dx],a[i]);//doi cho vt pt nho nhat 
		}
	}
}
void insertionSort(int n, int a[])
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = a[i];
       j = i-1;

       while (j >= 0 && a[j] > key)//tai sao j phai >=0---j la so ptu cua mang moi va no >=0
       {
           a[j+1] = a[j];
           j = j-1;//có y nghia gi??? -- neu khong chay vong lap while thi a[i] dc luu vao bien key dc gan tro lai bang chinh no
       }
       a[j+1] = key;
   }
}


int main()
{
	int n, a[MAX];
	nhap(n, a);
	insertsort(n, a);
	xuat(n, a);
	return 0;
}
