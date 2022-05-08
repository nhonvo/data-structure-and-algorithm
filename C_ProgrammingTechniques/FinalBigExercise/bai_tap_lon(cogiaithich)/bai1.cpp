//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//Chu de 1_bai 5
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>					
#include<math.h>
#define MAX 100

void nhap (int n, int a[]);
void xuat(int n, int a[]);
int dem_tong(int n, int a[], int m);
int tong_binh_phuong(int n, int a[], int m);

int main(){
	int n,a[MAX],m;
	printf("\nNhap so phan tu: ");
    scanf("%d", &n);
	
	nhap(n,a);
	printf("\nMang da nhap: ");
	xuat(n,a);
	printf("\n\nNhap so nguyen m: ");
	scanf("%d",&m);
//a
	int sum_A = dem_tong(n,a,m);
	printf("\nSo cap so nguyen co tong bang m = %d la: %d",m,sum_A);
//b
	int sum_b = tong_binh_phuong(n,a,m);
	printf("\nTong binh phuong cua cac phan tu co cac cap so co tong bang m = %d la: %d",m,sum_b);
//c
	int sum_c = dem_boi_so(n,a,m);
	printf("\nSo boi so cua m = %d: %d",m,sum_c);
	
	printf("\n\nTap somethings to stop!");
    getch();
}

void nhap (int n, int a[]){
    for(int i = 0; i < n; i++)    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuat(int n, int a[]){
    for(int i = 0; i < n; i++){
        printf("\na[%d] = %d", i, a[i]);
    }
}
//a
int dem_tong(int n, int a[], int m){
	int dem=0;
	for(int i = 0; i < n-1; i++){
		for(int j=i+1; j<n;j++){
			if(m==(a[i]+a[j])){
				dem++;
			}
		}
	}
	return dem;
}
//b
int tong_binh_phuong(int n, int a[], int m){
	int dem=0,k=0,b[101],sum;
	for(int i = 0; i < n-1; i++){
		for(int j=i+1; j<n;j++){
			if(m==(a[i]+a[j])){
				sum+=a[i]*a[i]+a[j]*a[j];
			}
		}
	}
	return sum;
}
//c
int dem_boi_so(int n, int a[], int m){
	int dem=0;
	for(int i = 0; i < n; i++){
		if(a[i] % m == 0){
			dem++;
		}
	}
	return dem;
}

//truongnhon
