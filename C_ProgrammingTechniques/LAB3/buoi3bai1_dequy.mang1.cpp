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
void Nhapdequy(int *a, int n, int i=0){
	if(i==n)
		return ;
	scanf("%d", (a+i));
	Nhapdequy(a,n,i+1);
}
void Xuatdequy(int *a, int n, int i=0){

    if(i == n)
    	return ;
    printf("%d ", *(a+i));
    Xuatdequy(a,n,i+1);
}
int TinhS(int *a, int n){
    if (n==0)
        return *a;//a[0]
    else 
        return TinhS(a,n-1)+(*(a+n));
}

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
int tongle(int *a, int n)
{ //tong le dê quy
	if (n == 1)
	{
		if (*(a+(n-1)) % 2 != 0)
		{
			return *(a+0);
		}
		else
		{
			return 0;
		}
	}
	if (*(a+(n-1)) % 2 != 0)
	{
		return *(a+(n-1)) + tongle(a, n - 1);
	}
	else
		return 0 + tongle(a, n - 1);
}
int fibonacy(int n){
	if (n==1 || n==2){
		return 1;
	}
	return fibonacy(n-1)+fibonacy(n-2);
	
}


int main()
{
    int *a, n,i=0;
    printf("n = ");
    scanf("%d",&n);
    a= (int*)malloc(n*sizeof(int));
    
    Nhapdequy(a,n,i);
    Xuatdequy(a,n,i);
    
//    Nhap(a,n);
//    Xuat(a,n);
//    printf("\nTong la: %d",TinhS(a,n-1));
//    printf("\nGia tri lon nhat:%d", gtln(a,n));
//    printf("\nTong cac so le:%d",tongle(a,n));
//	//0 1 1 2 3 5 8 13 21 
//    printf("\nDay Fibonacy:%d",fibonacy(n));
    return 0;
}


