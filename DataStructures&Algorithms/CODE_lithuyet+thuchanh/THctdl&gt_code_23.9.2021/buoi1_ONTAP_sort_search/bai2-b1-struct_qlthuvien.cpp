#include<stdio.h>
#include<string.h>
struct quanlythuvien{
	int masach;
	char tensach[40];
	float gia;
};
typedef struct quanlythuvien tv;


void nhap_1(tv&x){
	printf("\nNhap ma sach: ");  scanf("%d", &x.masach);
	printf("\nNhap ten sach: "); fflush(stdin); gets(x.tensach);
	printf("\nNhap gia: "); 	 scanf("%f", &x.gia);
}
void xuat_1(tv x){
	printf("\n%d--%s--%.2f\n", x.masach, x.tensach , x.gia);
}
void nhap_N(int n, tv a[]){
	for(int i=0;i<n;i++){
		nhap_1(a[i]);
		printf("\n--------------\n");
	}
}
void xuat_N(int n, tv a[]){
	for(int i=0;i<n;i++){
		xuat_1(a[i]);
	}
}

void tim_kiem_ma_sach_tuyentinh(int n, tv a[], int key)
{
	int i,j;
	for( i=0;i<n;i++){
		if(a[i].masach==key){
			xuat_1(a[i]);			
		}
	}
}
void tim_kiem_ma_sach_nhiphan(int n, tv a[], int key)
{
	int left = 0, right =n - 1;
	int mid;
	while(left <= right){
	mid =(right + left)/2 ;
		if(a[mid].masach == key){
			xuat_1(a[mid]);
			return;
		}else if(a[mid].masach > key){
			right =mid -1;
		}else{
			left =mid +1;
		}
	}
}
//??????????????
void tim_kiem_ten_sach(int n, tv a[], char x[100])
{
	for(int i=0;i<n;i++){
		if(strcmp(x,a[i].tensach)==0){
			xuat_1(a[i]);
			return;
		}
	}
}
//tim sach co gia ban cao????????
void max_gia(int n, tv a[])
{
	int max=a[0].gia;
	for(int i=0;i<n;i++)
	{
		if(a[i].gia>max)
		{
			max=a[i].gia;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].gia==max)
		{
			xuat_1(a[i]);
		}
	}
}
int main()
{
	int n;
	tv a[101];
		do
	{
		printf("Nhap n: "); scanf("%d",&n);
		if(n<=0||n>100)
		{
			printf("\nNhap sai! Moi nhap lai.\n");
		}
	}while(n<=0||n>100);
	printf("\nNhap thong tin sach: ");
	nhap_N(n,a); 
	printf("\nXuat thong tin danh sach: ");
	xuat_N(n,a);
//tim kiem ma sach tuyen tinh
	int key;
	printf("\nNhap so can tim bang tim kiem tuyen tinh:");
	scanf("%d", &key);
	tim_kiem_ma_sach_tuyentinh(n,a,key);
//tim kiem nhi phan
	int key_2;
	printf("\nNhap so can tim bang tim kiem nhi phan:");
	scanf("%d", &key_2);
	tim_kiem_ma_sach_nhiphan(n,a,key_2);
	char ten_sach [100];
	printf("\nNhap ten sach: "); fflush(stdin); gets(ten_sach);
	tim_kiem_ten_sach(n,a,ten_sach);
// nhung sach co gia cao
	max_gia(n,a);
	return 0;
}

