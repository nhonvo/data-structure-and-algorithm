#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(){
	char name[10];
	char sex[3];
	printf("Name:");
	scanf("%s", &name);
	printf("Gioi tinh:"); fflush(stdin); gets(sex);
	int n=strlen(name);
	for(int i=0;i<n;i++){
		printf("%d", n);
	}
printf("Name:%s", name);
printf("Sex:%s", sex);
}
