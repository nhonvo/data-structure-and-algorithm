#include<stdio.h>

int main(){
	float s=0;
	int n;
	scanf("%d", &n);				
	for(int i=1;i<=n;i++){
		if(n%i==0){
			printf("%d",i)
		}
		s+=i;
	}
	printf("Tong uoc:%f",s);
	return 0;
}






