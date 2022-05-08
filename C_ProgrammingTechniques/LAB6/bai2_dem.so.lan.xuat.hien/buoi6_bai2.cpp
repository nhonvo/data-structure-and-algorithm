#include <stdio.h>

FILE *f1,*f2;
int n,m,b[256];
char a[102][102];

int main(){

    f1 = fopen("bai1_in.txt","r");
    f2 = fopen("bai1_out.txt","w");

    fscanf(f1,"%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m*2;j++)
        	fscanf(f1,"%c",&a[i][j]);

    fprintf(f2,"%d %d\n",n,m);
    int dem=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m*2;j++)
       		b[a[i][j]]++;//mang danh dau - dem so lân xuat hien va luu no vao mang b.
    for(int i='A';i<='Z';i++)
        if(b[i]!=0){
       		char c =char(i);
        fprintf(f2,"%c %d\n",c,b[i]);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
