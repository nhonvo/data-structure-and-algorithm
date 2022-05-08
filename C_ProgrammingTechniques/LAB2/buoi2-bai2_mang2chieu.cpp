#include <stdio.h>
#include<conio.h>
														// bai 2 ma tran 2 chieu buoi-2 ktlt
int a[100][100];
//khai báo hàm

void Nhap(int a[100][100], int n, int m);
void Xuat(int a[100][100], int n, int m);


void Nhap(int a[100][100], int n, int m){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
}

void Xuat(int a[100][100], int n, int m){
    int i,j;
    printf("\nMang hai chieu la:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

int maxcell(int a[100][100], int n, int m){
    int i,j,max=a[0][0];
    int row=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(a[i][j]>max){
				max=a[i][j];
			}            
    	}
	}
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	if(max==a[i][j]){
        		row = j;
			}
		}
	}
	printf("\nCot   %d    chua ptu lon nhat la:\t%d", row, max);

}

int minrow(int a[100][100], int n, int m){
    int i,j,min=a[0][0];
    int cell;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(a[i][j]<=min){
				min=a[i][j];
			}            
    	}
	}

	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	if(min==a[i][j]){
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

void nguyento(int a[100][100], int n, int m){
	//in ra hang co so nguyen to lon nhat
	int i,j;
	int cellmax =0, cell;
	for (i = 0; i < n; i++)
	{
		for(j =0; j<m; j++){
			if (checknt(a[i][j])&&a[i][j]!=0&&a[i][j]!=1)
			{
				cellmax=a[i][j];
				if (cellmax<a[i][j]){
					cellmax=a[i][j];
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for(j =0; j<m; j++){
			if(cellmax==a[i][j]){
				cell=i;
			}
		}
	}
	printf("\nHang %d chua so nguyen to lon nhat la :\t%d", cell, cellmax);
}
int main()
{
    int n,m;
    printf("Nhap dong(n), cot(m) = ");
    scanf("%d%d",&n,&m);
    Nhap(a,n,m);
    Xuat(a,n,m);
    
    maxcell(a,n,m);
    minrow(a,n,m); 
	nguyento(a,n,m);   
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
}
