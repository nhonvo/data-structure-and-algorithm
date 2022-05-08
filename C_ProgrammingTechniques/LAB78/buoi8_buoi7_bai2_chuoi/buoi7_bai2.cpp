#include <stdio.h>
#include <string.h>

FILE *f1,*f2;
int n,m,b[256];
char s1[102];
char s2[102];
char s3[102];
int dem;

//a
int check_chuoi_con(char s1[], char s2[]){
	if(strstr(s1,s2)!=NULL){
		return 1;
	}else{
		return 0;
	}
}
//b
//int xoa_chuoi(int &do_dai_chuoi, char s1[], int i, int j){	
//	for(int k=j;k<=do_dai_chuoi;k++)
//		s1[i+k-j]=s1[k];
//		//chèn phàn tu tu j vè sau vào tù i den ...
//}


int xoa_chuoi(int &do_dai_chuoi, char s1[], int i, int j){	
	int so_luong=(j-i)+1;
	for(int u=i; u<	do_dai_chuoi-so_luong-1; u++){
		s1[u]=s1[u+so_luong];
	}				
		s1[do_dai_chuoi-so_luong]='\0';
}

//c
void chen_chuoi(int &l, char s1[], char s2[], char s3[], int k){
	for(int i = k; i <=l; i++){
		s3[i-k] = s1[i]; //s3=s1
    }
    s1[k]='\0';
    //xoa_chuoi(l,s1,k,l);//xoa 1
    //fprintf(f2,"%s\n",s1);
    strcat(s1,s2);
    //fprintf(f2,"%s\n",s3);
    strcat(s1,s3);
    //fprintf(f2,"%s\n",s1);
}

int ThemPhanTu(int &n, int a[], int x, int vt){
    for(int i = n; i > vt; i--){
        a[i] = a[i-1];
    }
    a[vt] = x;
    n++;
}
int main(){
	
    f1 = fopen("bai2_in.txt","r");
    f2 = fopen("bai2_out.txt","w");

   	fscanf(f1,"%s\n%s",&s1,&s2);

    fprintf(f2,"%s\n%s\n", s1, s2);
    int l=strlen(s1);
//a
    int u = check_chuoi_con(s1,s2);
    fprintf(f2,"Chuoi s1 co chua chuoi s2:   ");
    if(u==1){
    	fprintf(f2,"Co");
	}else{
		fprintf(f2,"Khong");
	}
////b
	int i,j;
	fscanf(f1,"%d %d",&i,&j);
	fprintf(f2,"\nHai so nguyen duong i,j:    ");
	fprintf(f2,"%d %d",i,j);
	xoa_chuoi(l,s1,i,j);
	fprintf(f2,"\nChuoi sau khi xoa:   ");
	fprintf(f2,"%s",s1);
//c
	int k;
	fscanf(f1,"%d",&k);
	fprintf(f2,"\nVi tri can chen k= ");
	fprintf(f2,"%d", k);
	chen_chuoi(l,s1,s2,s3,k);
	fprintf(f2,"\nChuoi sau khi chen: ");
	fprintf(f2,"%s",s1);
	
    fclose(f1);
    fclose(f2);
    return 0;
}
