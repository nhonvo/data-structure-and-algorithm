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
int linearsearch(int n, int a[], int key){
	int i,j,vt=-1;
	for( i=0;i<n;i++){
		if(a[i]==key){
			vt=i;			
		}
	}
	if(vt==-1){
		return -1;
	}else{
		return vt;
	}
}

int main()
{
	int n, a[101];
	nhap(n, a);
	xuat(n, a);
	int key;
	printf("\nNhap so can tim:");
	scanf("%d", &key);
	printf("\nVi tri so can tim:\t%d",linearsearch(n,a,key));
	
}
