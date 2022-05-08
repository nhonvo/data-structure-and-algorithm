// Võ Thương Trường Nhơn
// 20DTHD4
// 2080600542

#include <stdio.h>
#include <iostream>
#include <conio.h>
#define MAX 101

using namespace std;

FILE *f;
int n;

typedef struct graph
{
    int n;
    int a[MAX][MAX];
} dothi;
void docfile(dothi &g)
{
    f = fopen("data.txt", "r");
    if (f == NULL)
        cout << "\nChua tim thay file!";
    fscanf(f, "%d \n", &g.n);
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            fscanf(f, "%d", &g.a[i][j]);
        }
    }
}
void xuatfile(dothi &g)
{
    cout << "\nSố đỉnh của ma trận: " << g.n << endl;
    cout << "\nXuất ma trận : \n";
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << "\n";
    }
}

void DiTimCacDinhLienThong(dothi g, int nhan[MAX], int i)
{
    for (int j = 0; j < g.n; j++)
    {
        if (g.a[i][j] != 0 && nhan[j] != nhan[i])
        {
            nhan[j] = nhan[i];
            DiTimCacDinhLienThong(g, nhan, j);
        }
    }
}

int XetLienThong(dothi g)
{
    int Nhan[MAX];
    int i;
    for (i = 0; i < g.n; i++)
        Nhan[i] = 0;
    int SoThanhPhanLT = 0;
    for (i = 0; i < g.n; i++)
    {
        if (Nhan[i] == 0)
        {
            SoThanhPhanLT++;
            Nhan[i] = SoThanhPhanLT;
            DiTimCacDinhLienThong(g, Nhan, i);
        }
    }
    return SoThanhPhanLT;
}

int ChuaXet[MAX];

typedef struct EDGE
{
    // u,v là cặp cạnh, value là trọng số
    int u;
    int v;
    int value;
} CANH;

CANH T[MAX];

void Prim(dothi g)
{
    if (XetLienThong(g) != 1)
    {
        cout << "\nĐồ thị không liên thông nên không thể triển khai thuật toán Prim" << endl;
        return;
    }
    int nT = 0;
    for (int i = 0; i < g.n; i++)
        ChuaXet[i] = 0;
// chọn đỉnh đầu tiên cho vào tập Y
    ChuaXet[0] = 1;
    while (nT < g.n - 1)
    {
        CANH CanhNhoNhat;
        int GiaTriNhoNhat = 100;
        for (int i = 0; i < g.n; i++)
        {
            // xét các đỉnh trong tập đỉnh đã xét
            if (ChuaXet[i] == 1)
            {
                for (int j = 0; j < g.n; j++)
                // xét các đỉnh trong tập đỉnh X/Y các đỉnh chưa xét
                    if (ChuaXet[j] == 0 && g.a[i][j] != 0 && GiaTriNhoNhat > g.a[i][j])
                    // Điều kiện các đỉnh chưa xét, có đường nối từ đỉnh i sang j và chọn trọng số nhỏ nhất
                    {
                        CanhNhoNhat.u = i;
                        CanhNhoNhat.v = j;
                        CanhNhoNhat.value = g.a[i][j];
                        GiaTriNhoNhat = g.a[i][j];
                        // cập nhật các giá trị
                    }
            }
        }
        T[nT] = CanhNhoNhat;
        // thêm cạnh nhỏ nhất vào tập cạnh T 
        nT++;
        ChuaXet[CanhNhoNhat.v] = 1;
        // gán lại giá trị chưa xét của đỉnh v là 1, tức đã xét
        // đánh đấu đỉnh từ tập x/y đã xét
    }

    int sum = 0;
    cout << "Cay khung nho nhat cua do thi la \n";
    for (int i = 0; i < nT; i++)
    {
        cout << "(" << T[i].u << "," << T[i].v << ")" << endl;
        sum += T[i].value;
    }
    cout << "Tổng trọng số của cây khung là: " << sum << endl;
}

int main()
{
    dothi g;
    docfile(g);
    xuatfile(g);
    Prim(g);
}