//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//Chu de 4 bai 5

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

long long tinh_tong_xn_de_quy(int n);
long long tinh_xn_khong_De_quy(long long n, long long a[]);

int main(){
	long long n,a[100];
	long long b[100];
	printf("Nhap n: ");
	scanf("%lld", &n);

//b
	long long u = tinh_tong_xn_de_quy(n);
	printf("\n\t\tb)Ket qua x(%d) de quy: ", n);
	printf("\n\t\t\t %lld", u);		
//c
	long long cc = tinh_xn_khong_De_quy(n,a);
	printf("\n\t\tb)Ket qua x(%d) khong de quy: ", n);
	printf("%lld", cc);
	return 0;
}
//b
long long tinh_tong_xn_de_quy(int n){
	if(n<=3){
		return n;
	}
	return 2 * tinh_tong_xn_de_quy(n-1) * (5 * tinh_tong_xn_de_quy(n-2) + 3 * tinh_tong_xn_de_quy(n-3));
}
//c
long long tinh_xn_khong_De_quy(long long n, long long a[]){
	a[1]=1,a[2]=2;a[3]=3; 
	long long m;
	if(n<=3){
		return n;
	}else{
		for(int i=4;i<=n;i++){
			a[i] = 2*a[i-1]*(5*a[i-2]+3*a[i-3]);
			m=a[i];
		}
	}
	return m;
}
