#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void nhap(int **a, int m, int n);
void xuat(int **a, int m, int n);
int Max(int **a, int m, int n);

int main(){
	int **a,m,n,i;
	scanf("%d%d",&m,&n);
    a = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int *));
    }
	nhap(a,m,n);
	xuat(a,m,n);
	printf("\n%d",Max(a,m,n));
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
int Max(int **a, int m, int n){
	int max=*(*(a+0)+0);
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (*(*(a+i)+j)>max){
				max=*(*(a+i)+j);
			}	
		}
	}
	return max;
}
