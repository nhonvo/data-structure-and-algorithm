#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
void nhap(int &n, int *a){
	do{
	printf("Nhap n:");
	scanf("%d",&n);
		if(n<=0||n>100){
			printf("ERROR\n");
		}
	}while(n<=0||n>100);
	
	for(int i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d", a+i);
	}
}

void xuat(int n,int *a){
    for(int i = 0;i < n; i++){
        printf("%4d", *(a+i));
    }
}
int tongbt(int n , int a[]){
	int sum=0;
	for(int i=0; i<n; i++){
		sum=sum+*(a+i);
	}
	return sum;	
}
int tong(int n , int a[]){
	int sum=0;
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			sum=sum + *(a+i);
		}
	}
	return sum;
}
bool check(int n){
	int dem=0;
	if(n==1||n==0){
		return 0;
	}
	for (int i=1; i<=n; i++){
		if(n%i==0){
			dem++;
		}
	}
	if(dem==2){
		return true;
	}else{
		return false;
	}
}
int tongnt(int n, int *a){
	int s=0;
	for (int i=0; i<=n; i++){	
		if(check(a[i])){
			s+=*(a+i);
		}
	}
	return s;	
}
int chan(int n, int *a){			//le, nt tuong tu
	for (int i=0; i<=n; i++){
		if(*(a+i)%2==0){
			printf("\nPhan tu chan dau:%d", *(a+i));
			return 0;
		}
	}
}
int chanlast(int n ,int *a){
	for (int i=n; i>0; i--){
		if(*(a+i)%2==0){
			printf("\nPhan tu chan cuoi:%d", *(a+i));
			return 0;
		}
	}
}
bool checkmot(int n){			//kiem tra chinh phuong
	int sqr=sqrt(n);
	if(sqr*sqr==n){
		return true;
	}else{
		return false;
	}
}
int chinhphuong(int n, int *a){
	for (int i=0; i<=n; i++){
		if(checkmot(a[i])){
			printf("\n%5d",*(a+i));	
		}
	}
}
int ThemPhanTu(int &n, int *a, int x, int vt){		//xoa them dau cuoi tt
    for(int i = n; i >= vt; i--){
        *(a+i)=*(a+i-1);
    }
    a[vt] = x;			//chua toi uu
    n++;
}
int main(){
	int n, *a,x,vt;
//	a =(int*)malloc(101);
	a= new int[100];
	nhap(n,a);
	
	scanf("\n%d%d",&x,&vt);
	ThemPhanTu(n,a,x,vt);
	xuat(n,a);
	return 0;
}
