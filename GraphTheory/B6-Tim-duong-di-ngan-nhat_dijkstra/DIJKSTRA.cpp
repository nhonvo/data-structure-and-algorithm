// Võ Thương Trường Nhơn
// 20DTHD4
// 2080600542

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
#define voCung 100000

using namespace std;
FILE *f;
int n;

int chuaXet[MAX];
int LuuVet[MAX];
int DoDaiDuongDiToi[MAX];

typedef struct gharp
{
    int n;
    int a[MAX][MAX];
} dothi;

void docfile(dothi &g)
{
    f = fopen("dothi.txt", "r");
    if (f == NULL)
        cout << "\nChưa tìm thấy file!";
    fscanf(f, "%d \n", &g.n);
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            fscanf(f, "%d", &g.a[i][j]);
        }
    }
}
void xuatfile(dothi g)
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
int TimDuongDiNhoNhat(dothi g)
{
    int li = -1;
    int p = voCung;
    for (int i = 0; i < g.n; i++)
    {
        if (chuaXet[i] == 0 && DoDaiDuongDiToi[i] < p)
        {
            p = DoDaiDuongDiToi[i];
            li = i;
        }
    }
    return li;
}

void CapNhatDuongDi(int u, dothi g)
{
    chuaXet[u] = 1;
    for (int v = 0; v < g.n; v++)
    {
        if (chuaXet[v] == 0 && g.a[u][v] > 0 && DoDaiDuongDiToi[u] + g.a[u][v] < DoDaiDuongDiToi[v])
        {
            DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
            LuuVet[v] = u;
        }
    }
}

void Dijkstra(dothi g, int S, int F)
{
    for (int i = 0; i < g.n; i++)
    {
        DoDaiDuongDiToi[i] = voCung;
        chuaXet[i] = 0;
        LuuVet[i] = -1;
    }
    DoDaiDuongDiToi[S] = 0;
    while (chuaXet[F] != 1)
    {
        int u = TimDuongDiNhoNhat(g);
        if (u == -1)
        {
            break;
        }
        CapNhatDuongDi(u, g);
    }
    if (chuaXet[F] == 1)
    {
        cout << "\nĐường đi ngắn nhất từ " << S + 1 << " --> " << F + 1 << " là: ";
        int i = F;
        cout << F + 1;
        while (LuuVet[i] != S)
        {
            cout << " <- " << LuuVet[i] + 1;
            i = LuuVet[i];
        }
        cout << " <- " << LuuVet[i] + 1;
        cout << "\nĐộ dài đường đi: " << DoDaiDuongDiToi[F] << endl;
    }
    else
    {
        cout << "\nKhông có đường đi";
    }
}

int main()
{
    dothi g;
    docfile(g);
    xuatfile(g);
    int S, F;
    cout << "\nNhập đỉnh bắt đầu: ";
    cin >> S;
    cout << "\nNhập đỉnh kết thúc: ";
    cin >> F;
    Dijkstra(g, S - 1, F - 1);
    return 0;
}