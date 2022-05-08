#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h> 

void nhap(char *s){
	printf("Nhap chuoi :");
	fflush(stdin);
	gets(s);
}

void xuat(char *s){
	printf("\nChuoi da nhap:");
	puts(s);
}

void noi_hai_chuoi(char *s1, char *s2){
	char *s3;
	s3= (char *)malloc(sizeof(char));
	strcpy(s3,s1);
	strcat(s3,s2);
	printf("\n%s",s3);
}
int check_s1s2(char *s1, char *s2){
	if(strlen(strstr(s1,s2))!=NULL){
		printf("\nCo");
	}else{
		printf("\nKhong");
	}
}
int check_s2s1(char *s1, char *s2){
	if(strlen(strstr(s2,s1))!=NULL){
		printf("\nCo");
	}else{
		printf("\nKhong");
	}
}
int main() {
	char *s1,*s2;
	s1 = (char *)malloc(sizeof(char));
	s2 = (char *)malloc(sizeof(char));
//a
	nhap(s1);
	nhap(s2);
//b
	xuat(s1);
	xuat(s2);
//c	
	printf("\nDo dai hai chuoi:");
	int l1=strlen(s1);
	printf("\nS1:%d",l1);
	int l2=strlen(s2);	
	printf("\nS2:%d",l2);
//d	
	if(strcmp(s1,s2)==0){
		printf("\nHai chuoi giong nhau");
		
		
	}else{
		printf("\nHai chuoi khac nhau");
	}
//e
	printf("\nHai chuoi duoc noi:");
	noi_hai_chuoi(s1,s2);
//f	
	printf("\nChuoi s1 co chua s2 khong: ");
	check_s1s2(s1,s2);
	printf("\nChuoi s2 co chua s1 khong: ");	
	check_s2s1(s1,s2);
    getch();
	return 0;
}

