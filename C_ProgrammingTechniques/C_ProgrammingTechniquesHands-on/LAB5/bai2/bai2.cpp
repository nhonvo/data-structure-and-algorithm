#include<stdio.h>
#include<stdlib.h>


void random(int a[100][100], int n,int m)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			a[i][j]=rand()%10;
}
void luu_matran_in(int a[][100],int n,int m,FILE *f1){
	f1 = fopen("bai2_in.txt","a");
	for(int i =0;i<n;i++){
		for(int j =0;j < m;j++){
			fprintf(f1,"%d\t",a[i][j]);
			}
		fprintf(f1,"\n");
	}
}

void xuat(int a[][100],int n,int m){
	for(int i =0;i<n;i++){
		for(int j =0;j < m;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
void doc_file(int a[][100],int b[][100],int n,int m){
	for(int i =0;i<n;i++){
		for(int j =0;j < m;j++)
			b[i][j] = a[i][j];
	}
}
int main(){
	FILE *f1;
	int n = 5;
	int m = 6;
	int a[100][100];
	int b[100][100];
	f1 = fopen("bai2_in.txt","w");
	random(a,n,m);
	
	luu_matran_in(a,n,m,f1);
	doc_file(a,b,n,m);
	xuat(b,n,m);
	
	return 0;
}
