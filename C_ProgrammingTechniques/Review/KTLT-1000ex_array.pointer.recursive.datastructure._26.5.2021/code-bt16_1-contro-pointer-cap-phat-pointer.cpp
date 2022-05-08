/*
  Suu t?m b?i @nguyenvanhieuvn
  Th?c hành nhi?u bài t?p hon t?i https://luyencode.net/
*/

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void CapPhat(int*& a, int n)  // Cách 1 dùng tham chi?u
{
    //a = new int[n];
    a = (int*)malloc(n * sizeof(int));
}

int* CapPhat(int n)   // Cách 2 Không thay d?i tr?c ti?p tham s? mà tr? v?
{
    int* a = new int[n];
    //int* a = (int*)malloc(n * sizeof(int));
    return a;
}
void CapPhat(int** p,int n)   // Cách 3 S? d?ng con tr? p tr? d?n con tr? a này. Hàm s? thay d?i giá tr? c?a con tr? a gián ti?p thông qua con tr? p.
{
    //*p = new int[n];
    int* a = (int*)malloc(n * sizeof(int));
}

int main()
{
    int n = 5;
    int* a = CapPhat(n);

    //CapPhat(a, n);      // S? d?ng hàm truy?n d?i s? ki?u tham chi?u
    


    //CapPhat(&a,n);        // S? d?ng hàm v?i tham s? là con tr? tr? c?p n + 1
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
