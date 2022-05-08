
#include <stdio.h>
#include <stdlib.h>

int tim_pt(int *a, int n, int x){
	if (n == 1 && x!= *(a+n-1))
		return 0;
	if(*(a+n-1)==x){
		return n;
	}else{
		return tim_pt(a,n-1,x);
	}	
}
int tim_pt_khong_dequy(int *a, int n, int x){
	for(int i=0;i<n;i++){
		if(a[i]==x){
			return i+1;
		}
	}
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
int main()
{
    int *a, n,i=0;
    printf("n = ");
    scanf("%d",&n);
    a= (int*)malloc(n*sizeof(int));
    
    Nhapdequy(a,n,i);
    Xuatdequy(a,n,i);
    
	int k;
	printf("\nNhap x =");
	scanf("%d",&k);
	printf("\nVi tri: %d",tim_pt(a,n,k));

	printf("\nTim kiem khong de quy: %d", tim_pt_khong_dequy(a,n,k));
    return 0;
}


