#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h> 

void nhap(char *s){
	printf("Nhap chuoi:");
	gets(s);
}

void xuat(char *s){
	printf("\nChuoi da nhap:");
	puts(s);
}

int countcharacter(char *s, int l){
	int count= NULL;
	for (int i=0; i<l  ; i++ ){
		if(*(s+i) >='A' && *(s+i) <='Z' || *(s+i) >= 'a' && *(s+i) <= 'z'){
			count++;
		}
	}
	return count;
}

int countnumber(char *s, int l){
	int count= NULL;
	for (int i=0; i<l  ; i++ ){
		if(*(s+i) >='0' && *(s+i) <='9' ){
			count++;
		}
	}
	return count;
}

int wordcount(char *s, int l){
    int word = (*(s+0) != ' ');
    for (int i = 0; i < l; i++)
    {
        if (*(s+i) == ' ' && *(s+i+1) != ' ')
        {
            word++;
        }
    }
    return word;
}


int countsumnumberthay(char *s, int l){
	int n=0, i, j,sum = 0;
	char *temp;
	temp = (char *)malloc(sizeof(char));
	for (i=0; i<l; i++){
		j=0; *(temp+j)='\0';	//tao mang moi temp de gan
		while (*(s+i)>= '0' && *(s+i)<='9'&& i<l)//dk
			*(temp+j++) = *(s+i++);
		*(temp+j) = '\0' ;
		sum+=atoi(temp);
	}
	return sum;
}

char *wordlongest(char *s, int l){
    char *temp, *savemax;
    temp = (char *)malloc(sizeof(char));
    savemax = (char *)malloc(sizeof(char));
    int i,j, max=0;
    for (i=0; i<l; i++){
    	j=0;
    	while(*(s+i) != ' ' && i<l){
    		*(temp + j++) = *(s+i++);
		}
		*(temp +j )='\0';
		if(max < strlen(temp)){
			max =strlen(temp);
			strcpy(savemax, temp);
		}
	}
	return savemax;
}


int main() {
	char *s;
	s = (char *)malloc(sizeof(char));

	nhap(s);
	xuat(s);

	int l=strlen(s);	
	printf("\nSo luong phan tu trong chuoi:\t%d", countcharacter(s,l));
	printf("\nSo luong tu trong chuoi:\t%d", wordcount(s,l));
	printf("\nTong cac so trong chuoi:\t%d", countsumnumberthay(s,l));  
	printf("\nTu dai nhat trong chuoi:\t%s", wordlongest(s,l));
	wordlongest(s,l);
    getch();
	return 0;
}

