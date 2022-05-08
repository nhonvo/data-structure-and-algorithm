#include<stdio.h>
#include<math.h>
void Bubble_sort(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
            if(*a[j]>*a[j+1])
        {
            int x=*a[j];
            *a[j]=*a[j+1];
            *a[j+1]=x;
        }
    }
}
void xuat(int a[][102],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
int ktnt(int x)
{
    if(x<=1)return 0;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)return 0;
    return 1;
}
int ktcp(int x)
{
    int k=sqrt(x);
    return k*k==x;
}
void sxdcchinh(int a[][102],int n)
{
    int **x= new int*;
    int dem=0;
    for(int i=0;i<n;i++)
        if(ktnt(a[i][i]))
        {
            x[dem]=&a[i][i];
            dem++;
        }
    Bubble_sort(x,dem);
}
void sxdcphu(int a[][102],int n)
{
    int **x= new int*;
    int dem=0;
    for(int i=0;i<n;i++)
        if(ktcp(a[i][n-i-1]))
        {
            x[dem]=&a[n-i-1][i];
            dem++;
        }
    Bubble_sort(x,dem);
}
void sxbien(int a[][102],int n)
{
    int **x= new int*;
    int dem=0;
    for(int i=0;i<n;i++)
        {
            x[dem]=&a[0][i];
            dem++;
        }
    for(int i=1;i<n;i++)
    {
        x[dem]=&a[i][n-1];
        dem++;
    }
    for(int i=n-2;i>=0;i--)
        {
            x[dem]=&a[n-1][i];
            dem++;
        }
    for(int i=n-2;i>0;i--)
        {
            x[dem]=&a[i][0];
            dem++;
        }
    Bubble_sort(x,dem);
}
void nhap(int a[][102],int &n)
{
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        printf("Nhap a[%d][%d]: ",i,j);
        scanf("%d",&a[i][j]);
    }
}
int main()
{
    int n=3,a[102][102];
    nhap(a,n);
    printf("Mang vua nhap la:\n");
    xuat(a,n);
    printf("Mang sau khi sap xep cac phan tu nguyen to tren duong cheo chinh la:\n");
    sxdcchinh(a,n);
    xuat(a,n);
    printf("Mang sau khi sap xep cac phan tu chinh phuong tren duong cheo phu la:\n");
    sxdcphu(a,n);
    xuat(a,n);
    printf("Mang sau khi sap xep bien la: \n");
    sxbien(a,n);
    xuat(a,n);
    return 0;
}
