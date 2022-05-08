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

typedef struct EDGE
{
    int u;
    int v;
    int value;
} CANH;

void SapXepTang(CANH E[100], int tongsocanh)
{
    CANH canhtam;
    for (int i = 0; i < tongsocanh - 1; i++)
    {
        for (int j = i + 1; j < tongsocanh; j++)
            if (E[i].value > E[j].value)
            {
                canhtam = E[i];
                E[i] = E[j];
                E[j] = canhtam;
            }
    }
}

void Kruskal(dothi g)
{
    CANH listEdge[MAX];
    // danh sách các cạnh của đồ thị
    int tongsocanh = 0;
    int i, j;
    // thêm cách cạnh vào listEdge
    for (i = 0; i < g.n; i++)
    {
        for (j = i + 1; j < g.n; j++)
            if (g.a[i][j] > 0)
            {
                listEdge[tongsocanh].u = i;
                listEdge[tongsocanh].v = j;
                listEdge[tongsocanh].value = g.a[i][j];
                tongsocanh++;
            }
    }
    // sắp xếp theo chiều tăng dần của trọng số
    SapXepTang(listEdge, tongsocanh);

    int nT = 0;
    CANH T[MAX];
    // chứa cách cạnh của cây khung nhỏ nhất
    int nhan[MAX];

    for (i = 0; i < g.n; i++)
        nhan[i] = i;

    int canhdangxet = 0;
    // lưu vị trí đang xét

    while (nT < g.n && canhdangxet < tongsocanh)
    // ĐK dừng
    {
        // thêm một cạnh trong cây khung mà không tạo chu trình = chọn cạnh mà đỉnh tại nhãn khác nhau
        if (nhan[listEdge[canhdangxet].u] != nhan[listEdge[canhdangxet].v])
        {
            T[nT] = listEdge[canhdangxet];
            nT++;
            // cập nhật lại giá trị nhãn của tất cả các nhãn của đỉnh v thành nhãn của đỉnh u
            // hai đỉnh cùng nhãn là cùng 1 thành phần liên thông
            int giatri = nhan[listEdge[canhdangxet].v];
            // lưu lại gtr trước đó của đỉnh 4 để vòng for tiếp theo đỉnh 5 ss vs gtri =4 tức bằng nhau
            // ta cập nhật giá trị
            for (j = 0; j < g.n; j++)
                if (nhan[j] == giatri)
                    nhan[j] = nhan[listEdge[canhdangxet].u];
        }
        canhdangxet++;
        // xét tiếp cạnh tiếp theo trong tập cạnh đã sắp xếp
    }
    if (nT != g.n - 1)
        // nếu số cạnh trong cây khung không đủ n-1 thì ko liên thông
        cout << "\nĐồ thị không liên thông \n";
    else
    {
        int SUM = 0;
        cout << "\nĐồ thị liên thông \n";
        cout << "Cây khung nhỏ nhất của đồ thị là \n";
        for (i = 0; i < nT; i++)
        {
            cout << "(" << T[i].u << "," << T[i].v << ")" << endl;
            SUM += T[i].value;
        }
        cout << "\nTổng trọng số của cây khung là: " << SUM;
    }
}
int main()
{
    dothi g;
    docfile(g);
    xuatfile(g);
    Kruskal(g);
}
// Nhận xét đồ thị ít cạnh krukal nhanh hơn prim tuy nhiên trường hợp đồ thị nhiều cạnh thì krukal
// chậm hơn do còn giải thuật sắp xếp
// do không quan trọng trọng số nên 2 giải thuật dùng được cả trên đồ thị vô hướng, ...
