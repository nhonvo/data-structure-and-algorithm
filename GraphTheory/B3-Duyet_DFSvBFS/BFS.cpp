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

int LuuVet[MAX];
int ChuaXet[MAX];

struct Queue
{
    int size;
    int array[MAX];
};

void CreateQueue(Queue &Q)
{
    Q.size = 0;
}

int PUSH(Queue &Q, int &value)
{
    if (Q.size + 1 >= 100)
        return 0;
    Q.array[Q.size] = value;
    Q.size++;
    return 1;
}

int POP(Queue &Q, int &value)
{
    if (Q.size <= 0)
        return 0;
    value = Q.array[0];
    for (int i = 0; i < Q.size - 1; i++)
        Q.array[i] = Q.array[i + 1];
    Q.size--;
    return 1;
}

int CHECK(Queue Q)
{
    if (Q.size <= 0)
        return 1;
    return 0;
}

void BFS(int v, dothi g)
{
    Queue Q;
    CreateQueue(Q);
    PUSH(Q, v);
    while (!CHECK(Q))
    {
        POP(Q, v);
        ChuaXet[v] = 1;
        for (int u = 0; u < g.n; u++)
        {
            if (g.a[v][u] != 0 && ChuaXet[u] == 0)
            {
                PUSH(Q, u);
                if (LuuVet[u] == -1)
                    LuuVet[u] = v;
            }
        }
    }
}

void duyettheoBFS(int A, int B, dothi g)
{
    int i;
    for (i = 0; i < g.n; i++)
    {
        ChuaXet[i] = 0;
        LuuVet[i] = -1;
    }
    BFS(A, g);
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
    cout << "\n";
    duyettheoBFS(1, 4, g);
    return 0;
}