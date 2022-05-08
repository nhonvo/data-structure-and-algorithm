#include<stdio.h>
#include<string.h>
struct Thuvien{
	char masach[5];
	char tensach[40];
	float gia;
};

typedef struct Thuvien tv;

void nhap_1(tv&x);
void xuat_1(tv x);
void nhap_N(int n, tv a[]);
void xuat_N(int n, tv a[]);
void xuat_1_file(tv x, FILE *f1);
void xuat_N_file(int n, tv a[], FILE *f1);
void doc_file(int n, tv a[], FILE *f1);
int tim_kiem_x(int n, tv a[], FILE *f2, char x[100]);
int max_gia(int n, tv a[]);

int main(){
	int n;
	tv a[100];
	FILE *f1, *f2;
	
	f1 = fopen("data.txt", "w");
	f2 = fopen("ketqua.txt", "w");
	if(f1==NULL){
		printf("\nChua tim thay File!");
	}
	
	printf("Nhap so luong phan tu n: ");
	scanf("%d", &n);
	nhap_N(n,a);
	printf("\n------Xuat mang ra man hinh----");
	xuat_N(n,a);
	
//b-xuat theo kieu mang
	xuat_N_file(n,a,f1);
	rewind(f1);
//c--d
	tv b[100];
	printf("\n\tc>Lay du lieu tu data.txt luu vao b[]: ");
	doc_file(n,b,f1);

//e
	char x[100];
	printf("\nNhap ma sach x: ");
	scanf("%s", &x);
	int flag = tim_kiem_x(n,a,f2,x);
	if(flag == 1){
		printf("Co x trong mang");
		fprintf(f2, "---Co x trong mang");
	}else{
		fprintf(f2, "***Khong co x trong mang");
		printf("\nKhong co x trong mang");
	}
//f
	float max = max_gia(n,a);
	fprintf(f2,"\nGia cao nhat la: %0.2f", max);
	
	fclose(f1);
	fclose(f2);
	return 0;
}

void nhap_1(tv&x){
	printf("\nNhap ma sach: ");  scanf("%s", &x.masach);
	printf("\nNhap ten sach: "); scanf("%s", &x.tensach);
	printf("\nNhap gia: "); 	 scanf("%f", &x.gia);
}
void xuat_1(tv x){
	printf("\nMa sach: %s",  x.masach);
	printf("\nTen sach: %s", x.tensach);
	printf("\nGia: %0.2f",	 x.gia);
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
	fprintf(f1,"%s", 		x.masach);
	fprintf(f1,"\t%s",  	x.tensach);
	fprintf(f1,"\t%0.2f",	x.gia );
}
void xuat_N_file(int n, tv a[], FILE *f1){
	for(int i=0;i<n;i++){
		xuat_1_file(a[i],f1);
		fprintf(f1,"\n");
	}
}
//c 
void doc_file(int n, tv a[], FILE *f1){
	tv b[100];
	int i=0;
	f1 = fopen("data.txt", "r");
	while(i<n){
		fscanf(f1,"%s\t%s\t%f", &b[i].masach, &b[i].tensach,&b[i].gia);
		i++;
	}
	for(int i=0;i<n/2;i++){
		xuat_N(n,b);
	}
}
//e
int tim_kiem_x(int n, tv a[], FILE *f2, char x[100]){
	f2 = fopen("ketqua.txt", "w");
	int flag=0;
	for(int i=0;i<n;i++){
		if(strcmp(x,a[i].masach)==0){
			flag=1;
		}
	}
	return flag;
}
//f
int max_gia(int n, tv a[]){
	int max=-1;
	for(int i=0;i<n;i++){
		if(a[i].gia>max){
			max=a[i].gia;
		}
	}
	return max;
}

