#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>


struct DATE{
	unsigned char ngay;
	unsigned char thang;
	int nam;
};

typedef struct Sinhvien{
	char MSSV[9];
	char ten[10];
	float diem;
	struct DATE ns;
}sv;
void nhapngaysinh(DATE &a){
	printf("\nNgay:");
	scanf("%u", &a.ngay);
	printf("\nThang:");
	scanf("%u", &a.thang);
	printf("\nNam:");
	scanf("%d", &a.nam);
}
void xuatngaysinh(DATE d){
	printf("%2u/%2u/%4d", d.ngay,d.thang,d.nam);
}
void nhap (sv&x){
	printf("\nMSSV:");
	scanf("%s", &x.MSSV);
	printf("\nTen:");
	scanf("%s", &x.ten);
	printf("\nNhap ngay thang nam sinh:");
	nhapngaysinh(x.ns);
		
	printf("\nNhap diem:");
	scanf("%f", &x.diem);
}
void nhapSV(int &n, sv a[]){
	do{
		printf("\nNhap so luong sinh vien:");
		scanf("%d", &n);
		if(n<=0||n>100){
			printf("\nSai! So luong sinh vien phai nam trong khoang --- n<=0||n>100--\nLam on thu lai. ");
		}
	}while(n<=0||n>100);
	
	for (int i=0; i<n;i++){
		printf("Nhap sinh sien thu %d:",i+1);
		nhap(a[i]);
	}
}
void xuat(sv x){
	printf("\n%s |%s |", x.MSSV,x.ten);
	xuatngaysinh(x.ns);
	printf("|%.2f", x.diem);
}
void xuatSV(int n, sv a[]){
	printf("\n____________________________________\n");
	printf("Xuat danh sach sinh vien");
	for (int i=0; i<n;i++){
		printf("\nSinh sien thu %d:",i+1);
		xuat(a[i]);	
	}
	printf("\n____________________________________\n");
}
int tim_sv_theoten(int n, char MSSVcantim[10] ,sv a[])
{
	int i,j;
	int flag = 0;
	for (i=0;i<n;i++)
	{
		if(strcmp(a[i].ten, MSSVcantim) == 0)
		{
			printf("\nDa tim thay sinh vien %s", a[i].ten);
			xuat(a[i]);
			flag=1;
		}
	}

 	if(flag == 0)
	 {
		printf("\nKhong co sinh vien can tim");
		return 0;
	}else
	{
		return 1;
	}
	
}


void xuatsv_d_lonnhon_5(int n, sv a[])
{
	for (int i=0; i<n;i++)
	{
		if(a[i].diem >= 5)
		{
			xuat(a[i]);
		}
	}
}
void demsv_d_lonnhon_8(int n, sv a[])
{
	int dem=0;
	for (int i=0; i<n;i++)
	{
		if(a[i].diem > 8)
		{
			dem++;
			xuat(a[i]);
		}
	}
	printf("\nSo luong sinh vien co diem > 8: %d", dem);
}
void xuatsv_d_caonhat(int n, sv a[])
{
	int max=a[0].diem;
	for (int i=0; i<n;i++)
	{
		if(a[i].diem > max)
		{
			max=a[i].diem;
		}
	}
	for (int i=0; i<n;i++)
	{
		if(max == a[i].diem)
		{
			xuat(a[i]);
		}
	}
}
int xuat_sl_tsv_d_caonhat(int n, sv a[])
{
	int max=a[0].diem;
	for (int i=0; i<n;i++)
	{
		if(a[i].diem > max)
		{
			max=a[i].diem;
		}
	}
	int dem=0;
	for (int i=0; i<n;i++)
	{
		if(max == a[i].diem)
		{
			dem++;
		}
	}
	return dem;
}
int swap(sv &a, sv &b){
	sv tmp = a;
    a = b;
    b = tmp;
}
int sapxep_theo_diem(int n, sv a[]){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(a[i].diem>a[j].diem){
				swap(a[i], a[j]);
			}
		}
	}
}
int sapxep_theo_mssv(int n, sv a[]){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(strcmp(a[i].MSSV, a[j].MSSV) > 0){
				swap(a[i], a[j]);
			}
		}
	}
}
int main(){
	int n;
	sv a[100];
	nhapSV(n,a);
	xuatSV(n,a);
	
//d
	char tensv_tim[10];
	printf("\nNhap ten sinh vien can tim:");
	fflush(stdin);
	gets(tensv_tim);
	tim_sv_theoten(n,tensv_tim,a);
//e
	printf("\nCac sinh vien co diem >= 5:");
	xuatsv_d_lonnhon_5(n,a);
//f
	demsv_d_lonnhon_8(n,a);
//g
	printf("\nSinh vien co diem cao nhat: ");
	xuatsv_d_caonhat(n,a);
//h
	printf("\nSo luong sinh vien co diem cao nhat: %d", xuat_sl_tsv_d_caonhat(n,a));
//	i
	printf("\nSap xep danh sach sv tang dan theo diem: ");
	sapxep_theo_diem(n,a);
	xuatSV(n,a);
//j
	printf("\nSap xep danh sach sv tang dan theo mssv: ");
	sapxep_theo_mssv(n,a);
	xuatSV(n,a);
	
	return 0;
}


