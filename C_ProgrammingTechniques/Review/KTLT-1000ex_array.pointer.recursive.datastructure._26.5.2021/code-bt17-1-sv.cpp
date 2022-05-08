#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>

//them cap nhat danh sach
//sua lai xuat sinh vien 
//
struct tinhdiem{
	char ten[10];
	char MSSV[9];
	float diemtoan, diemanh, diemtin, diemtrungbinh;
	char gioitinh[1];
};
typedef tinhdiem td;


void nhap (td&x);
void nhapSV (int &n, td a[]);
void xuat(td x);
void xuatSV(int n, td a[]);
int diemtb(td x);
void xeploai(td x);
int sapxep(int n, td a[]);
int xoaSV(int n, char MSSVcanxoa[10] ,td a[]);
void search(int n, char tenctim[30],td a[]);
int xuatfile(int n, td a[], char filename[]);


int main(){																	// MAIN function here
	td a[101];
	char filename[]="text.txt";
	int n,key;
	bool daNhap=false;
	printf("CHUONG TRINH QUAN LI SINH VIEN HUTECH created by truongnhon");
	while (true){
		system("cls");
        printf("**********************************************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN HUTECH created by truongnhon   **\n");
        printf("**      1. Nhap du lieu												**\n");
        printf("**     	2. Xuat danh sach sinh vien									**\n");
        printf("**      3. Sap xep sinh vien theo DTB							    **\n");
        printf("**      4. Xuat DS sinh vien xuat file 								**\n");
        printf("**      5. Tim kiem sinh vien theo MSSV								**\n");
        printf("**      6. Xoa sinh vien theo MSSV									**\n");
        printf("**      0. Thoat													**\n");
        printf("**********************************************************************\n");
        printf("**       Nhap so nhu huong dan o tren   							**\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS sinh vien!");
                nhapSV(n,a);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuatSV(n,a);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep SV theo STB!");
                    sapxep(n,a);
					xuatSV(n,a);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon xuat DS SV!");
					xuatfile(n,a,filename);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nXuat DSSV thanh cong vao file %s!", filename);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
                
            case 5:
				if(daNhap){
					char tenctim[30];
					printf("\nNhap ten SV can tim:");fflush(stdin);
					gets(tenctim);
                    printf("\nBan da chon tim kiem theo ten!");
                    search(n,tenctim,a);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
			
			case 6:
				if(daNhap){
					char MSSVcanxoa[10];
                    printf("\nBan da chon xoa sinh vien theo MSSV!");
					xuatSV(n,a);
					printf("\nNhap MSSV can xoa:");fflush(stdin);
					gets(MSSVcanxoa);
					xoaSV(n,MSSVcanxoa, a);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
			
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}

void nhap (td&x ){
	printf("\nTen:");
	fflush(stdin);
	gets(x.ten);
	printf("\nMSSV:");
	gets(x.MSSV);
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
	
	printf("\nDiem toan:");
	scanf("%f", &x.diemtoan );
	printf("\nDiem anh:");
	scanf("%f", &x.diemanh );
	printf("\nDiem tin:");
	scanf("%f", &x.diemtin );
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
	
	printf("\n____________________________________\n");
	printf("\nTen:%s",x.ten);
	printf("\nMSSV:%s",x.MSSV);
	if(strcmp(x.gioitinh,"x")==0){
		printf("\nGioi tinh:nam");
	}else if(strcmp(x.gioitinh,"y")==0){
		printf("\nGioi tinh:nu");
	}
	printf("\nDiem toan:%.3f",x.diemtoan);
	printf("\nDiem anh:%.3f",x.diemanh);
	printf("\nDiem tin:%.3f",x.diemtin);
//	diemtb da xuat trong ham xeploai
	xeploai(x);
	printf("\n____________________________________\n");
}
void xuatSV(int n, td a[]){
	
	for (int i=0; i<n;i++){
		printf("\nSinh sien thu %d:",i+1);
		xuat(a[i]);	
	}
}

int diemtb(td x){
	x.diemtrungbinh=(x.diemtin+x.diemtoan+x.diemanh)/3;
	printf("\nDiem trung binh:%.3f", x.diemtrungbinh);
	return x.diemtrungbinh;
}

void xeploai(td x){
	x.diemtrungbinh =diemtb(x);
	printf("\nSinh vien xep loai:");
	
	if(x.diemtrungbinh>=8)		printf("Gioi");
	else if(x.diemtrungbinh>=6.5)		printf("Kha");
	else if(x.diemtrungbinh>=4)		printf("Trung binh");
	else		printf("Yeu");
}
int swap(td &a, td &b){
	td tmp = a;
    a = b;
    b = tmp;
}
int sapxep(int n, td a[]){
	td tmp;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(a[i].diemtrungbinh>a[j].diemtrungbinh){
				swap(a[i], a[j]);
			}
		}
	}
}
int sapxeptheoten(int n, td a[]){
	
	char SV1[30], SV2[30];
	int i,j;
	for (i=0;i<n;i++){
		strcpy(SV1,a[i].ten);
		for(j = 0; j < n-1; j++){
			strcpy(SV2,a[j].ten);
			if(strcmp( strupr(SV1), strupr(SV2)) > 0){
				swap(a[i],a[j]);
			}
		}
	}
}

void search(int n, char tenctim[30],td a[]){
	td SVtimthay[101];
	int timthay = 0;
	char tenSV[30];
	char SV[30];
	for(int i=0;i<n;i++){
		strcpy(tenSV, a[i].ten);
		if(strstr(strupr(tenSV), strupr(SV))){
			SVtimthay[timthay] = a[i];
			timthay++;
		}
	}
	xuatSV(timthay, SVtimthay);
}

int xoaSV(int n, char MSSVcanxoa[10] ,td a[]){
	int i,j;
	int flag = 1;
	for (i=0;i<n;i++){
		if(strcmp(a[i].MSSV, MSSVcanxoa) == 0){
			flag =1;
			for(j=i;j<n;j++)
				a[j] = a[j+1];
			printf("Da xoa sinh vien co MSSV:%s", MSSVcanxoa);
			break;
		}
	}
	if(flag == 0){
		printf("/nKhong co sinh vien can xoa");
		return 0;
	}else{
		return 1;
	}
}

int xuatfile(int n, td a[], char filename[]){
	FILE *fptr;
	
	fptr= fopen(filename,"w");
	fprintf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n","ten","MSSV","gioitinh","diemtoan","diemanh","diemtin","diemtrungbinh");
	for (int i=0;i<n;i++){
		fprintf(fptr,"%s\t%s\t%s\t\t%.3f\t%.3f\t%.3f\t%.3f\n",a[i].ten,a[i].MSSV,a[i].gioitinh,a[i].diemtoan,a[i].diemanh,a[i].diemtin,a[i].diemtrungbinh);
	}
	fclose(fptr);
}
