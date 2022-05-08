#include<stdio.h>

void nhap(int &n, int a[]){
	do{
	printf("Nhap n="); scanf("%d", &n);
		if(n<=0||n>100){
			printf("Nhap sai. Nhap lai.\n");
		}
	}while(n<=0||n>100);
	for(int i=0;i<n;i++){
		printf("Nhap a[%d]=",i+1); scanf("%d", &a[i]);
	}
}
void xuat(int &n, int a[]){
	for(int i=0;i<n;i++){
		printf("\na[%d]=%d",i+1, a[i]);
	}
}
int tang(int n, int a[]){
	int tmp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}

int main(){
	int n, a[101];
	nhap(n,a);
	tang(n,a);
	
	xuat(n,a);	
}
