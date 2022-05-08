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

void nhap (int n, int a[])
{
    
    for(int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &a[i]);
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
int phantuduongdautien(int n,int a[]){
	int duong_first=-1;
	for(int i=0;i<n;i++){
		if (a[i]>0){
			duong_first=a[i];
			break;
		}
	} 
	return duong_first;
}
//d 
int phantuduongcuoicung(int n,int a[]){
	int duong_last=-1;
	for(int i=n-1;i>=0;i--){
		if (a[i]>0){
			duong_last=a[i];
			break;
		}
	} 
	return duong_last;
}

//e
int phantulonnhat(int n,int a[]){
	int max=0;
	for(int i=0;i<n;i++){
		if (a[i]>max){
			max=a[i];
		}
	} 
	return max;
}
//f
int sophantulonnhat(int n,int a[]){
	int max=0,dem=0;
	for(int i=0;i<n;i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(max==a[i]){
			dem++;
		}
	}
	return dem;
}
//g
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
//h  
int ThemPhanTuvaodaumang(int &n, int a[], int gtCanthem){
    for(int i = n; i > 0 ; i--){
        a[i] = a[i-1];
    }
	a[0]=gtCanthem;
    n++;
}
//i
int ThemPhanTu(int &n, int a[], int x, int vt){
    for(int i = n; i > vt; i--){
        a[i] = a[i-1];
    }
    a[vt] = x;
    n++;
}
//j  
int XoaPhanTudaumang(int &n, int a[]){
    for(int i = 0; i < n -1; i++){
        a[i] = a[i+1];
    }
    n--;
}

//k
int xoaPT(int &n, int a[], int vt){
	for(int i=vt; i<n -1; i++){
		a[i]=a[i+1];
	}
	n--;
}
//l

int mangsole(int n, int a[]){
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			return 1;
		}
	}
	return 0;
}
//m
void mangmoichuasochantaisudung(int n, int a[], int &k, int mangmoi[]){
	k=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			mangmoi[k++]=a[i];	
		}
	}
	
}
int main(){
	int n,a[MAX];
	n = nhapn();
	
	nhap(n,a);
	xuat(n,a);
	printf("\nPhan tu duong dau tien:    %d", phantuduongdautien(n,a));
	printf("\nPhan tu duong cuoi cung:   %d", phantuduongcuoicung(n,a));
	printf("\nPhan tu duong lon nhat:    %d", phantulonnhat(n,a));

	int ko = vtphantulonnhat(n,a);
	if(ko!=100){
		printf("\nVi tri phan tu lon nhat:%4d va so do la :%4d",ko, a[ko]);
	}else{
		printf("\nMang nay toan so am!");
	}
	printf("\nSo phan tu lon nhat:       %d", sophantulonnhat(n,a));
	
	int x, vt, y;
    
	printf("\nNhap so can them vao mang a[]: ");
    scanf("%d", &y);
    printf("\nNhap vi tri muon chen(0<vt<%d): ", n-1);
    scanf("%d", &vt);
    ThemPhanTu( n, a, y, vt);
    printf("\nMang sau khi them: ");
	xuat(n,a);
	
	printf("\nNhap so can them vao dau mang a[]: ");
    scanf("%d", &x);
    ThemPhanTuvaodaumang(n,a,x);
    printf("\nThem %d vao dau mang:",x);
	xuat(n,a);
	
	printf("\nNhap vi tri muon xoa(0<=vt<=%d): ",n-1);
    scanf("%d", &vt);
	printf("\nMang sau khi xoa phan tu o vi tri %d:",vt);
	xoaPT(n,a,vt);
	xuat(n,a);
	printf("\nMang sau khi xoa phan tu dau tien:");
	XoaPhanTudaumang(n,a);
	xuat(n,a);
	
	int lee = mangsole(n,a);
	if(lee==1){
		printf("\nMang chua so le!");
	}else{
		printf("\nMang khong chua so le!");
	}
	
	int o[101];
	int k;
	mangmoichuasochantaisudung(n,a,k,o);
	printf("\nMang chua cac phan tu chan a[]: ");
	xuat(k,o);
	
	
	printf("\nTap somethings to stop!");
    getch();
}
//truongnhon
