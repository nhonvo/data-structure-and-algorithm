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

int maxcell(int **a, int n, int m){
    int i,j,max=*(*(a+0)+0);
    int row=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(*(*(a+i)+j)>max){
				max=*(*(a+i)+j);
			}            
    	}
	}
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	if(max==*(*(a+i)+j)){
        		row = j;
			}
		}
	}
	printf("\nCot   %d    chua ptu lon nhat la:\t%d", row, max);

}

int minrow(int **a, int n, int m){
    int i,j,min=*(*(a+0)+0);
    int cell;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(*(*(a+i)+j)<=min){
				min=*(*(a+i)+j);
			}            
    	}
	}

	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	if(min==*(*(a+i)+j)){
        		cell = i;
			}
		}
	}
	    printf("\nHang    %d     chua ptu be nhat la:\t%d", cell , min); 
}
bool checknt(int n)
{
	int dem = 0;
	if (n < 2)
	{
		return false;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				dem++;
			}
		}
		if (dem == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void nguyento(int **a, int n, int m){
	//in ra hang co so nguyen to lon nhat
	int i,j;
	int cellmax =0, cell;
	for (i = 0; i < n; i++)
	{
		for(j =0; j<m; j++){
			if (checknt(*(*(a+i)+j))&&*(*(a+i)+j)!=0&&*(*(a+i)+j)!=1)
			{
				cellmax=*(*(a+i)+j);
				if (cellmax<*(*(a+i)+j)){
					cellmax=*(*(a+i)+j);
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for(j =0; j<m; j++){
			if(cellmax==*(*(a+i)+j)){
				cell=i;
			}
		}
	}
	printf("\nHang %d chua so nguyen to lon nhat la :\t%d", cell, cellmax);
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
	    
    
    maxcell(a,n,m);
    minrow(a,n,m); 
	nguyento(a,n,m);   
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
	
}
