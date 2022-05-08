#include<stdio.h>

int fibonacy(int n){
	if (n==1 || n==2){
		return 1;
	}
	return fibonacy(n-1)+fibonacy(n-2);
}
int main(){
	int n;
	printf("Nhap so can tinh: ");
	scanf("%d", &n);
	int fi =fibonacy(n);
	printf("\nSo can tinh: %d", fi);
	return 0;
}
