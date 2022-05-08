#include <stdio.h>
#include <stdlib.h>
	int k=1;

int ucln(int a, int b){
    if (b == 0) return a;
    if (a % b == 0) return b;
    return ucln(b, a%b);
}

int bcnn(int a,int b){
	if(a<b){
		if(b%a==0) return b;
		else {
			k++;
			bcnn(a,b*k);
		}
	}else{
		if(a%b==0) return a;
		else {
			k++;
			bcnn(a*k,b);
		}
	}
}

int main(){
	int a,b;
	a=5;
	b=10;
	printf("\nUoc chung lon nhat: %d", ucln(a,b));
	printf("\nBoi chung nho nhat: %d", bcnn(a,b));	
	
}
