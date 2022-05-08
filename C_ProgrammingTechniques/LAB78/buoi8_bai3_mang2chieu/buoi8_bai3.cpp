#include <stdio.h>
#include <string.h>

FILE *f1,*f2;
int a[102][102];
int n,m,i,j;
//a
void print_resever(int n, int m, int a[102][102]){
	int b[m*m];
	int k=0;
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	b[k++]=a[i][j];
		}
	}
	b[k]=NULL;
	fprintf(f2,"\nDao nguoc:");
	for(i=m*n; i>0; i--){
		fprintf(f2,"%d\n",b[i]);
	}
}

void swap(int &xp, int &yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}	
//b
void sap_xep_dong_noibot(int n,int m, int a[102][102]){
 	for(int k = 0; k<m ; k++)
		for(int i = 0; i<n-1 ; i++)
    		for(int j = n-1; j>i ; j--)
				if(a[k][j]<a[k][j-1])
				{
					int temp = a[k][j];
					a[k][j] = a[k][j-1];
					a[k][j-1] = temp;
				}
}

//c
void sap_xep_dong_luachon(int arr[102][102], int n, int m)
{
    int i, j, min_idx;
	for(int k = 0; k < n;k++){
 	   for (i = 0; i < m-1; i++){
   		min_idx = i;
    	for (j = i+1; j < m; j++)
        	if (arr[k][j] < arr[k][min_idx])
        		min_idx = j;
        	swap(arr[k][min_idx], arr[k][i]);
    	}
	}
}

int main(){

    f1 = fopen("bai3_in.txt","r");
    f2 = fopen("bai3_out.txt","w");

    fscanf(f1,"%d%d",&n,&m);
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        	fscanf(f1,"%d",&a[i][j]);
        	
    fprintf(f2,"%d %d\n",n,m);
    
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	fprintf(f2,"%d ",a[i][j]);
		}
		fprintf(f2,"\n");
	}
	print_resever(n,m,a);

//	sap_xep_dong_noibot(n,m,a);
	sap_xep_dong_luachon(a,n,m);
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        	fprintf(f2,"%d ",a[i][j]);
		}
		fprintf(f2,"\n");
	}
    fclose(f1);
    fclose(f2);
    return 0;
}
