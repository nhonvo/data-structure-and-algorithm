#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h> 
#include<ctype.h>

void nhap(char *s){
	printf("Nhap chuoi :");
	fflush(stdin);
	gets(s);
}

void xuat(char *s){
	printf("\nChuoi da nhap:");
	puts(s);
}
int viet_hoa(char *s, int l){
    for (int i = 0; i < l; i++)    
        if (*(s+i) == ' ' && *( s+i+1 ) != ' '){
        	*( s+i+1 )=toupper(*( s+i+1 ));
		}else{
			*( s+i+1 )=tolower(*( s+i+1 ));
		}
        
        *(s+0)=toupper(*(s+0));
    printf("\nHo & ten viet hoa:");
    for (int i = 0; i < l; i++)
    	printf("%c",*(s+i));
}
int main() {
	char *s1;
	s1 = (char *)malloc(sizeof(char));
	nhap(s1);
	xuat(s1);
	int l= strlen(s1);
	viet_hoa(s1,l);
    getch();
	return 0;
}

