#include <conio.h>
#include <stdio.h>
#include <string.h>

struct sinhvien
{
    char *masv;
    char *hoten;
    int namsinh;
    float diemtb;
};

void NhapDSSV(sinhvien *sv, int &n)
{
    int i;
    do
    {
        printf("\n Nhap so sinh vien: ");
        scanf("%d", &n);
        fflush(stdin);
    } while (n <= 0 || n >= 101);
    sv = new sinhvien[n];
    for (i = 0; i < n; i++)
    {
        printf("\n Nhap sinh vien thu %d", i + 1);
        printf("\n Nhap ma so sinh vien: ");
        gets(sv[i].masv);
        printf("\n Nhap ho ten: ");
        gets(sv[i].hoten);
        printf("\n Nhap nam sinh: ");
        scanf("%d", &sv[i].namsinh);
        fflush(stdin);
        printf("\n Nhap diem trung binh: ");
        scanf("%f", &(sv[i].diemtb));
        fflush(stdin);
    }
}
void XuatDSSV(sinhvien *sv, int n)
{
    int i;
    printf("\n  MASV  HOTEN    NAMSINH  DIEMTB");
    for (i = 0; i < n; i++)
        printf("\n  %s    %s       %d       %f",
            sv[i].masv, sv[i].hoten, sv[i].namsinh, sv[i].diemtb);
}
int main(void)
{
    sinhvien *s;
    int i, n = 0;
    NhapDSSV(s, n);
    XuatDSSV(s, n);
    getch();
    return 0;
}
