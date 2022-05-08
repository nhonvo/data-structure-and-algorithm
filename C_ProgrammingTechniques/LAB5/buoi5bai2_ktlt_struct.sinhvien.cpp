#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>


struct sinhvien{
	char lop[10];
	int MSSV;
	int namsinh;
	char gioitinh[1];
	char quequan[50];
};
typedef sinhvien sv;


void nhap (sv&x ){
//	printf("\nLop:");
//	fflush(stdin);
//	gets(x.lop);
//	printf("\nMSSV:");
//	scanf("%d", &x.MSSV);
	printf("\nNam sinh:");
	scanf("%d", &x.namsinh);
//	do{
//		printf("\nGioi tinh\(x(nam) hoac y(nu)):");
//		scanf("%s",&x.gioitinh);
//		if(strcmp(x.gioitinh,"x")==0){
//			printf("\nGioi tinh:nam");
//		}else if(strcmp(x.gioitinh,"y")==0){
//			printf("\nGioi tinh:nu");
//		}
//		if (strcmp(x.gioitinh,"x")!=0&&strcmp(x.gioitinh,"y")!=0){
//			printf("\nNhap sai. Nhap lai\n");
//		}
//	}while(strcmp(x.gioitinh,"x")!=0&&strcmp(x.gioitinh,"y")!=0);
	
//	printf("\nQue quan:");
//	fflush(stdin);
//	gets(x.quequan);
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
	
//	printf("\n____________________________________\n");
//	printf("\nLop:%s",x.lop);
//	
	printf("\nMSSV:%d",x.MSSV);
//	printf("\nNam sinh: %d", x.namsinh);
//	
//	if(strcmp(x.gioitinh,"x")==0){
//		printf("\nGioi tinh:nam");
//	}else if(strcmp(x.gioitinh,"y")==0){
//		printf("\nGioi tinh:nu");
//	}
//	printf("\nQue quan:%s", x.quequan);
//	printf("\n____________________________________\n");
}
void xuatSV(int n, sv a[]){
	
	for (int i=0; i<n;i++){
		printf("\nSinh sien thu %d:",i+1);
		xuat(a[i]);	
	}
}

int swap(sv &a, sv &b){
	sv tmp = a;
    a = b;
    b = tmp;
}
//xuat sinh vien theo lop, que
void Xuat_Que (sv a[100], int n){
    int i,j, b[100];
    for(i=0;i<n;i++)
        b[i]=0;
    for(i=0;i<n-1;i++)
        if (b[i]==0){
            printf("\n Cac sinh vien que %s:\n",a[i].quequan);
            xuat(a[i]);
            b[i]=1;
            for(j=i+1;j<n;j++)
                if(strcmp(a[i].quequan,a[j].quequan)==0){
                    xuat(a[j]);
                    b[j]=1;
                } 
        }
}
void Xuat_Lop (sv a[100], int n){
    int i,j, b[100];
    for(i=0;i<n;i++)
        b[i]=0;
    for(i=0;i<n-1;i++)
        if (b[i]==0){
            printf("\n Cac sinh vien lop %s:\n",a[i].lop);
            xuat(a[i]);
            b[i]=1;
            for(j=i+1;j<n;j++)
                if(strcmp(a[i].lop,a[j].lop)==0){
                    xuat(a[j]);
                    b[j]=1;
                } 
        }
}

int sinhvienlontuoinhat(int n, sv a[]){
	
	int i,j,min=a[0].namsinh;
	for (i=0;i<n;i++){
		if(a[i].namsinh<min){
			min=a[i].namsinh;
		}
	}
	int vt;
	for(j=0;j<n;j++){
		if(min==a[j].namsinh){
			vt = a[j].MSSV;
		}
	}
	return vt;
}
int counts(int n, sv a[], char diaphuong[50]){
	char diaphuong1[50];
	char diaphuong2[50];
	int i,j,dem=0;
	diaphuong=a[0].quequan;
	for (i=0;i<n-1;i++){
		strcpy(diaphuong1,a[i].quequan);
		for(j=i+1;j<n;j++){
			strcpy(diaphuong2,a[j].quequan);
			if(strcmp( strupr(diaphuong1), strupr(diaphuong2)) == 0){
				dem++;
			}
		}
	}
	return dem;
}
int Dp_max(int n, sv a[]){
	int	max=-1;
	for(int i= 0; i < n; i++)
    {
    if(max < counts(n,a, a[i].quequan)){
          max = counts(n,a, a[i].quequan);     
        }
    }
    return max;
}



int main(){																
	sv a[101];
	int n;
	nhapSV(n,a);
//	printf("\nXuat danh sach sinh vien:");

//	xuatSV(n,a);
//2	
//	Xuat_Que(a,n);
//3
//	Xuat_Lop(a,n);
//4		
	int vt =    sinhvienlontuoinhat(n,a);
	printf("\nMssv lon tuoi nhat:%d",vt);
//5    

//	char diaphuong[50];
//	counts(n,a,diaphuong);
//	int max =Dp_max(n,a);
//    printf("\nDia phuong nhieu nhat co %d (sinh vien)",max);
}



