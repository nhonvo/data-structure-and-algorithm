#include <iostream>

using namespace std;
void Input(int a[], int &n);
void Output(int a[], int &n);

void Merge(int a[], int &n, int b[], int &m, int c[], int &p);
void Split(int a[], int &n, int b[], int &m, int c[], int &p);
void SplitFirst(int a[], int &n, int b[], int &m, int c[], int &p);
void SplitLast(int a[], int &n, int b[], int &m, int c[], int &p);

void MergeSort(int a[], int &n);
void MergeSortIncrease(int a[], int &n);
void MergeSortDecrease(int a[], int &n);

void BubbleSort(int a[], int &n);
void BubbleSortIncrease(int a[], int &n);
void BubbleSortDecrease(int a[], int &n);

void SelectionSort(int a[], int &n);
void SelectionSortIncrease(int a[], int &n);
void SelectionSortDecrease(int a[], int &n);

void InsertionSort(int a[], int &n);
void InsertionSortIncrease(int a[], int &n);
void InsertionSortDecrease(int a[], int &n);

void QuickSort(int a[], int &n);
void QuickSortIncrease(int a[], int &n);
void QuickSortDecrease(int a[], int &n);

void HeapSort(int a[], int &n);
void HeapSortIncrease(int a[], int &n);
void HeapSortDecrease(int a[], int &n);

void ShellSort(int a[], int &n);
void ShellSortIncrease(int a[], int &n);
void ShellSortDecrease(int a[], int &n);

void RadixSort(int a[], int &n);
void RadixSortIncrease(int a[], int &n);
void RadixSortDecrease(int a[], int &n);

void CountingSort(int a[], int &n);
void CountingSortIncrease(int a[], int &n);
void CountingSortDecrease(int a[], int &n);

void Menu(int a[], int &n);

int main()
{
    int a[100], n;
    Input(a, n);
    Menu(a, n);
    return 0;
}

void Merge(int a[], int &n, int b[], int &m, int c[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    n = n + m;
    for (int i = 0; i < n; i++)
    {
        a[i] = c[i];
    }
}
void Split(int a[], int &n, int b[], int &m, int c[], int &p)
{
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
        }
        i++;
    }
    n = j;
    m = k;
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
}
void SplitIncrease(int a[], int &n, int b[], int &m, int c[], int &p)
{
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
        }
        i++;
    }
    n = j;
    m = k;
    SortIncrease(b, n);
    SortIncrease(c, m);
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
}
void SplitDecrease(int a[], int &n, int b[], int &m, int c[], int &p)
{
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
        }
        i++;
    }
    n = j;
    m = k;
    SortDecrease(b, n);
    SortDecrease(c, m);
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
}
void SplitReverse(int a[], int &n, int b[], int &m, int c[], int &p)
{
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
        }
        i++;
    }
    n = j;
    m = k;
    Reverse(b, n);
    Reverse(c, m);
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
}
void SplitFirst(int a[], int &n, int b[], int &m, int c[], int &p)
{
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
        }
        i++;
    }
    n = j;
    m = k;
    FetchFirst(b, n);
    FetchFirst(c, m);
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
}
void SplitLast(int a[], int &n, int b[], int &m, int c[], int &p)
{
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
        else
        {
            c[k] = a[i];
            k++;
        }
        i++;
    }
    n = j;
    m = k;
    FetchLast(b, n);
    FetchLast(c, m);
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
}
void Merge(int a[], int &n, int b[], int &m, int c[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    n = n + m;
    for (int i = 0; i < n; i++)
    {
        a[i] = c[i];
    }
}
void MergeSort(int a[], int &n)
{
    int b[100], c[100];
    int m = 0, p = 0;
    Split(a, n, b, m, c, p);
    Merge(b, m, c, p, a);
}
void MergeSortIncrease(int a[], int &n)
{
    int b[100], c[100];
    int m = 0, p = 0;
    SplitIncrease(a, n, b, m, c, p);
    Merge(b, m, c, p, a);
}
void MergeSortDecrease(int a[], int &n)
{
    int b[100], c[100];
    int m = 0, p = 0;
    SplitDecrease(a, n, b, m, c, p);
    Merge(b, m, c, p, a);
}
void BubbleSort(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                Swap(a[j], a[j - 1]);
            }
        }
    }
}
void BubbleSortIncrease(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                Swap(a[j], a[j - 1]);
            }
        }
    }
}
void BubbleSortDecrease(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j] > a[j - 1])
            {
                Swap(a[j], a[j - 1]);
            }
        }
    }
}
void InsertionSort(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 1; i < n; i++)
    {
        int x = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
void InsertionSortIncrease(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 1; i < n; i++)
    {
        int x = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
void InsertionSortDecrease(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 1; i < n; i++)
    {
        int x = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
void SelectionSort(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        Swap(a[i], a[min]);
    }
}
void SelectionSortIncrease(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        Swap(a[i], a[min]);
    }
}
void SelectionSortDecrease(int a[], int &n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[min])
            {
                min = j;
            }
        }
        Swap(a[i], a[min]);
    }
}
void QuickSort(int a[], int &n)
{
    int i = 0, j = 0;
    int x = a[n / 2];
    do
    {
        while (a[i] < x)
        {
            i++;
        }
        while (a[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
    {
        QuickSort(a, j);
    }
    if (i < n)
    {
        QuickSort(a + i, n - i);
    }
}
void QuickSortIncrease(int a[], int &n)
{
    int i = 0, j = 0;
    int x = a[n / 2];
    do
    {
        while (a[i] < x)
        {
            i++;
        }
        while (a[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
    {
        QuickSort(a, j);
    }
    if (i < n)
    {
        QuickSort(a + i, n - i);
    }
}
void QuickSortDecrease(int a[], int &n)
{
    int i = 0, j = 0;
    int x = a[n / 2];
    do
    {
        while (a[i] > x)
        {
            i++;
        }
        while (a[j] < x)
        {
            j--;
        }
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
    {
        QuickSort(a, j);
    }
    if (i < n)
    {
        QuickSort(a + i, n - i);
    }
}
void HeapSort(int a[], int &n)
{
    int i = 0;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        Swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}
void HeapSortIncrease(int a[], int &n)
{
    int i = 0;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        Swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}
void HeapSortDecrease(int a[], int &n)
{
    int i = 0;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        Swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}
void ShellSort(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            int x = a[i];
            for (j = i; j >= k; j -= k)
            {
                if (x < a[j - k])
                {
                    a[j] = a[j - k];
                }
                else
                {
                    break;
                }
            }
            a[j] = x;
        }
    }
}
void ShellSortIncrease(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            int x = a[i];
            for (j = i; j >= k; j -= k)
            {
                if (x < a[j - k])
                {
                    a[j] = a[j - k];
                }
                else
                {
                    break;
                }
            }
            a[j] = x;
        }
    }
}
void ShellSortDecrease(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            int x = a[i];
            for (j = i; j >= k; j -= k)
            {
                if (x > a[j - k])
                {
                    a[j] = a[j - k];
                }
                else
                {
                    break;
                }
            }
            a[j] = x;
        }
    }
}
void RadixSort(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    int b[10][100], buck[10];
    for (i = 0; i < 10; i++)
    {
        buck[i] = 0;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < n; j++)
        {
            int x = a[j] % (int)pow(10, i + 1) / (int)pow(10, i);
            b[x][buck[x]] = a[j];
            buck[x]++;
        }
        for (j = 0, k = 0; j < 10; j++)
        {
            int y = 0;
            for (y = 0; y < buck[j]; y++)
            {
                a[k] = b[j][y];
                k++;
            }
            buck[j] = 0;
        }
    }
}
void RadixSortIncrease(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    int b[10][100], buck[10];
    for (i = 0; i < 10; i++)
    {
        buck[i] = 0;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < n; j++)
        {
            int x = a[j] % (int)pow(10, i + 1) / (int)pow(10, i);
            b[x][buck[x]] = a[j];
            buck[x]++;
        }
        for (j = 0, k = 0; j < 10; j++)
        {
            int y = 0;
            for (y = 0; y < buck[j]; y++)
            {
                a[k] = b[j][y];
                k++;
            }
            buck[j] = 0;
        }
    }
}
void RadixSortDecrease(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    int b[10][100], buck[10];
    for (i = 0; i < 10; i++)
    {
        buck[i] = 0;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < n; j++)
        {
            int x = a[j] % (int)pow(10, i + 1) / (int)pow(10, i);
            b[x][buck[x]] = a[j];
            buck[x]++;
        }
        for (j = 0, k = 0; j < 10; j++)
        {
            int y = 0;
            for (y = 0; y < buck[j]; y++)
            {
                a[k] = b[j][y];
                k++;
            }
            buck[j] = 0;
        }
    }
}
void CountingSort(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    int b[100], c[100];
    for (i = 0; i < 100; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (i = 1; i < 100; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void CountingSortIncrease(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    int b[100], c[100];
    for (i = 0; i < 100; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (i = 1; i < 100; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void CountingSortDecrease(int a[], int &n)
{
    int i = 0, j = 0, k = 0;
    int b[100], c[100];
    for (i = 0; i < 100; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (i = 1; i < 100; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void Menu()
{
    cout << "1. Nhap mang" << endl;
    cout << "2. Xuat mang" << endl;
    cout << "3. Sap xep tang dan" << endl;
    cout << "4. Sap xep giam dan" << endl;
    cout << "5. Thoat" << endl;
    int choose = 0;
    cout << "Nhap lua chon: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        Input(a, n);
        break;
    case 2:
        Output(a, n);
        break;
    case 3:
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Heap Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Radix Sort" << endl;
        cout << "8. Counting Sort" << endl;
        cout << "Nhap lua chon: ";
        int choose1 = 0;
        cin >> choose1;
        switch (choose1)
        {
        case 1:
            BubbleSortIncrease(a, n);
            break;
        case 2:
            SelectionSortIncrease(a, n);
            break;
        case 3:
            InsertionSortIncrease(a, n);
            break;
        case 4:
            QuickSortIncrease(a, 0, n - 1);
            break;
        case 5:
            HeapSortIncrease(a, n);
            break;
        case 6:
            MergeSortIncrease(a, 0, n - 1);
            break;
        case 7:
            RadixSortIncrease(a, n);
            break;
        case 8:
            CountingSortIncrease(a, n);
            break;
        }
        break;
    case 4:
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Heap Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Radix Sort" << endl;
        cout << "8. Counting Sort" << endl;
        cout << "Nhap lua chon: ";
        int choose2 = 0;
        cin >> choose2;
        switch (choose2)
        {
        case 1:
            BubbleSortDecrease(a, n);
            break;
        case 2:
            SelectionSortDecrease(a, n);
            break;
        case 3:
            InsertionSortDecrease(a, n);
            break;
        case 4:
            QuickSortDecrease(a, 0, n - 1);
            break;
        case 5:
            HeapSortDecrease(a, n);
            break;
        case 6:
            MergeSortDecrease(a, 0, n - 1);
            break;
        case 7:
            RadixSortDecrease(a, n);
            break;
        case 8:
            CountingSortDecrease(a, n);
            break;
        }
        break;
    case 5:
        exit(0);
        
    }