#include<stdio.h>

void nhap(int &n, int a[]){
	do{
	printf("Nhap n:");
	scanf("%d",&n);
		if(n<=0||n>100){
			printf("ERROR\n");
		}
	}while(n<=0||n>100);
	
	for(int i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int n,int a[]){
    for(int i = 0;i < n; i++){
        printf("%4d", a[i]);
    }
}
int ThemPhanTu(int &n, int a[], int x, int vt){
    for(int i = n; i >= vt; i--){
        a[i] = a[i-1];
    }
    a[vt] = x;
    n++;
}
int xoaPT(int &n, int a[], int vt){
	for(int i=vt; i<n; i++){
		a[i]=a[i+1];
	}
	n--;
}
int xoaPTam(int &n, int a[]){
	int vt;
	for(int i=0; i<n; i++){
		if(a[i]<0){
			xoaPT(n,a,i);
			i--;							//tai sao phai giam vt ???
		}
	}
}
int xoaPTtrung(int &n, int a[]){
	int vt;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[i]==a[j]){
				xoaPT(n,a,i);
				i--;				//có dòng nay thì mat han pt trùng
			}
		}
	}
}
int xoaPTtrunggiualai1pt(int &n, int a[]){
	int vt;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[i]==a[j]){
				xoaPT(n,a,j);
				j--;						//tai sao thay i  =j thì giua lai 1 pt
			}
		}
	}
}
int main(){
	int n,a[1001];
	nhap(n,a);
	int x, vt;
    printf("\nNhap so can them: ");
    scanf("%d", &x);
    printf("\nNhap vi tri muon chen: ");
    scanf("%d", &vt);
    ThemPhanTu( n, a,x, vt);
	xoaPTtrung(n,a);
    printf("\nMang sau khi them: ");
    XuatMang(n,a);
}
