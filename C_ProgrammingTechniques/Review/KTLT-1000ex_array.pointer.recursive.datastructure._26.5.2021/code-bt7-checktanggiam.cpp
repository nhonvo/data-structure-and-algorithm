#include <stdio.h>
#include<conio.h>
void nhap(int &n, int a[])
{
	do
	{
		printf("Nhap N=");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
		{
			printf("Error.Enter again.");
		}

	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i+1);
		scanf("%d", &a[i]);
	}
}
void xuat(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%d",a[i]);
	}
}
//tang tuong tu
int checkGiam(int n, int a[]){
	int flag=1;
	for(int i=0;i<n;i++) {
		if(a[i]<=a[i+1])
		flag=0;
		break;
	}
	return flag;
}


int main()
{
    int n;
    int a[101];
    nhap(n,a);
    xuat(n,a);

    int flag = checkGiam(n,a);
    if(flag == 1)
    {
        printf("\nMang giam dan");
    }
    else
    {
    printf("\nKhong thoa DK");
    }
    
    return 0;
}
