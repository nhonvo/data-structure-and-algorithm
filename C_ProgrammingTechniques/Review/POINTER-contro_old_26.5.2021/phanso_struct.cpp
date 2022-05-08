#include<stdio.h>
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
void xuat(ps x){
	printf("%d/%d", x.tuso, x.mauso);
}

//rutgon(a);rutgon(b);
int main(){
	ps a,b;
	printf("Nhap a\n");
	nhap(&a); printf("Toi gian\n"); xuat(a);
	//1
	printf("\nNhap b\n");
	nhap(&b); printf("Toi gian\n"); xuat(b);
	//2
	/*printf("\nTong hai so:");//++
	ps s=tong(a,b); xuat(s);
	printf("\nHieu hai so:");//--
	ps s1=hieu(a,b); xuat(s1);	
	printf("\nTich hai so:");	//**
	ps s2=tich(a,b); xuat(s2);
	printf("\nThuong hai so:");	// //
	ps s3=thuong(a,b); xuat(s3);
	printf("\n");// ss
	sosanh(a,b);*/

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
ps rutgon(ps&x){
	int c=ucln(x.tuso,x.mauso);
	x.tuso=x.tuso/c;
	x.mauso=x.mauso/c;
	return x;
}
ps tong(ps a,ps b){
	ps tong;
	tong.tuso=a.tuso*b.mauso+b.tuso*a.mauso;
	tong.mauso=a.mauso*b.mauso;
	rutgon(tong);
	return tong;
}
ps hieu(ps a, ps b){
		ps hieu;
	hieu.tuso=a.tuso*b.mauso-b.tuso*a.mauso;
	hieu.mauso=a.mauso*b.mauso;
	return hieu;
}
ps tich(ps a, ps b){
		ps tich;
	tich.tuso=a.tuso*b.tuso;
	tich.mauso=a.mauso*b.mauso;
		rutgon(tich);
	return tich;
}
ps thuong(ps a, ps b){
		ps thuong;
	thuong.tuso=a.tuso*b.mauso;
	thuong.mauso=a.mauso*b.tuso;
		rutgon(thuong);
	return thuong;
}
ps sosanh(ps a, ps b){
	if(a.tuso*b.mauso>b.tuso*a.mauso){ printf("1>2");}
	else if(a.tuso/a.mauso==b.tuso*b.mauso){printf("1=2");}
	else{printf("1<2");} 

}
