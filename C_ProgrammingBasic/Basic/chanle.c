#include<stdio.h>

int chanle(int n){
	
	printf("nhap n=");
	scanf("%d", &n);
	int c, l;

		
		for(c=1; c<=n; c++){
			if(c%2==0){
			printf("%d\n", c);
			}		
		}	 			
		for(l=1; l<=n; l++){
			if(l%2!=0){
			printf("_%d", l);	
			}		
		}
	return n;
}


int main(){
	int n;
	chanle(n);
	return 0;
}
