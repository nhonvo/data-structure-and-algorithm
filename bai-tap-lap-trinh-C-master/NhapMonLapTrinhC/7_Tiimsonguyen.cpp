#include <stdio.h>
#include <conio.h>
int main()
{
    int tong, n;
    tong = 0;
    n = 1;
    while (tong <= 1000)
    {
        tong = tong+n;
        n++;
    }
    printf("Voi n= %d thi 1+2+3...+n>1000",n);
    return 0;
}  
