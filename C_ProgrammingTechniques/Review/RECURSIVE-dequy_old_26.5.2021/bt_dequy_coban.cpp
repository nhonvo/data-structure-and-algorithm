
#include<stdio.h>

int giaithua(int n){
	if ( n==1 ){
		return 1;
	}
	return n * giaithua(n-1);
}
int fibonacy(int n){
	if (n==1 || n==2){
		return 1;
	}
	return fibonacy(n-1)+fibonacy(n-2);
	
}
int ucln(int a , int b){
	if( a*b==0){
		return 1;
	}if(a>b){
		return ucln(a-b,b);
	}if(a<b){
		return ucln(a,b-a);
	}
}

static int count = 0;
  
void loop() {
    count++;
    if (count <= 5) {
        printf("loop %d \n", count);
        loop();
    }
}
int tongle(int n){
	if( n==1){
		return 1;
	}
	if( n%2!=0){
		return tongle(n-1);
	}
	if( n%2==0){
		return n-1+tongle(n-2);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d", tongle(n));
	fibonacy(n);
	return 0;
}
