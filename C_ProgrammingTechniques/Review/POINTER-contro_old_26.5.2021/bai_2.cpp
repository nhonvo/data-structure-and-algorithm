#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
long tinhtong(int **a, int m , int n){
	int s=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			s=s+ *(*(a+i)+j);
		}
	}
	return s;
}
long tinhtongchan(int **a, int m , int n){			//tinh tong le tt
	int s=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (*(*(a+i)+j)%2==0){
				s=s+ *(*(a+i)+j);
			}
		}
	}
	return s;
}
bool check(int n){
	int dem=0;
	if(n==1||n==0){
		return 0;
	}
	for (int i=1; i<=n; i++){
		if(n%i==0){
			dem++;
		}
	}
	if(dem==2){
		return true;
	}else{
		return false;
	}
}
long tinhtongnt(int **a, int m , int n){
	int s=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(check(*(*(a+i)+j))){
				s=s+ *(*(a+i)+j);
			}
		}
	}
	return s;
}
long tinhtongdcchinh(int **a, int m , int n){
	int s=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(i==j){
				s=s+ *(*(a+i)+j);
			}
		}
	}
	return s;
}
long tinhtongdcphu(int **a, int m , int n){
	int s=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(j==n-i-1){
				s=s+ *(*(a+i)+j);
			}
		}
	}
	return s;
}
void freearray(int **a, int m){
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}
int main(){
	int **a=NULL, m, n,i;
	scanf("%d%d",&m,&n);
    a = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int *));
    }
	nhap(a,m,n);
	xuat(a,m,n);
	int s=tinhtongdcphu(a,m,n);
	printf("\nTong:%d", s);
	freearray(a,m);
    return 0;
}
