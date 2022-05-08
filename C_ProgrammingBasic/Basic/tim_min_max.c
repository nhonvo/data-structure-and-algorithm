#include<stdio.h>


int minMax(int n, int a[1000000])
{
	int max=a[1];
	int min=a[1];
	int i;
		for(i=1; i<=n; i++){
			
			if(a[i]<max)
			{
				max=a[i];//tinh
			}
			if(a[i]>min)
			{
				min=a[i];
			}
		}
	printf("max is:%d\n", max);
	printf("min is:%d", min);
}
int main(){
	int n,a[1000],i;	
	printf("Nhap so pt n:");
	scanf("%d", &n);

	for(i=1;i<=n;i++){
		printf("cac so phan tu a[%d]=", i);		
		scanf("%d", &a[i]);
	}//nhap
	minMax(n, a);	
	return 0;
}

