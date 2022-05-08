
#include<stdio.h>
#include<conio.h>

// Khai báo ki?u d? li?u c?u trúc phân s?
struct PhanSo
{
    int TuSo, MauSo, Honso;
};

typedef struct PhanSo PHANSO;

void NhapPhanSo(PHANSO &);
void XuatPhanSo(PHANSO);

void NhapPhanSo(PHANSO &ps)
{
    printf("\nNhap vao tu so: ");
    scanf("%d%d", &ps.TuSo,&ps.Honso);

    do
    {
        printf("\nNhap vao mau so: ");
        scanf("%d", &ps.MauSo);

        if(ps.MauSo == 0)
        {
            printf("\nMau so phai khac 0. Xin kiem tra lai !");
        }
    }while(ps.MauSo == 0);
}

void XuatPhanSo(PHANSO ps)
{
    printf("%d(%d/%d)",ps.Honso, ps.TuSo, ps.MauSo);
}
int main()
{
    PHANSO ps;
    NhapPhanSo(ps);
    XuatPhanSo(ps);

    

    getch();
    return 0;
}
