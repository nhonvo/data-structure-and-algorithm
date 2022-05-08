#include <stdio.h>
#include<math.h>
#include<conio.h>

typedef struct phanso{
    int tu;
    int mau;
} Ps;

void NhapPs(Ps &a){
    scanf("%d%d", &a.tu,&a.mau);
}
void XuatPs(Ps a){
    printf("\t %d/%d ", a.tu,a.mau);
}
int UCLN(int a, int b){   
    if (a == 0 || b == 0){
        return a + b;
    }
	while (a*b != 0){ 
        if (a > b){
            a %= b; 
        }else{
            b %= a;
        }
    }
    return a + b;
}

Ps toigian(Ps &a){
	Ps c;
	c.tu=a.tu /UCLN(a.tu,a.mau);
	c.mau = a.mau/UCLN(a.tu,a.mau);
	return c;
}

Ps tong(Ps &a, Ps &b){
	Ps c;
	c.tu=b.mau*a.tu+b.tu*a.mau;
	c.mau=a.mau*b.mau;
	toigian(c);
	return c;
}

Ps hieu(Ps &a, Ps &b){
	Ps c;
	c.tu=b.mau*a.tu-b.tu*a.mau;
	c.mau=a.mau*b.mau;
	toigian(c);
	return c;
}
Ps tich(Ps &a, Ps &b){
	Ps c;
	c.tu=a.tu*b.tu;
	c.mau=a.mau*b.mau;
	toigian(c);
	return c;
}
void sosanh(Ps a, Ps b){
	Ps c;
	float a1= a.tu/a.mau, a2=b.tu/b.mau;
		if(a1>a2)
		{
			printf("\nphan so a>b");
		}
	
		else
		{
		printf("\nphan so a<b");		
		}
}

void nhap(int n, Ps a[])
{
	int i=0;
	while (i<n)
	{
		printf("Nhap phan so thu %d: ",i);
		NhapPs(a[i]);
		i++;
	}
}
void xuat(int n, Ps a[])
{
	int i=0;
	while(i<n)
	{
		XuatPs(a[i]);
		i++;
	}
}
void tong(int n, Ps a[])
{
	
}
int main(){
    Ps a,b;
    printf("Nhap phan so a: ");
    NhapPs(a);
    printf("Nhap phan so b: ");
    NhapPs(b);
    XuatPs(toigian(a));
    XuatPs(toigian(b));
    
    Ps c= tong(a,b);
    printf("\nTong a v b:");
    XuatPs(toigian(c));
	Ps c1= hieu(a,b);
	printf("\nHieu a v b:");
	XuatPs(toigian(c1));
	printf("\nTich a v b: ");
	Ps c2 =tich(a,b);
	XuatPs(toigian(c2));
	sosanh(a,b);
	int n;
	Ps aa[100];
	printf("\nNhap so luong phan so: "); scanf("%d", &n);
	nhap(n ,aa);
	xuat(n,aa);
}

