/*
  Suu t?m b?i @nguyenvanhieuvn
  Th?c h�nh nhi?u b�i t?p hon t?i https://luyencode.net/
*/

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void CapPhat(int*& a, int n)  // C�ch 1 d�ng tham chi?u
{
    //a = new int[n];
    a = (int*)malloc(n * sizeof(int));
}

int* CapPhat(int n)   // C�ch 2 Kh�ng thay d?i tr?c ti?p tham s? m� tr? v?
{
    int* a = new int[n];
    //int* a = (int*)malloc(n * sizeof(int));
    return a;
}
void CapPhat(int** p,int n)   // C�ch 3 S? d?ng con tr? p tr? d?n con tr? a n�y. H�m s? thay d?i gi� tr? c?a con tr? a gi�n ti?p th�ng qua con tr? p.
{
    //*p = new int[n];
    int* a = (int*)malloc(n * sizeof(int));
}

int main()
{
    int n = 5;
    int* a = CapPhat(n);

    //CapPhat(a, n);      // S? d?ng h�m truy?n d?i s? ki?u tham chi?u
    


    //CapPhat(&a,n);        // S? d?ng h�m v?i tham s? l� con tr? tr? c?p n + 1
    if(a == NULL)
        printf("Cap phat thai bai!");
    else 
    {
            printf("Cap phat thanh cong");
            delete []a;
    }
    getch();
    return 0;
}
