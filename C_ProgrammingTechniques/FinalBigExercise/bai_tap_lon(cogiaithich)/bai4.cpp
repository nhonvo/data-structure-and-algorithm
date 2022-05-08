//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//bai 1 buoi 1

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

long long b[100];

//a
//a[4] = 78
//a[5] = 3276
//a[6] = 2614248
//a[7] = 86866232544

//b- su dung de quy  - chung ket luan muon lay cau nao TUY

//cach 1: de quy co nho
long long tinh_xn(long long n, long long b[]){
	
	if(n == 0){
		return 0;
	}
	if(b[n]>0){
		return b[n];
	}
	if(n <= 3){
		return b[n] = n;
	}
	b[n-3] = tinh_xn(n-3, b);
	b[n-2] = tinh_xn(n-2, b);
	b[n-1] = tinh_xn(n-1, b);
	return b[n] = 2 *  b[n-1]* (5 * b[n-2]+ 3 * b[n-3]);
}

//cach 2: de quy binh thuong

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
	for(int i=4;i<=n;i++){
		a[i] = 2*a[i-1]*(5*a[i-2]+3*a[i-3]);
		m=a[i];
	}
	return m;
}

int main(){
	long long n,a[100];
	printf("Nhap n: ");
	scanf("%lld", &n);
	
	
//c
	long long cc = tinh_xn_khong_De_quy(n,a);
	printf("\nKet qua x(n) khong de quy: ");
	printf("%lld", cc);
//b
	long long u = tinh_tong_xn_de_quy(n);
	printf("\nKet qua x(n) de quy: ");		
	printf("\n %lld", u);		

	long long nn =tinh_xn(n,b);
	printf("\nKet qua x(n) de quy: ");		
	printf("\n %lld", nn);
	
}
