#include <stdio.h>

FILE *f1,*f2;

int main(){
	
    int n,m,i,j;
    char a[100][100];
    f1 = fopen("bai1_in.txt","r");
    f2 = fopen("bai1_out.txt","w");
    
    fscanf(f1,"%d%d",&n,&m);
    
    for(i=0;i<n;i++)
        for(j=0;j<m*2;j++)
        	fscanf(f1,"%c",&a[i][j]);
        	
    fprintf(f2,"%d\n%d",n,m);
    
	for(i=0;i<n;i++){
        for(j=0;j<m*2;j++){
        	fprintf(f2,"%c",a[i][j]);
		}
	}
	fclose(f1);
    fclose(f2);
    return 0;
}
