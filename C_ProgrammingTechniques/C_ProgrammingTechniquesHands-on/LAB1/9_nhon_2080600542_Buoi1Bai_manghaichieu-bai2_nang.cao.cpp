//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//bai 1 buoi 1

#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

void random(int a[100][100], int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			a[i][j]=rand()%10;
}

void Xuat(int a[100][100], int n){
    int i,j;
    printf("\nMang hai chieu la:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
void xuat(int n, int a[100])
{
    for(int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

int tongdongk(int a[100][100], int n, int k){
	int i,j,sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			if(k==i){
				sum+=a[i][j];
			}   
    	}
	}
	return sum;
}
/*
1 2
3 4
*/
int tongcacpttrenmoidong(int a[100][100], int n, int array[100],int dem){
	int i,j,sum=0;
	dem=0;
	int count=-1;
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
			sum+=a[i][j];
	}
   	array[dem++]= sum;
	sum=0;
	}
	return dem;
}
int cacdongcotonglonnhat(int a[100][100], int n, int array[100], int dem ){
	int mangkethua[100];
	int max=mangkethua[0];
	dem=0;
	int demkethua =tongcacpttrenmoidong(a,n,mangkethua,demkethua);
	for(int i=0; i<demkethua;i++){
		if(mangkethua[i]>max){
			max= mangkethua[i];
		}
	}
//	printf("\nTong lon nhat: %d",max);
	for(int j=0; j<demkethua;j++){
		if(max==mangkethua[j]){
			array[dem++]=j;
		}
	}
	return dem;
}
int lietkecheochinh(int a[100][100], int n, int cheochinh[100], int dem ){
	int i,j;
	dem=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			if(i==j){
				cheochinh[dem++]=a[i][j];
			}	
		}
	}
	return dem;
}
int lietkecheophu(int a[100][100], int n, int cheophu[100], int dem ){
	int i,j;
	dem=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			if(i+j==n-1){
				cheophu[dem++]=a[i][j];
			}	
		}
	}
	return dem;
}
int main()
{
    int n;
    int a[100][100]= {{1,2},
			{3,4}};
    printf("Nhap ma tran vuong n = ");
    scanf("%d",&n);
//	random(a,n);
    Xuat(a,n);
    
    int cheochinh[100];
    printf("\nCac phan tu tren duong cheo chinh:");
    int dem= lietkecheochinh(a,n,cheochinh,dem);
    xuat(dem,cheochinh);
    
    int cheophu[100];
    printf("\nCac phan tu tren duong cheo phu:");
	int count =lietkecheophu(a,n,cheophu,dem);
    xuat(count, cheophu);
    
    
	int b[100][100],k;
	printf("\nNhap dong can tinh tong:");
	scanf("%d", &k);
	int sum =tongdongk(a,n,k);
	printf("\nTong dong %d can tinh la:%d", k, sum );
	
	int array[100];
	printf("\nTong cac dong la:");
	int tinh = tongcacpttrenmoidong(a,n,array,tinh);
	xuat(tinh,array);
	
	int mangcaucuoi[100];
	printf("\nCac dong co phan tu lon nhat:");
	int demcaucuoi=cacdongcotonglonnhat(a,n,mangcaucuoi,demcaucuoi);
	xuat(demcaucuoi,mangcaucuoi);
	
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
}
//truongnhon
