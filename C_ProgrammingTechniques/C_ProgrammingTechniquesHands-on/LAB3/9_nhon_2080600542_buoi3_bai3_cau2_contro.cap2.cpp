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
int tong(int **a, int m, int n){
	int sum=0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			sum+=	*(*(a+i)+j)	;
		}
	}
	return sum;
}
int main(){
	int **a,m,n,i;
	scanf("%d%d",&n,&m);
    a = (int **)malloc(m * sizeof(int *));//cac dong
    for (i = 0; i < m; i++)
    {
        *(a+i) = (int *)malloc(n*sizeof(int *));//côt
    }
	nhap(a,m,n);
	xuat(a,m,n);
	printf("\nTong:%d", tong(a,m,n)); 
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
	
}
