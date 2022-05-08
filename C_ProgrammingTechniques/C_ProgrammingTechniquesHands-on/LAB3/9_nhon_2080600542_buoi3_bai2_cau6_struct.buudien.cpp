#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>

struct DATE
{
    int ngay;
    int nam;
    int thang;
};
typedef struct Buudien
{
    int ma_buu_kien;
    char ten_gui[50];
    char ten_nhan[50];
    float trong_luong;
    DATE ng;
    char noi_dung[50];
    float tien;
} bd;

void nhapngaygui(DATE &a)
{
    printf("\nNgay:");
    scanf("%d", &a.ngay);
    printf("\nThang:");
    scanf("%d", &a.thang);
    printf("\nNam:");
    scanf("%d", &a.nam);
}
void xuatngaygui(DATE d)
{
    printf("\nNgay thang nam gui:");
    printf("%2d %2d %4d", d.ngay, d.thang, d.nam);
}

void nhap(bd &x)
{
    printf("\nNhap ma buu kien:");
    scanf("%d", &x.ma_buu_kien);
    printf("\nNhap ten nguoi gui:");
    fflush(stdin);
    gets(x.ten_gui);
    printf("\nNhap ten nguoi nhan:");
    fflush(stdin);
    gets(x.ten_nhan);
    printf("\nNhap trong luong goi hang:");
    scanf("%f", &x.trong_luong);
    printf("\nNhap ngay gui:");
    nhapngaygui(x.ng);
    printf("\nNhap noi dung buu kien:");
    fflush(stdin);
    gets(x.noi_dung);
}
void xuat(bd x)
{
    printf("\nNhap ma buu kien:          %d", x.ma_buu_kien);
    printf("\nNhap ten nguoi gui:        %s", x.ten_gui);
    printf("\nNhap ten nguoi nhan:       %s", x.ten_nhan);
    printf("\nNhap trong luong goi hang: %f", x.trong_luong);
    xuatngaygui(x.ng);
    printf("\nNhap noi dung buu kien:    %s", x.noi_dung);
}

void nhap_nhieu(int &n, bd a[])
{
    do
    {
        printf("\nNhap so luong buu kien:");
        scanf("%d", &n);
        if (n <= 0 || n > 100)
        {
            printf("\nSai! So luong buu kien phai nam trong khoang --- n<=0||n>100--\nLam on thu lai. ");
        }
    } while (n <= 0 || n > 100);

    for (int i = 0; i < n; i++)
    {
        printf("Nhap buu kien thu %d:", i + 1);
        nhap(a[i]);
    }
}
void xuat_nhieu(int n, bd a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nBuu kien thu %d:", i + 1);
        xuat(a[i]);
    }
}
//them 1 buukien vao ds
int themsvvaocuoi(int &n, bd a[], bd x)
{
    a[n] = x;
    n++;
}
//ss ds theo ma buukien
int swap(bd &a, bd &b)
{
    bd tmp = a;
    a = b;
    b = tmp;
}
int sapxep(int n, bd a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].ma_buu_kien > a[j].ma_buu_kien)
            {
                swap(a[i], a[j]);
            }
        }
    }
}
//tinh gia tri moi buu kien=tien*trong luong
int giatri_buukien(int n, bd a[])
{
    float giatri;
    for (int i = 0; i < n; i++)
    {
        printf("\nGia tri buu kien thu %d :", i);
        giatri = a[i].tien * a[i].trong_luong;
        printf("%f", giatri);
    }
}
int sobuukiencotrongluonglonnhat(int n, bd a[]){
	
	int max=a[0].trong_luong;
	for (int i=0; i<n;i++){	
		if(a[i].trong_luong>max){
			max=a[i].trong_luong;
		}
	}
	printf("\nTrong luong %d la can nang lon nhat.",max);
	int vt=0;
	for (int j=0; j<n; j++){	
		if(max==a[j].trong_luong){
			vt++;
		}
	}
    return vt;
}
void search(int n, char ten_ng_gui[30],bd a[]){
	
	for(int i=0;i<n;i++){
		if(strcmp(ten_ng_gui,a[i].ten_gui)==0){
            xuat(a[i]);
		}
	}
}
void xuat_theo_ngay(int n, bd a[]){
	printf("\nCac buu kien gui vao thang 4/2014:");
	for(int i=0; i<n;i++){
			printf("\nBuu kien thu %d:", i);
		if((a[i].ng.thang==4)&&(a[i].ng.nam==2014)){
				xuat(a[i]);
		}
	}  
}
int main()
{
    bd a[100];
    int n;
    printf("-----CHUONG TRINH QUAN LI BUU DIEN----");
//a
    nhap_nhieu(n, a);
//b   
    xuat_nhieu(n, a);

//c

	bd x;
	printf("\nNhap ten buu kien can them vao:");
	nhap(x);
	themsvvaocuoi(n,a,x);
	xuat_nhieu(n,a);
    
//d
	sapxep(n,a);
	xuat_nhieu(n,a);

//e
	giatri_buukien(n,a);
		
//f
    int dem = sobuukiencotrongluonglonnhat(n,a);
    printf("\nSo buu kien co trong luong lon nhat: %d",dem);

//g
    char ten_ng_gui[50];
    printf("\nNhap ten nguoi gui can tim: ");
    fflush(stdin);
    gets(ten_ng_gui);
    search(n,ten_ng_gui,a);

//h
	xuat_theo_ngay(n,a);	
}
