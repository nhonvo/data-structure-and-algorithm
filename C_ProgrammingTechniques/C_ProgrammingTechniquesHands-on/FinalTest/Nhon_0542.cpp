//2080600542
//Vo Thuong Truong Nhon
//20DTHD4
//DE 1
//28/7/2021

#include<stdio.h>
#include<string.h>
#include<conio.h>

struct MTINH{
	char ma_mt[5];	
	int nam_sx;
	float don_gia;
	int so_luong;
};

typedef struct MTINH tv;

//a-1
void doc_file(int n, tv a[], FILE *f1){
	f1 = fopen("Dsmt.txt", "r");
	fscanf(f1,"%d\n", &n);
	for(int i=0;i<n;i++){
		fscanf(f1,"%s %d %f %d", &a[i].ma_mt, &a[i].nam_sx, &a[i].don_gia, &a[i].so_luong);
	}
}
//a-2
void xuat_1(tv a){
	printf("%s\t%d\t%0.1f\t%d\n", a.ma_mt, a.nam_sx, a.don_gia, a.so_luong);
}
void xuat_N(int n, tv a[]){
	for(int i=0;i<n;i++){
		xuat_1(a[i]);
	}
}
//e
void xuat_1_file(tv x, FILE *f2){
	fprintf(f2,"%s %d %f %d", x.ma_mt, x.nam_sx, x.don_gia, x.so_luong);
}
void xuat_N_file(int n, tv a[], FILE *f2){
	for(int i=0;i<n;i++){
		xuat_1_file(a[i],f2);
		fprintf(f2,"\n");
	}
}
//b- tong tien
void tong_tien(int n, tv a[], FILE *f2){
	float s[100];
	int k=0;
	for(int i=0;i<n;i++){
		s[k++] = a[i].don_gia * a[i].so_luong;
	}
	fprintf(f2, "\n\t---b) Tong gia tien cua cac may tinh: ");
	for(int i=0;i<n;i++){	
		printf("\nMay co ma %s co tong thanh tien: %0.1f", 		a[i].ma_mt, s[i]);
		fprintf(f2,"\nMay co ma %s co tong thanh tien: %0.1f",  a[i].ma_mt, s[i]);
	}
}
//c-tim may theo nam
void tim_may_nam(int n, tv a[], int x, FILE *f2){
	int flag =1,dem =0;
	fprintf(f2,"\n\t---c) So may tinh trung voi so nam nhap tu ban phim: ");
	for(int i=0;i<n;i++){
		if(x==a[i].nam_sx){
			xuat_1(a[i]);
			fprintf(f2,"\n");
			xuat_1_file(a[i],f2);
			dem++;
			flag=0;
		}
	}
	if(flag ==1){
		printf("\nKhong co may can tim!");
		fprintf(f2, "\nKhong co may can tim!");
	}else{
		printf("Tong co %d may tinh can tim.", dem);
		fprintf(f2, "\nTong co %d may tinh can tim.\n", dem);	
	}
}
//d- sap xep theo ma may
void swap(tv &xp, tv &yp)
{
	tv temp = xp;
	xp = yp;
	yp = temp;
}
void sap_xep(int n, tv a[]){
	int i,j;
	for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{	
				if(strcmp(a[i].ma_mt, a[j].ma_mt)>0){
					swap(a[i],a[j]);
				}
			}
		}
	printf("\n");
}

int main(){
	int n;
	tv a[100];
	FILE *f1, *f2;
	
	f1 = fopen("Dsmt.txt", "r");
	f2 = fopen("Ketqua.txt", "w"); 
	if(f1==NULL){
		printf("\nChua tim thay File!");
	}
	
//a - doc file
	fscanf(f1,"%d\n", &n);
	
	doc_file(n,a,f1);
	printf("%d\n", n);
	printf("\n\t---a)Mang nhap tu file:\n");
	xuat_N(n,a);
//b
	printf("\n\t---b) Tong gia tien cua cac tinh: ");
	tong_tien(n,a,f2);
//c
	printf("\n\t---c) So may tinh trung voi so nam nhap tu ban phim: ");
	int x;
	printf("\nNhap nam san xuat: ");
	scanf("%d", &x);
	tim_may_nam(n,a,x,f2);
//d
	printf("\n\t---d) Sap xep tang dan theo ma may: ");
	sap_xep(n,a);
	xuat_N(n,a);
	fprintf(f2,"\n\t---d) Sap xep tang dan theo ma may: \n");
	xuat_N_file(n,a,f2);
//e-xuat vao file

	fclose(f1);
	getch();
	return 0;
}
