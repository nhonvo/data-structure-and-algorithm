//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//bai 1 buoi 1

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
int tongptu(int a[100][100], int n, int m){
    int i,j,tong=0;
    int row=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			tong+=a[i][j];           
    	}
	}
	return tong;
}

int trungbinhcong(int a[100][100], int n, int m){
    int i,j,tong=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			tong+=a[i][j];    
    	}
	}
	int k=(tong/(n*m));
	return k;
}

int trungbinhcongduong(int a[100][100], int n, int m){
    int i,j,tong=0,dem=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(a[i][j]>0){
				tong+=a[i][j];
				dem++;
			}            
    	}
	}
	int k=(tong/dem);
	return k;
}
void xuatdong(int a[100][100], int n, int m, int k){
	int i,j,tong=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(k==i){
				printf("\t%d", a[i][j]);
			}   
    	}
	}
}

int tongcot(int a[100][100], int n, int m, int k){
	int i,j,tong=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(k==j){
				tong+=a[i][j];
			}   
    	}
	}
	return tong;
}

int ptulonnhat(int a[100][100], int n, int m){
    int i,j,max=a[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
			if(a[i][j]>max){
				max=a[i][j];
			}            
    	}
	}
	return max;
}

int main()
{
    int n,m;
    int a[100][100];
    printf("Nhap dong(n), cot(m) = ");
    scanf("%d%d",&n,&m);
    Nhap(a,n,m);
    Xuat(a,n,m);
    
    printf("\nTong cac phan tu :%4d", tongptu(a,n,m));
    printf("\nTrung binh cong cac phan tu:%4d", trungbinhcong(a,n,m));
    printf("\nTrung binh cong cac phan tu duong:%4d", trungbinhcongduong(a,n,m));
    int k,b[100][100],p,o;
	printf("\nNhap dong k(0->%d):",m-1);
	scanf("%d", &k);
	printf("Cac phan tu nam tren dong %d la:", k);
	xuatdong(a,n,m,k);
	printf("\nNhap cot k(0->%d):",n-1);
	scanf("%d", &k);
	printf("Tong cac phan tu nam tren cot %d:%4d", k,tongcot(a,n,m,k));
	printf("\nPhan tu lon nhat:%4d", ptulonnhat(a,n,m));
	
    printf("\n\n\t\tEnter something to stop!");
	getch();
    return 0;
}
//truongnhon
