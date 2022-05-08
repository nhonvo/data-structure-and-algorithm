//Vo Thuong Truong Nhon
//20DTHD4
//2080600542
//bai 5 chu de 6

#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

void nhap(int a[100][100], int n);
void Xuat(int a[100][100], int n);
void xuat(int n, int a[100]);
int partition(int **a, int left, int right);
void quicksort(int **arr, int left, int right);
void ss_chan_chinh_tang(int a[100][100], int n );
bool check_ht(int &a);
void ss_chan_phu_tang(int a[100][100], int n );
void tang_cot(int a[100][100], int n );
void sap_xep_dong_noibot(int n,int a[100][100]);
int partition_c(int **a, int left, int right);
void quicksort_c(int **arr, int left, int right);
void sap_xep_cac_cot_tangdan(int a[100][100], int n );


int main(){

    int n ;
    int a[100][100];
		 
    printf("Nhap ma tran vuong n = ");
    scanf("%d",&n);
	nhap(a,n);
    Xuat(a,n);
    
//a
	printf("\n\ta>Sap xep cac phan tu chan tren duong cheo chinh tang dan: ");
	ss_chan_chinh_tang(a,n);
	Xuat(a,n);
//b
	printf("\n\tb>Sap xep cac phan tu hoan thien tren duong cheo phu giam dan: ");
	ss_chan_phu_tang(a,n);	
	Xuat(a,n);
//c
	printf("\n\tc>Sap xep cac phan tu tang dan tren moi cot: ");
	sap_xep_cac_cot_tangdan(a,n);
	Xuat(a,n);
	return 0;
}

void nhap(int a[100][100], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("a[%d][%d]=",i,j);
			scanf("%d", &a[i][j]);
		}
	}
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

int partition(int **a, int left, int right){
	
	int i = left-1;
	int pivot = *a[right]; 
	for(int j = left; j<= right-1; j++){
		if(*a[j]<pivot){
			i++;
			int x=*a[i];
            *a[i]=*a[j];
            *a[j]=x;
		}
	}
	int x=*a[i+1];
    	*a[i+1]=*a[right];
    	*a[right]=x;
	return (i+1);
}
void quicksort(int **arr, int left, int right){
	
	if (left < right){
		
		int pi = partition(arr, left, right); 
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}

//a
void ss_chan_chinh_tang(int a[100][100], int n ){
	int i,j,k=0;
	int **b = new int*;
    for(i=0;i<n;i++){
		if(a[i][i]%2==0){
			b[k++]=&a[i][i];
		}	
	}
	quicksort(b,0,k-1);
}
//b
int partition_b(int **a, int left, int right){
	
	int i = left-1;
	int pivot = *a[right]; 
	for(int j = left; j<= right-1; j++){
		if(*a[j]>pivot){
			i++;
			int x=*a[i];
            *a[i]=*a[j];
            *a[j]=x;
		}
	}
	int x=*a[i+1];
    	*a[i+1]=*a[right];
    	*a[right]=x;
	return (i+1);
}
void quicksort_b(int **arr, int left, int right){
	
	if (left < right){
		
		int pi = partition_b(arr, left, right); 
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}
bool check_ht(int &a){
	int i=1,s=0;
	while(i<=a/2){
		if(a%i==0){
			s+=i;
		}
		i++;
	}
	if(s==a)
		return true;
	return false;
}

void ss_chan_phu_tang(int a[100][100], int n ){
	int i,j,k=0;
	int **b = new int*;
    for(i=0;i<n;i++){
		if(check_ht(a[i][n-i-1])){
			b[k++]=&a[i][n-i-1];
		}	
	}
	quicksort_b(b,0,k-1);
}
//c

int partition_c(int **a, int left, int right){
	
	int i = left-1;
	int pivot = *a[right]; 
	for(int j = left; j<= right-1; j++){
		if(*a[j]<pivot){
			i++;
			int x=*a[i];
            *a[i]=*a[j];
            *a[j]=x;
		}
	}
	int x=*a[i+1];
    	*a[i+1]=*a[right];
    	*a[right]=x;
	return (i+1);
}
void quicksort_c(int **arr, int left, int right){
	
	if (left < right){
		
		int pi = partition(arr, left, right); 
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}

void sap_xep_cac_cot_tangdan(int a[100][100], int n ){
	int i,j,k=0;
	int **b = new int*;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			b[k++]= &a[i][j];
		}
	quicksort_c(b,0,k-1);	
	k = 0;
	}
}




