#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

struct phanso{
	int tuso, mauso;
};
typedef struct phanso ps;

void nhap(ps *x){
	printf("Nhap tu so:"); scanf("%d", &x->tuso);
	do{
	printf("Nhap mau so:"); scanf("%d", &x->mauso);		
		if(x->mauso==0){
			printf("error");
		}
	}while(x->mauso==0);
}
void xuat(ps *x){
	printf("%d/%d", x->tuso, x->mauso);
}
int ucln(int a, int b){
	a=abs(a);b=abs(b);
	while(a!=b){
		if(a>b)
		{
			a=a-b;
		} 
		else
		{
			b=b-a;
		}
	}
	return a;
}
ps rutgon(ps *x){
	int c=ucln(x->tuso,x->mauso);
	x->tuso=x->tuso/c;
	x->mauso=x->mauso/c;
	return *x;
}
void nhapphanso(ps *a,int n){
	scanf("%d", &n);
	for (int i=0; i<n;i++){
		printf("Nhap phan so %d\n", i+1);
	nhap(&a[i]); 
	}
}
void xuatphanso(ps *a, int n){		//khong chay duoc ham xuat
printf("\ncac phan so vua nhap:\n");;
	for (int i=0; i<n;i++){
		printf("Phan so %d:", i+1);
		printf("Toi gian\n"); 
		rutgon(&*(a+i));
		xuat(a+i);	
	}
}

int main(){
	ps a[101];
	int n;
	nhapphanso(a,n);
//	xuat(a);
	xuatphanso(a,n);
	getche();
	//xuat trong ham main
//	for (int i=0; i<n;i++){
//		printf("Phan so %d:", i+1);
//		printf("\nToi gian"); 
//		rutgon(&*(a+i));
//		xuat(*(a+i));	
//	}
	
//	for (int i=0; i<n;i++){
//		printf("\nPhan so %d\n", i+1);
//		printf("\nToi gian\n"); 
//		rutgon(&a[i]);
//		xuat(a[i]);	
//	}
}
