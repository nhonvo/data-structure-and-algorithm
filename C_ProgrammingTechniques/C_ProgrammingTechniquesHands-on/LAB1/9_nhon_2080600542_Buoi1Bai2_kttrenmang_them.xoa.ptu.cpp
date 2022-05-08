//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//bai 1 buoi 1

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

int nhapn(){
	int n;
	do
    {
        printf("\nNhap so phan tu: ");
        scanf("%d", &n);
        if(n <= 0 || n > MAX)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    }while(n <= 0 || n > MAX);
}
bool checktrung(int n, int a[], int giatri){
	for(int i = 0; i < n; i++){
		if(a[i]==giatri)
			return true;
	}
	return false;
}
void nhap (int n, int a[])
{
    int temp=0;
    for(int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &temp);
        if(checktrung(i,a,temp)== true ){
        	printf("\nPhan tu bi trung nhap lai!!");
        	i--;
		}else{
			a[i] =temp;
		}
    }
}

void xuat(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}
//c
bool check(int a){
	int n= sqrt(a);
	if(n*n==a)
		return true;
	return false;
}
int chinhphuongvtle(int n, int a[], int &k, int tong[]){
	k=0;
	for (int i = 0; i < n; i++){
		if(check(a[i])&&(i%2!=0)){
			tong[k++]=a[i];
		}
	}
	return k;
}
//d
int vtphantulonnhat(int n,int a[]){
	int max=0,vt;
	for(int i=0;i<n;i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(max==a[i]){
			vt=i;
		}
	} 
	return vt;
}

//e1

int amlonnhat(int n, int a[])
{
	int max=1,i,j,k;
	for (int i = 0; i < n; i++)
	{
		if(a[i] < 0){
			max =a[i];
			k=i;
			break;
		}
	}
	for (int j=k+1;j<n;j++){
		if(a[j] < 0 && a[j] > max){
			max =a[j];
		}
	}
	return max;
}
//e2

int duongnhonhat(int n, int a[])
{
	int min=-1,i,j,k;
	for (int i = 0; i < n; i++)
	{
		if(a[i] >0){
			min =a[i];
			k=i;
			break;
		}
	}
	for (int j=k+1;j<n;j++){
		if(a[j] > 0 && a[j]<min){
			min =a[j];
		}
	}
	return min;
}
//f
int tongnamvtchan( int n, int a[])
{
	int tong=0;
	for (int i = 0; i < n; i++)
	{
		if(i%2==0){
			tong+=a[i];
		}
	}
	return tong;
}

void HoanVi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//g
int sapxepmangtangdan( int n, int a[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                HoanVi(a[i], a[j]);
            }
        }
    }
}

int main(){
	int n,a[MAX];
	n = nhapn();
	
	nhap(n,a);
	xuat(n,a);
	int k, tong[100];
//
	if(chinhphuongvtle(n,a,k,tong)!=0){
		printf("\nCac so chinh phuong nam tai vi tri le trong mang:");
		
		chinhphuongvtle(n,a,k,tong);
		xuat(k,tong);
	}else{
		printf("\nKhong co so chinh phuong nam o vi tri le!!");
	}
//
	printf("\nVi tri phan tu lon nhat:%4d",vtphantulonnhat(n,a));
//
	if(duongnhonhat(n,a)!=-1){
		printf("\nPhan tu duong nho nhat:    %d", duongnhonhat(n,a));
	}else{
		printf("\nMang khong co so duong!!");
	}
	//
	if(amlonnhat(n,a)!=1){
		printf("\nPhan tu am lon nhat:    %d", amlonnhat(n,a));
	}else{
		printf("\nMang khong co so am!!");
	}
	//
	printf("\nTong phan tu nam o vi tri chan trong mang:\t%d", tongnamvtchan(n,a));
	printf("\nSap xep mang theo thu tu tang dan:");
	sapxepmangtangdan(n,a);
	xuat(n,a);
	printf("\nTap somethings to stop!");
    getch();
}
//truongnhon
