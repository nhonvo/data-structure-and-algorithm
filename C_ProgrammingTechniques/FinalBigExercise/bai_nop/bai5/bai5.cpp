//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//Chu de 5_bai 5
#include <stdio.h>
#include <string.h>
#include <math.h>

FILE *f1,*f2;
int a[200][200];
int n,m,i,j;

//Cac ham 
bool checknt(int &n);
int dem_nguyen_to(int m,int n, int a[200][200]);
int tongcacpttrenmoidong(int a[200][200], int m, int n);
void Xuat(int a[][200], int m, int n);

int main(){
    f1 = fopen("TABLE.INP.txt","r");
    f2 = fopen("TABLE.OUT.txt","w");
//nhap
    fscanf(f1,"%d%d",&m,&n);
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        	fscanf(f1,"%d ", &a[i][j]);
//xuat
	printf("%d %d\n", m,n);   	
	Xuat(a,m,n);
//a
	int num_a = dem_nguyen_to(m,n,a);
	fprintf(f2,"Cau a: \n\tSo cac so nguyen to trong mang hai chieu: %d", num_a);
//b
	int num_b = tongcacpttrenmoidong(a,m,n);
	fprintf(f2,"\nCau b:\n\tGia tri lon nhat tren cac tong cua moi dong: ");
	fprintf(f2," %d", num_b);
	
    fclose(f1);
    fclose(f2);
    return 0;
}
//a
bool checknt(int &n)
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

int dem_nguyen_to(int m,int n, int a[200][200]){
	int dem=0;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
			if(checknt(a[i][j])){
				dem++;
			}
		}
	}
	return dem;
}
	
//b
int tongcacpttrenmoidong(int a[200][200], int m, int n){
	int i,j,sum=0;
	int b[100],k=0;
	int max=b[0];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
			sum+=a[i][j];
    	}
    	b[k++]=sum;
    	sum=0;
	}
	for(i=0;i<k;i++){
		if(b[i] > max){
			max = b[i];
		}
	}
	return max;
}
void Xuat(int a[][200], int m, int n){
    int i,j;
    printf("\nMang hai chieu la:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

