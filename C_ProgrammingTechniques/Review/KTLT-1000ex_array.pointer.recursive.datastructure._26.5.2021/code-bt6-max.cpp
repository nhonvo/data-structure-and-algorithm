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
		printf("a[%d]=", i+1);
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
int maxl(int n,int a[]){
	int max=0;
	for(int i=0;i<n;i++){
		if (a[i]>max){
			max=a[i];
		}
	} 
	return max;
}
int main()
{
	int n, a[101];
	nhap(n, a);
	xuat(n, a);
	printf("%8.3d", maxl(n,a));
	return 0;
}
