// Võ Thương Trường Nhơn
// 20DTHD4
// 2080600542

#include <stdio.h>
#include <iostream>
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
int kiemtramatranke(dothi &g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.a[i][i] != 0)
                return 0;
        }
    }
    return 1;
}
int kiemtradothivohuong(dothi &g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.a[i][j] != g.a[j][i])
                return 0;
        }
    }
    return 1;
}

// XÉT TÍNH LIÊN THÔNG
// Kiểm tra đồ thị có liên thông hay không?
// Có mấy thành phần liên thông? Liệt kê tất cả các đỉnh của từng thành phần.

// 1. Khởi tạo tất cả các đỉnh i của đồ thị đều có nhãn = 0, nhan[i] = 0. và SoThanhPhanLT = 0.
// 2. Chọn 1 đỉnh i bất kỳ chưa xét, tức là chọn 1 đỉnh i có nhãn = 0, tức là đỉnh i chưa thuộc 1 thành phần liên thông nào cả.
//     - Tăng SoThanhPhanLT lên 1.
//     - Đánh dấu đỉnh i đã được xét bằng cách gán nhân cho nó, nhan[i] = SoThanhPhanLT
//     - Tìm các đinh j có nối với i. Xem đinh j nào có nhãn = 0, thì gắn nhãn lại cho đỉnh j, nhan[j] = nhan[i].
// 3. Lặp lại bước 2 cho đến khi ko chọn được đính i nào nữa.
// Vậy:
// - Mỗi lần duyệt ta được 1 thành phần liên thông.
// - Các đỉnh cùng nhân sẽ cùng 1 thành phần liên thông.

// CÁC BƯỚC CỦA ĐỒ THỊ LIÊN THÔNG
// khởi tạo ma trận đỉnh(nhãn(i))
// 1 2 3 4 5 6 7 8
// 0 0 0 0 0 0 0 0
// xét đỉnh 1 tăng stplienthong len 1 và gán nhãn[1] = 1
// tiến hành xét tiếp đỉnh tiếp theo
// xét đk có đường nối vs đỉnh đang xét gán nhãn = 1 xét đệ quy đến hết các đỉnh. Sang phần liên thông khác
// Xuất các thành phần liên thông:
// sau khi chạy ma trận nhãn thành:
// 1 2 4 6 7 3 5
// 1 1 1 1 1 2 2
// xét lần lượt các SoThanhPhanLT rồi xuất giá trị j
// ****************************************************************
void DiTimCacDinhLienThong(dothi g, int nhan[MAX], int i)
{
    // tìm đỉnh tiếp theo trong dt liên thông
    for (int j = 0; j < g.n; j++)
    {
        //Điều kiện a[i][j] trên ma trận kề <> 0; nhãn i = 1 <> nhãn j = 0 -> nút chưa xét
        if (g.a[i][j] != 0 && nhan[j] != nhan[i])
        {
            nhan[j] = nhan[i];
            DiTimCacDinhLienThong(g, nhan, j);
        }
    }
}

void XetLienThong(dothi g)
{
    int Nhan[MAX];
    int i;
    int SoThanhPhanLT = 0;
    // khởi tạo tất cả đỉnh i có nhãn = 0 và SoThanhPhanLT = 0
    for (int i = 0; i < MAX; i++)
        Nhan[i] = 0;

    for (i = 0; i < g.n; i++)
    {
        if (Nhan[i] == 0)
        {
            SoThanhPhanLT++;
            Nhan[i] = SoThanhPhanLT;
            // - Tìm các đỉnh j có nối với i xem đỉnh j nào có nhãn =0,
            // thì gán lại nhãn cho đỉnh j, nhan[j] = nhan[i].
            DiTimCacDinhLienThong(g, Nhan, i);
            // hết các nút kề nhau trong 1 thành phần liên thông
        }
        // tăng i đến nút tiếp theo nếu nút chưa xét tức nhan[i] = 0 tiếp tục xét
    }
    cout << "\nSo thanh phan lien thong la: " << SoThanhPhanLT << endl;
    for (i = 1; i <= SoThanhPhanLT; i++)
    {
        cout << "Thanh phan lien thong thu " << i << " gom cac dinh: ";
        for (int j = 1; j <= g.n; j++)
        // G.n số lượng đồ thị
        {
            if (Nhan[j] == i)
                cout << " " << j;
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    dothi g;

    docfile(g);
    xuatfile(g);
    if (kiemtramatranke(g))
        cout << "\n * Ma tran hop le!";
    else
        cout << "\n * Ma tran khong hop le!";
    if (kiemtradothivohuong(g))
        cout << "\n * Ma tran vo huong!";
    else
        cout << "\n * Ma tran co huong!";

    XetLienThong(g);
    fclose(f);
}
