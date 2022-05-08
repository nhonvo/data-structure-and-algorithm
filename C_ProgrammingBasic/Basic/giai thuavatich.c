#include<stdio.h>

int giaithua(int n){
	int i,s;
	s=1;

	for(i=1; i<=n; i++){
		s*=i;	
	}
	printf("%d!=1*2*3*...*%d=%d\n", n, n, s);
}

int tich(int n){
	int s,i,p;
	s=1;
	for(i=1; i<=n; i++){
		s*=i;
		p+=s;	
	}
	printf("P=1+1*2+1*2*3+...+1*2*3*%d=%d\n", n, p);
	
}
int main(){
	int m;
	printf("nhap vao m!=");
	scanf("%d", &m);
	giaithua(m);
	
	int n;
	printf("nhap vao n!=");
	scanf("%d", &n);
	tich(n);

	return 0;
}
