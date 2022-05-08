#include <stdio.h>

FILE *f1;
int a[100];
int n,i;
//a
void doc_file(){
	fscanf(f1,"%d",&n);
    
    for(i=0;i<n;i++)
       	fscanf(f1,"%d",&a[i]);
}
//b
void xuat_file(int n, int a[]){
    printf("%d\n",n);
    
	for(i=0;i<n;i++)
       	printf("%d ",a[i]);
}
//c
bool checknt(int n)
{
	int dem = 0;
	if (n < 2)
	{
		return false;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				dem++;
			}
		}
		if (dem == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void nguyen_to(int n, int a[]){
	FILE *f1 = fopen("bai1.txt","a");	
	fprintf(f1,"\nCac so nguyen to: ");
	for(i=0;i<n;i++)
		if(checknt(a[i]))
			fprintf(f1,"\n%4d",a[i]);
	fclose(f1);
}
int main(){
	int i;
    f1 = fopen("bai1.txt","r");
    if(f1 == NULL){
    	printf("\nFile chua duoc mo");
	}
//a
	doc_file();
//b
	printf("Du lieu tu file\n");
    xuat_file(n,a);
//c

	
	nguyen_to(n,a);

    fclose(f1);
    return 0;
}
