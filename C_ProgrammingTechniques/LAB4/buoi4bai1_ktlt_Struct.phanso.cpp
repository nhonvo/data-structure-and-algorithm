#include <stdio.h>
#include<math.h>
#include<conio.h>

typedef struct phanso{
    int tu;
    int mau;
} Ps;

void NhapPs(Ps &a){
    printf("Nhap phan so: ");
    scanf("%d%d", &a.tu,&a.mau);
}
void XuatPs(Ps a){
    printf("\t %d/%d ", a.tu,a.mau);
}
int UCLN(int a, int b){   
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; 
        }else{
            b -= a;
        }
    }
    return a; 
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
int main(){
    Ps a,b;
    NhapPs(a);
    NhapPs(b);
    XuatPs(toigian(a));
    XuatPs(toigian(b));
    
    Ps c= tong(a,b);
    printf("\nTong a v b:");
    XuatPs(toigian(c));
	Ps c1= hieu(a,b);
	printf("\nHieu a v b:");
	XuatPs(toigian(c1));
}

