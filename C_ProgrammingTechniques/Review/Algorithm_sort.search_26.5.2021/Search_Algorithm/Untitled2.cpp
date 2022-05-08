#include <stdio.h>

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
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
}
void xuat(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%d",a[i]);
	}
}
int binarysearch(int n, int a[], int key){
	
	int left = 0, right =n - 1;
	int mid;
	int vt=-1;
	
	while(left <= right){
	mid =(right + left)/2 ;
		if(a[mid] == key){
			return mid;
		}else if(a[mid] > key){
			right =mid -1;
		}else{
			left =mid +1;
		}
	}
	return -1;
}

int main()
{
	int n, a[101];
	nhap(n, a);
	xuat(n, a);
	int key;
	printf("\nNhap so can tim:");
	scanf("%d", &key);
	printf("\nVi tri so can tim:\t%d",binarysearch(n,a,key));
	
}
