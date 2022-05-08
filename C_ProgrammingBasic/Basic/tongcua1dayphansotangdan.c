#include<stdio.h>

float sum(float s){
	int n, i;
	s=0;
	i=1;
	printf("Enter number n= ");
	scanf("%d", &n);
		if(n==0){
		printf("ERROR. Enter again.");
		}else{
			
	while(i<=n){
		s+=1.0/i;
		i++;
	}
	printf("Sum of 1+ 1/2+ 1/3+...+1/2*%d-1= %f", n, s);
	}
}

int main(){
	float s;
	sum(s);
	return 0;
}
