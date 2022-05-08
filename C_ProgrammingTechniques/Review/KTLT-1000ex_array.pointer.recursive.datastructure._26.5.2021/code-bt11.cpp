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

void DoiChochiahetba(int a[], int n, int ViTriDoi)
{
	int tam=a[ViTriDoi];
    for(int i = ViTriDoi; i > 0; i--)
    {
        a[i] = a[i - 1];      
    }
    a[0] = tam;
}

void DuaChanVeDau(int a[], int ViTriDoi)
{
    int tam = a[ViTriDoi];           // bi?n t?m luu t?t c? các giá tr? th?a ÐK d?i
    for(int i = ViTriDoi; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = tam;
}

void Dua0VaoGiua(int a[], int ViTriDoi, int ViTriChanCuoi)
{
    // Do 0 n?m gi?a m?ng nên 0 s? là giá tr? ch?n cu?i d? th?a yêu c?u bài toán
    for(int i = ViTriDoi; i > ViTriChanCuoi; i--)
    {
        a[i] = a[i - 1];        
    }
    a[ViTriChanCuoi] = 0;
}

void DuaChanVeDauLeVeCuoi0NamGiuaMang(int a[], int n)
{
    int i, dem;
    int ViTriChanCuoi = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0 && a[i] != 0)
        {
            DuaChanVeDau(a, i);
        }
    }
    for(i = 0; i < n; i++)
    {
        if(a[i] % 2 != 0)
        {
            ViTriChanCuoi = i;
            break;
        }
    }
    for(i; i < n; i++) // b? kh?i t?o i d? tránh du 1 s? 0 
    {
        if(a[i] == 0)
        {
            Dua0VaoGiua(a, i, ViTriChanCuoi);
        }
    }
}
int main()
{
    int n;
    int a[MAX];

    nhap(a, n);
    xuat(a, n);
    DuaChanVeDauLeVeCuoi0NamGiuaMang(a, n);
    printf("\nDua chan ve dau mang le ve cuoi mang 0 vao giua: ");
    xuat(a, n);

    getch();
    return 0;
}
