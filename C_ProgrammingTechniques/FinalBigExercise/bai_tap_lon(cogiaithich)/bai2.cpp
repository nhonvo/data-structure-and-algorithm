//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//Chu de 2_bai 5

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

void Nhap(int a[100][100], int m, int n);
void Xuat(int a[100][100], int m, int n);
bool check_a(int &a);
int so_hoan_thien(int a[100][100], int m, int n);
int gtln_nhonhat_dong(int a[100][100], int m, int n);
int gtnn_lonhat_cot(int a[100][100], int m, int n);
bool check_cot(int a[][100],int m, int j);
void liet_ke_tangdan(int a[100][100], int m, int n);

int main()
{
    int n,m;
    int a[100][100];
    printf("Nhap dong (m>0), cot(n<=200) = ");
    scanf("%d%d",&m,&n);
    
    Nhap(a,m,n);
    Xuat(a,m,n);
//a -- 6 28 496 --
	
	int num =so_hoan_thien(a,m,n);
	printf("\nSo cac so hoan thien trong ma tran: %d",num);

//b
	int  num_b = gtln_nhonhat_dong(a,m,n);
	printf("\nGia tri lon nhat trong cac phan tu nho nhat: %d", num_b);
//c
	int num_c = gtnn_lonhat_cot(a,m,n);
	printf("\nGia tri nho nhat trong cac phan tu lon nhat: %d", num_c);	
//d
	printf("\nCot duoc sap xep tang dan");
	liet_ke_tangdan(a,m,n);

    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
}

void Nhap(int a[100][100], int m, int n){
    int i,j;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
		}
	}
}

void Xuat(int a[100][100], int m, int n){
    int i,j;
    printf("\nMang hai chieu la:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
//a
bool check_a(int &a){
	int i=1,s=0;
	while(i<=a/2){
		if(a%i==0){
			s+=i;
		}
		i++;
	}
	if(s==a)
		return true;
	return false;
}
int so_hoan_thien(int a[100][100], int m, int n){
    int i,j,dem=0;
    printf("\nCau a:");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
			if(check_a(a[i][j])==true){
				dem++;
			}  	
		}
    }
    return dem;
}
//b
int gtln_nhonhat_dong(int a[100][100], int m, int n){
    int i,j;
	int min=1000;
	int max=-1;
    int b[100],k=0;
     printf("\nCau b:");
    for(i=0;i<m;i++){
		max = -1;
    	for(j=0;j<n;j++){
			if(a[i][j]>max){
				max=a[i][j];
			}
		}
		b[k++]=	max;//phai de ngoai vong lap thu nhat vi neu de trong se khong lay dc cai nho nhat trong hang
	}
	b[k]='\0';
	for(i=0;i<n;i++){
		if(b[i]<min){
			min=b[i];
		}
	}
	return min;
}
//c
int gtnn_lonhat_cot(int a[100][100], int m, int n){
    int i,j;
	int min=1000;
	int max=-1;
    int b[100],k=0;
     printf("\nCau c:");
    for(j=0;j<n;j++){
		min = 1000;
    	for(i=0;i<m;i++){
			if(a[i][j]<min){
				min=a[i][j];
			}
		}
		b[k++]=	min;
	}
	b[k]='\0';
	for(i=0;i<n;i++){
		if(b[i]>max){
			max=b[i];
		}
	}
	return max;
}
//d-liet ke cac cot co thu tu tang dan

bool check_cot(int a[][100],int m, int j){
	int i;
		for(i=0;i<m-1; i++){//kiem tra cac ptu tren cot
			if(a[i][j]>=a[i+1][j]){//kiem tra neu khong tang dan thi sai
				return false;
			}
		}
		return true;
}
void liet_ke_tangdan(int a[100][100], int m, int n){
    for(int i=0;i<n;i++){
    	if(check_cot(a,m,i)){
    		printf(" %d ",i);
		}
	}
}


//truongnhon
