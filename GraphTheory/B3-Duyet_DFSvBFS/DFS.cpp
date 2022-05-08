#include <stdio.h>
#include <iostream>
#define MAX 10
using namespace std;

FILE *f;

struct dothi
{
    int n;
    int a[MAX][MAX];
};

int LuuVet[MAX];
int ChuaXet[MAX];

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

void DFS(int v, dothi g)
{
    ChuaXet[v] = 1;
    int u;
    for (u = 0; u < g.n; u++)
    {
        if (g.a[v][u] != 0 && ChuaXet[u] == 0)
        {
            LuuVet[u] = v;
            DFS(u, g);
        }
    }
}

void duyettheoDFS(int A, int B, dothi g)
{
    int i;
    for (i = 0; i < g.n; i++)
    {
        ChuaXet[i] = 0;
        LuuVet[i] = -1;
    }
    DFS(A, g);
    if (ChuaXet[B] == 1)
    {
        cout << "Duong di tu dinh " << A << " den dinh " << B << " la: " << endl;
        i = B;
        cout << B;

        while (i != A)
        {
            cout << " <= " << LuuVet[i];
            i = LuuVet[i];
        }
    }
    else
    {
        cout << "Khong co duong di tu dinh" << A << "den dinh " << B << endl;
    }
}
int main()
{
    dothi g;

    docfile(g);
    xuatfile(g);
    duyettheoDFS(1, 4, g);
    return 0;
}
