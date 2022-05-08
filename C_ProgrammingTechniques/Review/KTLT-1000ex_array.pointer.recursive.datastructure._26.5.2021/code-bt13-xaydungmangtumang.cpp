
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100

void nhap (int a[], int &n)
{
    do
    {
        printf("\nNhap so phan tu: ");
        scanf("%d", &n);
        if(n <= 0 || n > MAX)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    }while(n <= 0 || n > MAX);
    for(int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}



void taoMang(int a[],int n){
	int b[MAX],nb=0;
	for(int i=0;i <n; i++){
		if(a[i]%2!=0){
			b[nb]=a[i];
			nb++;
		}
	}
	xuat(b,nb);
}
int main()
{
    int n, m;
    int a[MAX];

    printf("\nNhap mang: ");
    nhap(a, n);
    xuat(a, n);

    printf("\nMang b chi chua gia tri le cua mang a: \n");
    taoMang(a, n);

    getch();
    return 0;
}
