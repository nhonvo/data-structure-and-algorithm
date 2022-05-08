#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhap(int &n, int *&a);
void xuat(int n, int *a);
void swap(int *pa, int *pb);
void sapxep(int n, int *a);

int main()
{
	int n, *a;
	a =(int*)malloc(101);

	nhap(n, a);
	xuat(n, a);	
	printf("\n");
	sapxep(n, a);
	xuat(n, a);
	return 0;
}

void nhap(int &n, int *&a)
{
	do
	{
		printf("Nhap n:");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
		{
			printf("ERROR\n");
		}
	} while (n <= 0 || n > 100);
	a = new int[100];
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", a + i);
	}
}

void xuat(int n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d", *(a + i));
	}
}
void sapxep(int n, int *a)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a+i) > *(a+j))
			{
				swap((a+i),(a+j));
			}
		}
	}
}
void swap(int *pa, int *pb){
	int tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}
