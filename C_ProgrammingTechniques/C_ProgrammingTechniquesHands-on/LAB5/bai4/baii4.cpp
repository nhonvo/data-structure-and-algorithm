#include<stdio.h>
#include<string.h>


typedef struct Mat_hang{
	char id[5];
	int sl;
	float dg;
	float st;
}mh;

void nhap_1(mh &a){
	fflush(stdin);
	printf("\nNhap ma hang don hang: ");
	gets(a.id);
	printf("\nNhap so luong don hang: ");
	scanf("%d",&a.sl);
	printf("\nNhap don gia san pham: ");
	scanf("%f",&a.dg);
	a.st = a.sl * a.dg;
}

void xuat_1(mh a){
	printf("\nMa hang don hang la : ");
	puts(a.id);
	printf("\nso luong : %d \tdon gia: %.2f \t Gia tien : %.2f",a.sl, a.dg, a.st);

}
void xuat_file(mh a, FILE *f1){
	fprintf(f1,"\nMa hang don hang la(file): ");
	fputs(a.id,f1);
	fprintf(f1,"\nso luong : %d \tdon gia: %.2f \t Gia tien : %.2f",a.sl, a.dg, a.st);
}
void xuat_N_file(mh a[],int n,FILE *f1){
	for(int i=0;i<n;i++){
		printf("\nBuu kien thu %d ",i+1);
		xuat_file(a[i],f1);
		printf("\n----------------------------------\n");
	}
}
void nhap_N(mh a[],int n){
	
	for(int i=0;i<n;i++){
		printf("\nNhap buu kien thu %d",i+1);
		nhap_1(a[i]);
		printf("\n----------------------------------\n");
	}
}

void xuat_N(mh a[],int n,FILE *f1){
	for(int i=0;i<n;i++){
		printf("\nBuu kien thu %d ",i+1);
		xuat_1(a[i]);
		printf("\n----------------------------------\n");
	}
}



int main(){
	FILE *f1;
	mh a[100];
	int n;
	f1 = fopen("bai1.txt","r+");
	printf("\nNhap so luong buu kien: ");
	scanf("%d",&n);
	nhap_N(a,n);
	xuat_N(a,n,f1);
	xuat_N_file(a,n,f1);
	fclose(f1);
	return 0;
}
