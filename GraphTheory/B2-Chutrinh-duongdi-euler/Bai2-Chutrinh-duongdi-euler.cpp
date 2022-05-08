// Võ Thương Trường Nhơn
// 20DTHD4
// 2080600542

#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

FILE *f;
int n;

typedef struct graph
{
    int n;
    int a[101][101];
} dothi;
// khởi tạo stack dạng mảng 1 chiều để lưu giá trị
struct stack
{
    int array[101];
    int size;
};

void khoitaostack(stack &s)
{
    s.size = 0;
}
// đưa giá trị vào stack(là mảng 1 chiều) mỗi lần thên giá trị tăng thêm 1 đv
void themvaostack(stack &s, int value)
{
    if (s.size > 101)
        return;
    s.array[s.size] = value;
    s.size++;
}
// từ đỉnh i duyệt đến các đỉnh kề nó. nên ta xét giá trị a[i][j] trên ma trận kề
void timduongdi(stack &stack, dothi &g, int i)
{
    for (int j = 0; j < g.n; j++)
    {
        // tìm kiếm đỉnh kề trên ma trận kề
        if (g.a[i][j] != 0)
        {
            g.a[i][j] = g.a[j][i] = 0;
            // xoá cạnh đã duyệt
            timduongdi(stack, g, j);
        }
    }
    // sau khi đã tìm hết tất cả các cạnh kề t cho vào lần lượt tất cả vào stack.
    themvaostack(stack, i);
}
int kiemtrachutrinh(dothi g, stack &s)
{
    // vì hàm tìm đường đi sẽ làm thay đổi giá trị đồ thị nên ta khởi tạo đồ thị tạm cho temp = g(đồ thị ban đầu)
    dothi temp = g;
    int i, j, dinhxuatphat = 0, y = 1;
    khoitaostack(s);
    timduongdi(s, temp, dinhxuatphat);
    // KIỂM TRA CÓ CHU TRÌNH KHÔNG
    // kiểm tra đỉnh đầu và đỉnh cuối
    // kiểm tra cạnh nào chưa đc đi
    for (int i = 0; i < temp.n; i++)
    {
        for (int j = 0; j < temp.n; j++)
        {
            if (temp.a[i][j] != 0)
                return 0;
        }
    }
    if (s.array[0] != s.array[s.size - 1])
        return 0;
    return 1;
}
int kiemtraduongdi(dothi g, stack &s)
{
    dothi temp = g;
    int i, j, dinhxuatphat = 0;
    khoitaostack(s);
    timduongdi(s, temp, dinhxuatphat);
    for (int i = 0; i < temp.n; i++)
    {
        for (int j = 0; j < temp.n; j++)
        {
            if (temp.a[i][j] != 0)
                return 0;
        }
    }
    if (s.array[0] == s.array[s.size - 1])
        return 0;
    return 1;
}
void xuatchutrinh(stack s)
{
    for (int i = s.size - 1; i >= 0; i--)
    {
        cout << " " << s.array[i];
    }
}
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
int main()
{
    dothi g;
    stack s;
    docfile(g);
    xuatfile(g);
    kiemtrachutrinh(g, s);
    if (kiemtrachutrinh(g, s))
    {
        cout << "\nChu trình của đồ thị trên là: ";
        xuatchutrinh(s);
    }
    else
        cout << "\nĐồ thị trên không có chu trình.";

    if (kiemtraduongdi(g, s))
    {
        cout << "\nĐường đi của đồ thị trên là: ";
        xuatchutrinh(s);
    }
    else
        cout << "\nĐồ thị trên không có đường đi.";
}