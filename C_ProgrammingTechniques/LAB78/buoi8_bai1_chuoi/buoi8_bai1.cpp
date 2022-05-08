#include <stdio.h>
#include <string.h>

FILE *f1,*f2;
char s1[102];

int dem;

//a

int xoa_khoang(char s[], int l){
    for (int i = 0; i < l; i++)
    {
        if (s[i] == ' ' &&s[i+1]==' ')
        {
        	s[i]=s[i+1];
        	i--;
    	}
	}
	s[l-1]='\0';
	fprintf(f2,"\nchuoi sau khi xoa :\t%s", s);
}

//b
void wordshortest(char s[101], int l){
    char temp[101], savemin[101];
    int i,j, min=-1;
    for (i=0; i<l; i++){
    	j=0;
    	while(s[i] != ' ' && i<l){
    		temp[j++] = s[i++];
		}
		temp[j]='\0';
		if(min > strlen(temp)){
			min =strlen(temp);
			strcpy(savemin, temp);
		}
	}
	fprintf(f2,"\nTu ngan nhat trong chuoi:\t%s", savemin);
}
//c
void wordlongest(char s[101], int l){
    char temp[101], savemax[101];
    int i,j, max=0;
    for (i=0; i<l; i++){
    	j=0;
    	while(s[i] != ' ' && i<l){
    		temp[j++] = s[i++];//phai co i++ vi trong vong while la 1 vong != khong dung dc cai cua vong for
		}
		temp[j]='\0';
		if(max < strlen(temp)){
			max =strlen(temp);
			strcpy(savemax, temp);
		}
	}
	fprintf(f2,"\nTu dai nhat trong chuoi:\t%s", savemax);
}

//d
int so_max(char s[], int l){
	int n=0, i, j,max = 0;
	char temp[101],savemax[101];
	for (i=0; i<l; i++){
		j=0; temp[j]='\0';	
		while (s[i]>= '0' && s[i]<='9'&& i<l)//dk
			temp[j++] = s[i++];
		temp[j] = '\0' ;
		if(max < strlen(temp)){
			max =strlen(temp);
			strcpy(savemax, temp);
		}
	}
	fprintf(f2,"\nTu co nhieu chu so nhat trong chuoi:\t%s", savemax);
}
//e
void tu_inhoa_max(char s[], int l){
	int n=0, i, j,max = 0;
	char temp[101],savemax[101];
	for (i=0; i<l; i++){
		j=0; temp[j]='\0';	
		while (s[i]>= 'A' && s[i]<='Z'&& i<l)
			temp[j++] = s[i++];
		temp[j] = '\0' ;
		if(max < strlen(temp)){
			max =strlen(temp);
			strcpy(savemax, temp);
		}
	}
	fprintf(f2,"\nTu co nhieu chu in hoa nhat trong chuoi:\t%s", savemax);
}
//f
void tu_dao_nguoc(char s[], int l){
	fprintf(f2,"\nTu dao nguoc trong chuoi:\t%s", strrev(s));
}
int main(){
//dung ham get khac	
    f1 = fopen("bai1_in.txt","r");
    f2 = fopen("bai1_out.txt","w");

    fgets(s1,100,f1);
    fputs(s1,f2);
    int l=strlen(s1);
    //a
    xoa_khoang(s1,l);
    fprintf(f2,"\n");
	fputs(s1,f2);
	//b
	wordlongest(s1,l);
	//c
	wordshortest(s1,l);
	
//d
	so_max(s1,l);
//e
	tu_inhoa_max(s1,l);
//f
	tu_dao_nguoc(s1,l);
    fclose(f1);
    fclose(f2);
    return 0;
}
