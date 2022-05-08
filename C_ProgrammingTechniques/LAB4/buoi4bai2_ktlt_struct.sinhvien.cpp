#include <stdio.h>
#include <string.h>


typedef struct Sinhvien{
    char lop[10];
	int MSSV;
	int namsinh;
	char gioitinh[1];
	char quequan[50];
} sv;
//khai bao ham 

//Thuc hien ham fgets(name, sizeof(name), stdin);
void NhapSv(sv a[100], int n){
    int i;
    for(i=0;i<n;i++){
        fflush(stdin);
        printf("Nhap sinh vien thu %d:\n", i+1);
        printf("Ma sv = ");
        scanf("%d",&a[i].MSSV);
        printf("Lop: ");
        fflush(stdin);
        fgets(a[i].lop,10, stdin);
        printf("Nam sinh: ");
        scanf("%d",&a[i].namsinh);
        printf("Gioi tinh: ");
        scanf("%d",&a[i].gioitinh);
        printf("Que quan: ");
        fflush(stdin);
        fgets(a[i].quequan,50, stdin);
    }
}
void Xuat1Sv(sv a){
    printf("Ma sv: %d\n",a.MSSV);
    printf ("Lop: ");
    puts(a.lop);
    printf("Nam sinh: %d\n", a.namsinh);
    printf("Gioi tính: %d\n",a.gioitinh);
    printf("Que quan: ");
    puts(a.quequan);
    printf("\n");
}
void XuatSv(sv a[100], int n){
    int i;
    for(i=0;i<n;i++){
         printf("Sinh vien thu %d:\n", i+1);
         Xuat1Sv(a[i]);
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
            Xuat1Sv(a[i]);
            b[i]=1;
            for(j=i+1;j<n;j++)
                if(strcmp(a[i].quequan,a[j].quequan)==0){
                    Xuat1Sv(a[j]);
                    b[j]=1;
                } 
        }
}
void Xuat_Lop(sv a[], int n){
    int i,j, b[100];
    for(i=0;i<n;i++)
        b[i]=0;
    for(i=0;i<n-1;i++)
        if (b[i]==0){
            printf("\n Cac sinh vien lop %s:\n",a[i].lop);
            Xuat1Sv(a[i]);
            b[i]=1;
            for(j=i+1;j<n;j++)
                if(strcmp(a[i].lop,a[j].lop)==0){
                    Xuat1Sv(a[j]);
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
    sv a[100];
    int n;
    printf("Cho n = ");
    scanf("%d",&n);
    NhapSv(a,n);
    XuatSv(a,n);
    
//    2,3
//    Xuat_Lop(a,n);
//    Xuat_Que(a,n);
    
    
//    4		
	int vt =    sinhvienlontuoinhat(n,a);
	printf("\nMssv lon tuoi nhat:%d",vt);
	
//	5
//	int max =Dp_max(n,a);
//    printf("\nDia phuong nhieu nhat co %d (sinh vien)",max);
//	
    return 0;
}
