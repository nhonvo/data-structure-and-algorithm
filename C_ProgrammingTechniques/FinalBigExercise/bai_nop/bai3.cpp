//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//Chu de 3_bai 5

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void nhap(int **a, int m, int n);
void xuat(int **a, int m, int n);
bool check_a(int &a);
int dem_hoan_chinh(int **a, int m, int n);
void tong_dong(int **a, int m, int n);

int main(){
	int **a,m,n,i;
    printf("Nhap dong(m), cot(n) = ");	
	scanf("%d%d",&m,&n);
    a = (int **)malloc(m * sizeof(int *));//cac dong
    for (i = 0; i < m; i++)
    {
        *(a+i) = (int *)malloc(n*sizeof(int *));//côt
    }

	nhap(a,m,n);
	xuat(a,m,n);
//a	
	int num_a = dem_hoan_chinh(a,m,n);
	printf("\nSo luong so hoan chinh: %d", num_a);
//b
	printf("\nTong cac phan tu tren moi dong:");
	tong_dong(a,m,n);	
	
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
}

void nhap(int **a, int m, int n){
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			printf("a[%d][%d]=",i,j);
			scanf("%d", &*(*(a+i)+j));
		}
	}
}

void xuat(int **a, int m, int n){
	printf("Cac phan tu cua mang:\n");
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			printf("%5d", *(*(a+i)+j));
		}
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
	if(s==a){
		return true;
	}else{
		return false;		
	}

}
int dem_hoan_chinh(int **a, int m, int n){
	int dem=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(check_a(*(*(a+i)+j))==true){
				dem++;
			}
		}
	}
	return dem;
}
//b
void tong_dong(int **a, int m, int n){
	int s=0;
	int *b;
	int k=0;
	for (int i=0; i<m; i++){
		s=0;
		for (int j=0; j<n; j++){
			s+=*(*(a+i)+j);
		}
		printf(" %d ", s);
	}
}

