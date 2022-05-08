//Let's sort the perfect numbers in the array descending other values between
//integer value and position (nguyentotang)
//6,28,496,8128
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
int kthoanthien(int &n)
{
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            s += i;
        }
    }
    if (s == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void sapxep(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (kthoanthien(a[i]) == 1)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (kthoanthien(a[j]) == 1 && a[i] < a[j])
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
    printf("\nMang sau khi sap xep so hoan thien giam dan: ");
    xuat(a, n);

    return 0;
}
