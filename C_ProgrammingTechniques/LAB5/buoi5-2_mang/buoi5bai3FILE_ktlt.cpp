#include <stdio.h>
FILE *f1,*f2;
int main()
{
    int n,m, a[100][100],i,j;
    f1 = fopen("bai1_in.txt","r");
    f2 = fopen("bai1_out.txt","w");
    fscanf(f1,"%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        	fscanf(f1,"%d",&a[i][j]);
    fprintf(f2,"%d %d\n",n,m);
    for(i=0;i<n;i++){
        int s=0;
        for(j=0;j<m;j++)
            s+= a[i][j];
        fprintf(f2,"%d\n",s);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
