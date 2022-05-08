#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<math.h>

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

bool ktcp(int &n){
	int sqr=sqrt(n);
	if(n==sqr*sqr){
		return true;
		printf("TRue");
	}
	else{
		printf(" FALse ");
		return false;
	}
	return n;
}

int chinhphuong(int n, int a[]){
	int dem=0, s=0;
	for(int i=0;i<n;i++){
		if(ktcp(a[i])==1){
			s+=a[i];
			dem++;
		}
		ktcp(a[i]);
	}
	float tb=s/dem;
	return tb;
}

int main(){
	int n, a[101];
	nhap(n,a);
	chinhphuong(n,a);
	float tb=chinhphuong(n,a);
	printf("\nTrung binh chinh phuong:%.2f", tb);
}
