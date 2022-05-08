//Let's sort the values at odd positions in the array ascending values
//others keep the same value and position (vitriletang). 
#include <stdio.h>
#include <conio.h>
#include <math.h>
void nhap(int a[], int &n)
{
    do
    {
        printf("\nNhap so phan tu: ");
        scanf("%d", &n);
        if (n <= 0 || n > 101)
        {
            printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
        }
    } while (n <= 0 || n > 101);
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

void HoanVi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int sapxep(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] % 2 != 0 && a[i] > a[j])
                {
                    HoanVi(a[i], a[j]);
                }
            }
        }
    }
}
int main()
{
    int n;
    int a[101];

    nhap(a, n);
    xuat(a, n);

    sapxep(a, n);
    printf("\nMang sau khi sap xep le tang dan: ");
    xuat(a, n);

    return 0;
}
