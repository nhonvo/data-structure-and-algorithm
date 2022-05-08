#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Canbo{
	char ten[20];
	float luong;
};
typedef Canbo cb;

void nhap(cb&a){
	printf("\nNhap ho&ten:");fflush(stdin); gets(a.ten);
	printf("\nNhap luong:");scanf("%f",&a.luong);
}

void nhapN(int n, cb a[]){
	for(int i=0;i<n;i++){
		printf("Nhap can bo thu %d", i+1);
		nhap(a[i]);
	}
}
void xuat(cb a){
	printf("\nHo va ten:%s", a.ten);
	printf("\nLuong:%f", a.luong);
}

void xuatN(int n,cb a[] ){
	for(int i=0;i<n;i++){
	printf("\nCan bo thu %d", i+1);
	printf("\nHo va ten:%s", a[i].ten);
	printf("\nLuong:%.3f", a[i].luong);
			
	}
}

void sapxep(int n, cb a[]){
	cb bien;
	printf("\nSap xep can bo\n");
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].luong>a[j].luong){
			bien =a[i];
			a[i]=a[j];
			a[j]=bien;
			}
		}
	}
}

int main(){
	int n;
	cb a[101];
	do{
		printf("Nhap so luong can bo:"); scanf("%d", &n);
		if(n<=0||n>15){
			printf("Nhap sai. Nhap lai");
		}
	}while(n<=0||n>15);
	nhapN(n,a);
	sapxep(n,a);	
 	xuatN(n,a);	
	printf("\nNhap vao phim bat ki de tiep tuc");
	getch();
	return 0;
}
