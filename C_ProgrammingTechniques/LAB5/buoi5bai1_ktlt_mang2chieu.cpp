#include <stdio.h>
#include<conio.h>

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
int xuat(int n, int a[100])
{
    for(int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

int tongcacpttrenmoidong(int a[100][100], int n,int m, int array[100],int dem){
	int i,j,sum=0;
	dem=0;
	int count=-1;
    for(i=0;i<n;i++){
    	count++;
        for(j=0;j<m;j++){
			if(i==count){
				sum+=a[i][j];
			}   
    	}
    	array[dem++]=sum;
    	sum=0;
	}
	xuat(dem,array);
}
int tongcacpttrenmoicot(int a[100][100], int n,int m, int array[100],int dem){
	int i,j,sum=0;
	dem=0;
	int count=-1;
    for(i=0;i<n;i++){
    	count++;
        for(j=0;j<m;j++){
			if(j==count){
				sum+=a[i][j];
			}   
    	}
    	array[dem++]=sum;
    	sum=0;
	}
	xuat(dem,array);
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
	int i,j;
	for (i = 0; i < n; i++){
		for(j =0; j<m; j++){
			if (checknt(a[i][j])==true&&i%2!=0){
				printf("\n---dong %d :",i);
				printf("\t%d---",a[i][j]);
			}
		}
	}
}

int main()
{
    int n,m;
    int a[100][100];
    printf("Nhap dong(n), cot(m) = ");
    scanf("%d%d",&n,&m);
    Nhap(a,n,m);
    Xuat(a,n,m);
	int array_1[100];
	int dem_1;
    printf("\nTong cac phan tu tren moi dong:");
    tongcacpttrenmoidong(a,n,m,array_1,dem_1);
	int array_2[100];
	int dem_2;
    printf("\nTong cac phan tu tren moi cot:");
    tongcacpttrenmoicot(a,n,m,array_2,dem_2);    
    
    printf("\nCac so nguyen to tren cac dong le:");
    nguyento(a,n,m);
    
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
}
