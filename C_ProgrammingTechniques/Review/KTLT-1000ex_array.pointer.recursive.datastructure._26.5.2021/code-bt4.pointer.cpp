#include <stdio.h>
#include <stdlib.h>
void nhap(int &n, int *a){
	do{
	printf("Nhap n:");
	scanf("%d",&n);
		if(n<=0||n>100){
			printf("ERROR\n");
		}
	}while(n<=0||n>100);
	
	for(int i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d", (a+i));
	}
}

void xuat(int n,int *a){
    for(int i = 0;i < n; i++){
        printf("%4d", *(a+i));
    }
}
bool ngtocheck(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            s++;
        }
    }
    if (s == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int ngto(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        if (ngtocheck(*(a+i)))
        {
            printf(" %d ", *(a+i));
        }
    }
}
int main()
{
    int n,*a;
    a= new int[100];
    nhap(n,a);
    ngto(n, a);
	//xuat(n,a);
}
