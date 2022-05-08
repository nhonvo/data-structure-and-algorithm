#include <stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

typedef struct phanso{
    int tu;
    int mau;
}ps;

void Nhapps(ps *a){
    printf("Nhap phan so: ");
    scanf("%d%d", &a->tu,&a->mau);
}
void Xuatps(ps *a){
    printf("\t %d/%d ", a->tu,a->mau);
}
void nhap_1Day(int n, ps *a){
	for(int i=0;i<n;i++){
		Nhapps((a+i));
	}
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
ps *toigian(ps *a){
	ps *c;
	c->tu  = a->tu  /UCLN(a->tu,a->mau);
	c->mau = a->mau /UCLN(a->tu,a->mau);
	return c;
}
void xuat_1Day(int n, ps *a){
	for(int i=0;i<n;i++){
		Xuatps((a+i));
	}
}



//a
ps *tong_2(ps *x, ps *y){
	ps *z;
	z = (ps*)malloc(sizeof(ps));
	z->tu = x->tu*y->mau+y->tu*x->mau;
	z->mau = x->mau*y->mau;
	return z;
}
ps *tong_day(int n, ps *a){
	ps *b=(a+0);
	
	for(int i=1; i<n;i++){
		b = tong_2(b,a+i);
	}
	return (b);
}
//b-max
int max_ps(int n, ps *a){
	float max = (float)(a+0)->tu/(a+0)->mau;
	int max_vt;
	for (int i =0; i<n; i++){
		if(max < (float)(a+i)->tu/(a+i)->mau){
			max_vt = i;
		}
	}
	return max_vt;
}
int main(){
    ps *a;
    int n;
    printf("Nhap n=:");
    scanf("%d",&n);
    a=(ps*)malloc(n*sizeof(ps));
  
	nhap_1Day(n,a);
  	printf("\nDay phan so: ");
    xuat_1Day(n,a);
    printf("\nTong %d phan so: ", n);
    Xuatps(tong_day(n,a));
	
//b
	int num_b = max_ps(n,a);
	printf("\nVi tri cua phan so lon nhat: %d", num_b );
	max_ps(n,a);
}


