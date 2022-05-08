#include<stdio.h>


int main(){
	int n, a[10000];
	int i;
	printf("nhap so pt cua mang n=");
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		printf("cac so a[%d]:", i);
		scanf("%d", &a[i]);
	}
	
//tinh tong cac so chan co trong mang
	int s=0;
	
	for(i=1; i<=n; i++){
		if(a[i]%2==0){
			s+=a[i];
		}
	}
	printf("s=%d", s);
	return 0;
}
