#include <stdio.h>

FILE *f1;
char u[100];
void xuat_mh(char kitu[]){
	
	f1 = fopen("NguyenAm.txt","a");
	printf("\nDoc tu file xuat ra man hinh: ");
	fscanf(f1,"%s",&u);
	printf("\n%s", u);
}

int main(){
	int i;
	char kitu[100];
    f1 = fopen("NguyenAm.txt","w");
    if(f1 == NULL){
    	printf("\nFile chua duoc mo");
	}
//nhap
	printf("Nhap ki tu: ");
	scanf("%s", &kitu);
	
	fprintf(f1,"%s", kitu);
//y2
	xuat_mh(kitu);
    fclose(f1);
    return 0;
}
