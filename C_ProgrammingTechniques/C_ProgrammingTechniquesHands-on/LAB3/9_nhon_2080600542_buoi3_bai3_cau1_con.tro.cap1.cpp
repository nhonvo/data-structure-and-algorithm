#include <stdio.h>
#include <stdlib.h>

void Nhap(int *a, int n){
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
}

void Xuat(int *a, int n){
    printf("\n----------------\n");
    for(int i=0;i<n;i++)
        printf("%d ",*(a+i));
}
int tong(int *a, int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=*(a+i);
	return sum;
}
int main()
{
    int *a, n;
    printf("n = ");
    scanf("%d",&n);
    a= (int*)malloc(n*sizeof(int));
  	Nhap(a,n);
  	Xuat(a,n);
  	printf("\nTong:%d",tong(a,n));
	return 0;
}
	
