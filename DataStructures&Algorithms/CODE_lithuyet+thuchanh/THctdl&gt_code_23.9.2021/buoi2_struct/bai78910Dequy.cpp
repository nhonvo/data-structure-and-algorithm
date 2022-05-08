#include <stdio.h>
#include<math.h>
int giaithua(int n){
	if(n == 1)
		return n;
	return giaithua(n-1) *n;
}
int bai5(int n){
	if(n == 1)
		return n;
	return bai5(n-1) + n*n*n;
}
int bai6(int n){
	if(n == 1)
		return -1;
	int a= bai6(n-1);
	return n*pow(-1,n) +a;
}
float bai7(int n){
	if(n == 1)
		return 1.0/2;
	return float(n)/float(n-1) + bai7(n-1);
}
int bai8(int n){
	if( n== 1){
		return 6;
	}
	return n*(n+1)*(n+2)+bai8(n-1);
}
float bai9(int n)
{
	if(n==1)
		return 0.5;
	return 1.0/float(n*(n+1))+bai9(n-1);
}
int main(){
	int n;	scanf("%d", &n);printf("\n%d | %d | %d | %.2f", giaithua(n), bai5(n),bai6(n), bai7(n));
	printf("\n%d| %.2f", bai8(n), bai9(n));
}
