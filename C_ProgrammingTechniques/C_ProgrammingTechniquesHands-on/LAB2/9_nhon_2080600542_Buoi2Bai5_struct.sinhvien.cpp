#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>


struct DATE{
	unsigned char ngay;
	unsigned char thang;
	int nam;
};

struct tinhdiem{
	char ten[10];
	char MSSV[9];
	float diemtrungbinh;
	char gioitinh[1];
	char hutech[8];
	struct DATE ns;
};
typedef tinhdiem td;
void nhapngaysinh(DATE &a){
	printf("\nNgay:");
	scanf("%u", &a.ngay);
	printf("\nThang:");
	scanf("%u", &a.thang);
	printf("\nNam:");
	scanf("%d", &a.nam);
}
void xuatngaysinh(DATE d){
	printf("\nNgay thang nam sinh:");
	printf("%2u %2u %4d", d.ngay,d.thang,d.nam);
}
void nhap (td&x){

	printf("\nTen:");
	scanf("%s", &x.ten);	
	printf("\nNhap ngay thang nam sinh:");
	nhapngaysinh(x.ns);
	printf("\nMSSV:");
	scanf("%s", &x.MSSV);
	do{
		printf("\nGioi tinh\(x(nam) hoac y(nu)):");
		scanf("%s",&x.gioitinh);
		if(strcmp(x.gioitinh,"x")==0){
			printf("\nGioi tinh:nam");
		}else if(strcmp(x.gioitinh,"y")==0){
			printf("\nGioi tinh:nu");
		}
		if (strcmp(x.gioitinh,"x")!=0&&strcmp(x.gioitinh,"y")!=0){
			printf("\nNhap sai. Nhap lai\n");
		}
	}while(strcmp(x.gioitinh,"x")!=0&&strcmp(x.gioitinh,"y")!=0);	
	printf("\nDiem diem trung binh:");
	scanf("%f", &x.diemtrungbinh);
	printf("\nNhap lop 2 ktu la nam hoc, 1 ktu bac dai hoc(d:dh, c:cd), 2 ktu nganh hoc:");	
	scanf("%s", x.hutech);
}
void nhapSV(int &n, td a[]){
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
void xuat(td x){
	printf("\nlop: %s",x.hutech);	
	printf("\nTen: %s",x.ten);
	printf("\n");
	xuatngaysinh(x.ns);

	printf("\nMSSV:%s",x.MSSV);
	if(strcmp(x.gioitinh,"x")==0){
		printf("\nGioi tinh:nam");
	}else if(strcmp(x.gioitinh,"y")==0){
		printf("\nGioi tinh:nu");
	}
	printf("\nDiem diem trung binh :%.3f",x.diemtrungbinh);
	
}
void xuatSV(int n, td a[]){
//	printf("\n____________________________________\n");
	for (int i=0; i<n;i++){
		printf("\nSinh sien thu %d:",i+1);
		xuat(a[i]);	
	}
//	printf("\n____________________________________\n");
}
void xuatdssinhvienthuoccntt(int n, td a[]){
	td SVtimthay[101];
	int timthay = 0;
	char tenSV[30] ;
	char SV[30]= "TT";
	for(int i=0;i<n;i++){
		strcpy(tenSV, a[i].hutech);
		if(strstr(strupr(tenSV), strupr(SV))){
			SVtimthay[timthay] = a[i];
			timthay++;
		}
	}
	xuatSV(timthay, SVtimthay);
}
void xuatsv_dtb_lonnhon_5(int n, td a[]){
	for (int i=0; i<n;i++){
		if(a[i].diemtrungbinh>5){
			xuat(a[i]);
		}
	}
}
int dem_sv_nu(int n, td a[]){
	int dem=0;
	for (int i=0; i<n;i++){
		if(strcmp(a[i].gioitinh, "y")==0){
			dem++;
		}
	}
	return dem;
}

int xuatsvdtbcao(int n, td a[]){
	
	int max=a[0].diemtrungbinh;
	for (int i=0; i<n;i++){	
		if(a[i].diemtrungbinh>max){
			max=a[i].diemtrungbinh;
		}
	}
	int vt;
	for (int j=0; j<n; j++){	
		if(max==a[j].diemtrungbinh){
			xuat(a[j]);
		}
	}
}

int themsvvaocuoi(int &n, td a[], td x){
	a[n]=x;
	n++;
}

int xoaSV(int n, char MSSVcanxoa[10] ,td a[]){
	int i,j;
	int flag = 1;
	for (i=0;i<n;i++){
		if(strcmp(a[i].MSSV, MSSVcanxoa) == 0){
			flag =1;
			for(int j=i;j<n;j++)
				a[j]=a[j+1];
			printf("----Da xoa sinh vien co MSSV:%s-----", MSSVcanxoa);
			n--;
			break;
		}
	}

 	if(flag == 0){
		printf("\nKhong co sinh vien can xoa");
		return 0;
	}else{
		return 1;
	}
	
}

void search(int n, char mssvien[30],td a[]){
	
	for(int i=0;i<n;i++){
		if(strcmp(mssvien,a[i].MSSV)==0){
			xoaSV(n,mssvien,a);
		}
	}
}
int swap(td &a, td &b){
	td tmp = a;
    a = b;
    b = tmp;
}
int sapxep(int n, td a[]){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(a[i].diemtrungbinh>a[j].diemtrungbinh){
				swap(a[i], a[j]);
			}
		}
	}
}
int main(){
	int n;
	td a[100];
	nhapSV(n,a);
	xuatSV(n,a);
	
	printf("\nDanh sach sv thuoc nganh cntt:");
	xuatdssinhvienthuoccntt(n,a);
	printf("\nCac sinh vien co diem trung binh lon hon 5:");
	xuatsv_dtb_lonnhon_5(n,a);
	printf("\nSo luong sinh vien nu: %d", dem_sv_nu(n,a));
	printf("\nSap xep danh sach tang dan theo diem trung binh:");
	sapxep(n,a);
	xuatSV(n,a);
	
	td x;
	printf("\nNhap thong tin sinh vien can them vao cuoi:");
	nhap(x);
	themsvvaocuoi(n,a,x);
	xuatSV(n,a);


	printf("\nNhung sinh vien co diem trung binh cao nhat:");
	xuatsvdtbcao(n,a);
	char mssvien[10];
	printf("\nNhap mssv can tim va xoa:");
	fflush(stdin);
	gets(mssvien);
	search(n,mssvien,a);
	xuatSV(n,a);
}


