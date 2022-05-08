//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//CHU DE 7-bai 5
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>


struct sinhvien{
	char tenlop[10];
	int siso;
	char hoten_gvcn[50];
	int soluong_hs_gioi;
	int soluong_hs_kha;
	int soluong_hs_trungbinh;
	int soluong_hs_yeu;
};
typedef sinhvien sv;
//Cac ham TRONG BAI
void nhap (sv&x );
void nhapSV(int n, sv a[]);
void xuat(sv x);
void xuatSV(int n, sv a[]);
void xuat_file_f1(sv x,FILE *f1);
void xuat_file_f2(sv x,FILE *f2);
void xuatSV_file_f1(int n, sv a[],FILE *f1);
void xuatSV_file_f2(int n, sv a[],FILE *f2);
void xuat_hsg(int n, sv a[]);
int max_hs_dequy(int n, sv a[]);
int hsg_nhieu_nhat(int n, sv a[]);
void tim_gv(int n, sv a[], char ten_gv[]);
void xoa_ds(int &n, sv a[]);
void swap(int &a, int &b);
int partition(int a[], int left, int right);
void quicksort(int arr[], int left, int right);
int tim_kiem(int n, sv a[], int b,FILE *f2);
void sap_Xep_tang_siso(int n, sv a[], FILE *f2);

int main(){
	sv a[101];
	int n,key;
	FILE *f1, *f2;
	f1 = fopen ("lophoc.inp", "w");
	f2 = fopen ("lophoc.out", "w");
	bool daNhap = false;
	while(true){
		system("cls");
		printf("******************************************************************************************************\n");
        printf("**    CHUONG TRINH QUAN LY LOP CUA MOT TRUONG - truongnhon-2080600542                               **\n");
        printf("**      1. (a1) Nhap danh sach cac lop va luu thong tin vao lophoc.inp                              **\n");
        printf("**     	2. (a2)Xuat danh sach cac lop                                                               **\n");
        printf("**      3. (b)In danh sach lop co tren 5 hoc sinh gioi                                              **\n");
        printf("**      4. (c)Tim lop co nhieu hoc sinh nhat(de quy)                                                **\n");
        printf("**      5. (d)Tim lop co so luong hoc sinh dat loai gioi nhieu nhat                                 **\n");
        printf("**      6. (e)Nhap ten giao vien cho biet thong tin lop gia vien phu trach(neu co)                  **\n");
        printf("**      7. (f)Xoa khoi danh sach cac lop co so hoc sinh yeu nhieu hon 1/2 si so                     **\n");
        printf("**      8. (g)Sap xep danh sach cac lop tang dan theo si so bang quick sort va luu vao lophoc.out   **\n");
        printf("**      0. Thoat chuong trinh                                                                       **\n");
        printf("******************************************************************************************************\n");
        printf("**       Nhap so nhu huong dan o tren                                                               **\n");
        scanf("%d",&key);
			switch(key){
			    case 1:
			        printf("\nBan da chon nhap DS cac lop  va luu thong tin vao lophoc.inp !");
					do{
						printf("\nNhap so luong sinh vien:");
						scanf("%d", &n);
						if(n<=0||n>100){
							printf("\nSai! So luong sinh vien phai nam trong khoang --- n<=0||n>100--\nLam on thu lai. ");
						}
					}while(n<=0||n>100);
					nhapSV(n,a);			    	    
			        printf("\nBan da nhap thanh cong!");
			        daNhap = true;
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
			    case 2:
			        if(daNhap){
			            printf("\nBan da chon xuat DS cac lop(file va xuat ra man hinh)!");
//			        a--Xuat vao file va xuat ra man hinh
						fprintf(f1, "\n\t\tDANH SACH LOP DUOC XUAT VAO FILE: \n");
						xuatSV_file_f1(n,a,f1);
						rewind(f1);
						rewind(f2);
						printf("\n\n---Xuat danh sach: \n");
						xuatSV(n,a);
						printf("\n---------------------\n");		            
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
			    case 3:
			        if(daNhap){
			            printf("\nBan da chon (b)In danh sach lop co tren 5 hoc sinh gioi!");
//					b--In danh sach lop co tren 5 hoc sinh gioi
						printf("\n\n---b) Danh sach cac lop co nhieu hon 5 hoc sinh gioi: \n");
						xuat_hsg(n,a);
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
			    case 4:
			        if(daNhap){
			            printf("\nBan da chon (c)Tim lop co nhieu hoc sinh nhat(de quy)!");
//					c--(c)Tim lop co nhieu hoc sinh nhat(de quy)
						int num_c = max_hs_dequy(n,a);
						printf("\n\n---c)Danh sach cac lop co nhieu hoc sinh nhat: ");
						for(int i=0;i<n;i++){
							if(a[i].siso==num_c){
								xuat(a[i]);
							}
						}						
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
			        
			    case 5:
					if(daNhap){
						printf("\nBan da chon (d)Tim lop co so luong hoc sinh dat loai gioi nhieu nhat!");
//					d--(d)Tim lop co so luong hoc sinh dat loai gioi nhieu nhat 
						int num_d = hsg_nhieu_nhat(n,a);
						printf("\n\n----d) Danh sach cac lop co nhieu hoc sinh gioi nhat: ");
						for(int i=0;i<n;i++){
							if(a[i].soluong_hs_gioi==num_d){
								xuat(a[i]);
							}
						}
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
				case 6:
					if(daNhap){
						printf("\nBan da chon (e)Nhap ten giao vien cho biet thong tin lop gia vien phu trach(neu co)!");
//				e--(e)Nhap ten giao vien cho biet thong tin lop gia vien phu trach(neu co) 
						char num_e[100]; 
						printf("\n----e)Nhap ten giao vien can tim: ");
						fflush(stdin);
						gets(num_e);
						tim_gv(n,a,num_e);						
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
			    case 7:
					if(daNhap){
						printf("\nBan da chon (f)Xoa khoi danh sach cac lop co so hoc sinh yeu nhieu hon 1/2 si so!");
//				f--(f)Xoa khoi danh sach cac lop co so hoc sinh yeu nhieu hon 1/2 si so  
						printf("\n---f)Danh sach sinh vien sau khi xoa(so hs yeu > 1/2 si so): ");
						xoa_ds(n,a);
						xuatSV(n,a);
						
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
				case 8:
					if(daNhap){
						rewind(f1);
						printf("\nBan da chon (g)Sap xep danh sach cac lop tang dan theo si so bang quick sort va luu vao lophoc.out!");
//					g--(g)Sap xep danh sach cac lop tang dan theo si so bang quick sort va luu vao lophoc.out 
						fprintf(f2, "\n\t\tDANH SACH LOP DUOC XUAT VAO FILE: \n");
						printf("\n---g)Danh sach cac lop tang dan theo si so (quick_sort): ");
						fprintf(f2, "\n---g)Danh sach cac lop tang dan theo si so (quick_sort): ");	
						sap_Xep_tang_siso(n,a,f2);
			        }else{
			            printf("\nNhap DS SV truoc!!!!");
			        }
			        printf("\nBam phim bat ky de tiep tuc!");
			        getch();
			        break;
				
			    case 0:
			    	fclose(f1);
					fclose(f2);
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

//nhap_1
void nhap (sv&x ){
	printf("\nNhap ten lop: ");
	fflush(stdin);
	gets(x.tenlop);
	printf("\nNhap si so: ");
	scanf("%d", &x.siso);
	printf("\nNhap ho va ten gvcn: ");
	fflush(stdin);
	gets(x.hoten_gvcn);
	printf("\nNhap so luong hoc sinh gioi: ");
	scanf("%d", &x.soluong_hs_gioi);
	printf("\nNhap so luong hoc sinh kha: ");
	scanf("%d", &x.soluong_hs_kha);
	printf("\nNhap so luong hoc sinh trung binh: ");
	scanf("%d", &x.soluong_hs_trungbinh);
	printf("\nNhap so luong hoc sinh yeu: ");
	scanf("%d", &x.soluong_hs_yeu);
}
//nhap nhieu
void nhapSV(int n, sv a[]){	
	for (int i=0; i<n;i++){
		printf("\n");
		printf("Nhap sinh sien thu %d:",i+1);
		nhap(a[i]);
	}
}
//xuat 1
void xuat(sv x){
	printf("\nTen lop: %s", 					x.tenlop);
	printf("\nSi so: %d",						x.siso);
	printf("\nHo va ten gvcn: %s", 				x.hoten_gvcn);
	printf("\nSo luong hoc sinh gioi: %d", 		x.soluong_hs_gioi);
	printf("\nSo luong hoc sinh kha: %d", 		x.soluong_hs_kha);
	printf("\nSo luong hoc sinh trung binh: %d",x.soluong_hs_trungbinh);
	printf("\nSo luong hoc sinh yeu: %d", 		x.soluong_hs_yeu);
}
//xuat nhieu
void xuatSV(int n, sv a[]){
	for (int i=0; i<n;i++){
		printf("\n\n---So thu: %d---",i+1);
		xuat(a[i]);	
	}
}
	//a//
//xuat_1_file
void xuat_file_f1(sv x,FILE *f1){
	fprintf(f1,"\nTen lop: %s",						x.tenlop);
	fprintf(f1,"\nSi so: %d", 						x.siso);
	fprintf(f1,"\nHo va ten gvcn: %s", 				x.hoten_gvcn);
	fprintf(f1,"\nSo luong hoc sinh gioi: %d", 		x.soluong_hs_gioi);
	fprintf(f1,"\nSo luong hoc sinh kha: %d", 		x.soluong_hs_kha);
	fprintf(f1,"\nSo luong hoc sinh trung binh: %d",x.soluong_hs_trungbinh);
	fprintf(f1,"\nSo luong hoc sinh yeu: %d", 		x.soluong_hs_yeu);
}
void xuat_file_f2(sv x,FILE *f2){
	fprintf(f2,"\nTen lop: %s", 					x.tenlop);
	fprintf(f2,"\nSi so: %d", 						x.siso);
	fprintf(f2,"\nHo va ten gvcn: %s", 				x.hoten_gvcn);
	fprintf(f2,"\nSo luong hoc sinh gioi: %d", 		x.soluong_hs_gioi);
	fprintf(f2,"\nSo luong hoc sinh kha: %d", 		x.soluong_hs_kha);
	fprintf(f2,"\nSo luong hoc sinh trung binh: %d",x.soluong_hs_trungbinh);
	fprintf(f2,"\nSo luong hoc sinh yeu: %d", 		x.soluong_hs_yeu);
}
//xuat_nhieu_file
void xuatSV_file_f1(int n, sv a[],FILE *f1){
	for (int i=0; i<n;i++){
		fprintf(f1,"\n\t---So thu %d---",i+1);
		xuat_file_f1(a[i],f1);
		printf("\n");
	}
	
}
void xuatSV_file_f2(int n, sv a[],FILE *f2){
	for (int i=0; i<n;i++){
		fprintf(f2,"\n\t---So thu %d---",i+1);
		xuat_file_f2(a[i],f2);	
		fprintf(f2,"\n");
	}
}
	//b//
//ds 5 hs gioi
void xuat_hsg(int n, sv a[]){
	for(int i=0; i<n;i++){
		if(a[i].soluong_hs_gioi > 5){
			xuat(a[i]);
		}
	}
}
	//c//
//lop nhieu hs nhat_de quy
int max_hs_dequy(int n, sv a[]){
	if(n == 1){
		return a[0].siso;
	}
	if(n==0){
		return 0;
	}
	if(max_hs_dequy(n-1,a)>a[n-1].siso){
		return max_hs_dequy(n-1, a);
	}else{
			printf("%d\n", n-1);
		return a[n-1].siso;
	}
}
	//d//
//lop co hsg nhieu nhat
int hsg_nhieu_nhat(int n, sv a[]){
	int max=-1;
	for(int i=0; i<n;i++){
		if(a[i].soluong_hs_gioi > max){
			max = a[i].soluong_hs_gioi;
		}
	}
	return max;
}
	//e//
//nhap ten gv tim thong tin
void tim_gv(int n, sv a[], char ten_gv[]){
	for(int i=0; i<n;i++){
		if(strcmp(a[i].hoten_gvcn, ten_gv) == 0){
			xuat(a[i]);
		}
	}
}
	//f//
//xoa ds if (hs.yeu> 1/2 h )
void xoa_ds(int &n, sv a[]){
	int flag=0;
	for(int i=0; i<n;i++)
		if(a[i].soluong_hs_yeu > (a[i].siso / 2)){
			flag = 1;
			for(int j=0; j<n;j++){
				a[j]=a[j+1];
					n--;
				printf("\nDa xoa lop %s ", a[j].tenlop);
				break;
			}
		}	

	if(flag == 0){
		printf("\nKhong co lop can xoa");
	}
}
	//g
//sap xep tang dan theo si so = quick sort.
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int partition(int a[], int left, int right)
{
	int i = left;
	int j = right - 1;	  
	int pivot = a[right]; 
	while (true)
	{
		while (pivot > a[i] && i <= j)
			i++;
		while (pivot < a[j] && i <= j)
			j--;
		if (i >= j)
		{
			break;
		}
		else
		{
			swap(a[i], a[j]); 
			i++;
			j--;
		}
	}
	swap(a[i], a[right]); 
	return i;
}
void quicksort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pi = partition(arr, left, right); 
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}
int tim_kiem(int n, sv a[], int b,FILE *f2){
	sv c[100];
	for(int i=0; i<n;i++){
		if(b==a[i].siso){
			xuat(a[i]);
			xuat_file_f2(a[i],f2);
		}
	}
}
void sap_Xep_tang_siso(int n, sv a[], FILE *f2){
	int b[100], k=0;
	for(int i=0; i<n;i++){
		b[k++]=a[i].siso;
	}
	quicksort(b, 0, n-1);
	
	for(int i=0; i<n;i++){
		tim_kiem(n,a,b[i],f2);
	}
}




