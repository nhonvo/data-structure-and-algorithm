//#include<stdio.h>
//
//int main(){
//	float s=0;
//	int n;
//	scanf("%d", &n);					b1
//	for(int i=1;i<=n;i++){
//		s=s+1.0/i;
//	}
//	printf("%f",s);
//	return 0;
//}
#include<stdio.h>

int main(){
	float s=0,u=0;
	int n,i=1;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		s=s+i;								//b3
		u=u+1.0/s;
	}
//while(i<=n){
//	s*=i;								b2
//	u+=s;
//	i++;
//}
	printf("%f",u);
	return 0;
}
