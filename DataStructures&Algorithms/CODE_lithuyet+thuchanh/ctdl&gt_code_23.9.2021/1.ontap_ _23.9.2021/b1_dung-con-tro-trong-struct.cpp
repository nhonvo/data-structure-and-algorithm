#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct Quanlisinhvien{
	int manv;
	char ho_ten[30];
	float diem_tb;
};

typedef struct Quanlisinhvien tv;

void nhap_1(tv *x){
	
	printf("\nNhap ma sinh vien: ");  scanf("%d", &x->manv);
	printf("\nNhap ten sinh vien: "); scanf("%s", &x->ho_ten);
	printf("\nNhap diem_tb: ");		  scanf("%f", &x->diem_tb);
}
void xuat_1(tv *x){
	printf("\n%d--",      x->manv);
	printf(" %s--", 	  x->ho_ten);
	printf(" %0.2f",	  x->diem_tb);
}
void nhap_N(int n, tv *a){
	for(int i=0;i<n;i++){
		nhap_1((a+i));
		printf("\n--------------\n");
	}
}
void xuat_N(int n, tv *a){
	for(int i=0;i<n;i++){
		xuat_1(a+i);
		printf("\n--------------\n");
	}
}

//tim kiêm theo msv
int tim_kiem(int n, tv *a, int k)
{
	int flag=0;
	for (int i = 0; i <n; i++)
	{
		if(k == (a+i)->manv)
		{
			xuat_1(a+i);
			flag=1;
		}
	}
	return flag;
}

int main()
{
	int n;
//	tv *a = malloc(100*sizeof(double)) ;	
	tv *a =new tv;
//a
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	nhap_N(n,a);
	
	
//b
	printf("\n------Xuat mang ra man hinh----");
	xuat_N(n,a);
	
//c 
	int k;
	printf("\n\nNhap ma so sinh vien can tim: ");
	scanf("%d",&k);
	
	int flag = tim_kiem(n,a,k);
	if (flag==0){
		printf("\nMa so ban nhap khong co trong danh sach");
	}
	
	return 0;
}
