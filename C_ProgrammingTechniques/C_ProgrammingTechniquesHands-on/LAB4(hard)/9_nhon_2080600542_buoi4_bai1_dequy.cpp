#include <stdio.h>
#include <stdlib.h>

void Nhap(int *a, int n){
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
        Nhap(a,n);
}

void Xuat(int *a, int n){
    printf("\n----------------\n");
    for(int i=0;i<n;i++)
        printf("%d ",*(a+i));
}
//a
void Nhapdequy(int *a, int n, int i=0){
	if(i==n)
		return ;
	scanf("%d", (a+i));
	Nhapdequy(a,n,i+1);
}
//b
void Xuatdequy(int *a, int n, int i=0){

    if(i == n)
    	return ;
    printf("%d ", *(a+i));
    Xuatdequy(a,n,i+1);
}
//c
int TinhS(int *a, int n){
    if (n==0)
        return *a;//a[0]
    else 
        return TinhS(a,n-1)+(*(a+n));
}


//d
int tongchan(int *a, int n){ 
	if (n == 1)
	{
		if (*(a+(n-1)) % 2 == 0)
		{
			return *(a+0);
		}
		else
		{
			return 0;
		}
	}
	if (*(a+(n-1)) % 2 == 0)
	{
		return *(a+(n-1)) + tongchan(a, n - 1);
	}
	else
		return 0 + tongchan(a, n - 1);
}
//e
int dem_duong(int *a, int n){ 
	if (n==0)
        return 0;
	if (*(a+(n-1)) > 0)	{
		return 1+ dem_duong(a, n - 1);
	}else{
		return dem_duong(a,n-1);
	}
}
//f-1
int gtln(int *a, int n)
{
	if (n == 1)
	{
		return *(a+0);
	}
	if (gtln(a, n - 1) > *(a+n-1))
	{
		return gtln(a, n - 1);
	}
	else
	{
		return *(a+n-1);
	}
}
//f-2

int gtnn(int *a, int n){
	if (n == 0)
		return -1;
	if (n == 1)
		return *(a+0);
	else
	{
		if (*(a+n-1) < gtnn(a, n - 1))
			return *(a+n-1);
		else
			return gtnn(a, n - 1);
	}
}
//g 
int timchan_cuoi(int *a, int n){
	if(n==1){
		if(*(a+n-1)%2==0){
			return *(a+0);
		}
	}
	if(*(a+n-1)%2==0){
		return *(a+n-1);
	}else{
		return timchan_cuoi(a,n-1);
	}
}
//h
int tim_pt(int *a, int n, int x){
	if (n == 1 && x!= *(a+n-1))
		return 0;
	if(*(a+n-1)==x){
		return n;
	}else{
		return tim_pt(a,n-1,x);
	}	
}

int main()
{
    int *a, n,i=0;
    printf("n = ");
    scanf("%d",&n);
    a= (int*)malloc(n*sizeof(int));
    
    Nhapdequy(a,n,i);
    Xuatdequy(a,n,i);
    
//    printf("\nSo so duong la: %d",dem_duong(a,n-1));
    printf("\nGia tri nho nhat: %d", gtnn(a,n));
// g
//	printf("\nChan cuoi la: %d", timchan_cuoi(a,n));
//h
	int k;
	printf("\nNhap x =");
	scanf("%d",&k);
	printf("\nVi tri: %d",tim_pt(a,n,k));
//cau2
    printf("\nTinh day Fibonacy:%d",fibonacy(n));
    return 0;
}



