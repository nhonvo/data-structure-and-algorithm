#include<stdio.h>

int main(){
	int n;
	printf("Enter even number n:");
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i=i+2)
	{printf("_%d",i);
	}
	if(n<=1){
		printf("having not even number");
	}
	

	return 0;
}
