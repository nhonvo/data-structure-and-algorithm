#include<stdio.h>
#include<string.h>

struct Quanlinhanvien{
	int manv;
	char ho_ten[30];
	float luong;
};

typedef struct Quanlinhanvien tv;

void nhap_1(tv&x){
	printf("\nNhap ma nhan vien: ");  scanf("%d", &x.manv);
	printf("\nNhap ho va ten: "); 	  scanf("%s", &x.ho_ten);
	printf("\nNhap luong: "); 	 	  scanf("%f", &x.luong);
}
void xuat_1(tv x){
	printf("\n%d--",  x.manv);
	printf(" %s--", 	  x.ho_ten);
	printf(" %0.2f",	  x.luong);
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
		printf("\n--------------\n");
	}
}
//b
void xuat_1_file(tv x, FILE *f1){
	fprintf(f1,"%d\t%s\t%0.2f", x.manv, x.ho_ten, x.luong);
}
void xuat_N_file(int n, tv a[], FILE *f1){
	for(int i=0;i<n;i++){
		xuat_1_file(a[i],f1);
		fprintf(f1,"\n");
	}
}
//c 
void swap(tv &xp, tv &yp)
{
	tv temp = xp;
	xp = yp;
	yp = temp;
}

void sap_xep(int n, tv a[]){
	int i,j;
	tv b[100];
	for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{	
				if(a[i].luong > a[j].luong){
					swap(a[i],a[j]);
				}
			}
		}
	xuat_N(n,a);
}
//d
//e
void doc_file(int n, tv a[], FILE *f1){
	tv b[100];
	int i=0;
	f1 = fopen("data", "r");
	while(i<n){
		fscanf(f1,"%d %s %f", &b[i].manv, &b[i].ho_ten,&b[i].luong);
		i++;
	}
	for(int i=0;i<n/2;i++){
		xuat_N(n,b);
	}
}
//f

void ss_hoten(int n, tv a[]){
	int i, j;
	tv b[100];
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].ho_ten, a[j].ho_ten)>0)
			{
				swap(a[i],a[j]);
			}
		}
	}
}
//g
void thay_doi(int n, tv a[], int k, float luong_moi){
	for (int i = 0; i <n; i++){
		if(k == a[i].manv){
			a[i].luong = luong_moi;
		}
	}
}


int main(){
	int n;
	tv a[100];
	FILE *f1;
	
	f1 = fopen("data", "w");
	if(f1==NULL){
		printf("\nChua tim thay File!");
	}
//a
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	nhap_N(n,a);
//b
	printf("\n------Xuat mang ra man hinh----");
	xuat_N(n,a);
//c
	printf("\n---Sap xep mang tang dan theo luong: ");
	sap_xep(n,a);
//d-luu mang vao file data
	xuat_N_file(n,a,f1);
	rewind(f1);
//e
	printf("\n---File doc tu data xuat ra man hinh:");
	doc_file(n,a,f1);
//f
	printf("\n---Sap xep mang tang dan theo ho va ten: ");
	ss_hoten(n,a);
	xuat_N(n,a);
//g
	int k;
	float kk;
	printf("\n---Nhap ma nhan vien can thay doi luong:");
	scanf("%d", &k);
	kk=25.5;
	thay_doi(n,a,k,kk);
	xuat_N(n,a);
	
	fclose(f1);
	return 0;
}

