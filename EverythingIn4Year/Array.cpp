#include <iostream>

using namespace std;
void Input(int a[], int &n);
void Output(int a[], int &n);

void InsertFirst(int a[], int &n, int x);
void InsertLast(int a[], int &n, int x);
void Insert(int a[], int &n, int x, int k);

void DeleteFirst(int a[], int &n);
void DeleteLast(int a[], int &n);
void Delete(int a[], int &n, int k);
void DeleteAll(int a[], int &n, int x);
void DeleteAllFirst(int a[], int &n, int x);
void DeleteAllLast(int a[], int &n, int x);

void Search(int a[], int &n, int x);
void SearchFirst(int a[], int &n, int x);
void SearchLast(int a[], int &n, int x);

void SortIncrease(int a[], int &n);
void SortDecrease(int a[], int &n);
void Reverse(int a[], int &n);

void Fetch(int a[], int &n, int k);
void FetchFirst(int a[], int &n);
void FetchLast(int a[], int &n);

void Menu(int a[], int &n);

int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Menu(arr, n);
    return 0;
}

void Input(int a[], int &n)
{
    cout << "Enter number of elements of array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void Output(int a[], int &n)
{
    cout << "Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
}
// 1 2 3 4
// a[4] = 4, a[3] = 3, a[2] = 2, a[1] = 1, a[0] = 0
void InsertFirst(int a[], int &n, int x)
{
    for (int i = n; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = x;
    n++;
}
void InsertLast(int a[], int &n, int x)
{
    a[n] = x;
    n++;
}
// 1 2 3 4 k = 2
// a[4] = 4, a[3] = 3, a[2] = x; a[1] = 2, a[0] = 1
void Insert(int a[], int &n, int x, int k)
{
    for (int i = n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = x;
    n++;
}
void DeleteFirst(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}
void DeleteLast(int a[], int &n)
{
    n--;
}
void Delete(int a[], int &n, int k)
{
    for (int i = k; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}
void DeleteAllLast(int a[], int &n, int x)
{
    int i = n - 1;
    while (i >= 0)
    {
        if (a[i] == x)
        {
            Delete(a, n, i);
        }
        i--;
    }
}
void DeleteAllFirst(int a[], int &n, int x)
{
    int i = 0;
    while (i < n)
    {
        if (a[i] == x)
        {
            Delete(a, n, i);
        }
        i++;
    }
}
void DeleteAll(int a[], int &n, int x)
{
    int i = 0;
    while (i < n)
    {
        if (a[i] == x)
        {
            Delete(a, n, i);
        }
        i++;
    }
}
void Search(int a[], int &n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Found at a[" << i << "]" << endl;
        }
    }
}
void SearchFirst(int a[], int &n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Found at a[" << i << "]" << endl;
            break;
        }
    }
}
void SearchLast(int a[], int &n, int x)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == x)
        {
            cout << "Found at a[" << i << "]" << endl;
            break;
        }
    }
}
void SortIncrease(int a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void Reverse(int a[], int &n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void SortDecrease(int a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void Fetch(int a[], int &n, int k)
{
    cout << "a[" << k << "] = " << a[k] << endl;
}
void FetchFirst(int a[], int &n)
{
    cout << "a[0] = " << a[0] << endl;
}
void FetchLast(int a[], int &n)
{
    cout << "a[" << n - 1 << "] = " << a[n - 1] << endl;
}

void Menu(int a[], int &n)
{
    int choice;
    do
    {
        cout << "1. Input" << endl;
        cout << "2. Output" << endl;
        cout << "3. InsertFirst" << endl;
        cout << "4. InsertLast" << endl;
        cout << "5. Insert" << endl;
        cout << "6. DeleteFirst" << endl;
        cout << "7. DeleteLast" << endl;
        cout << "8. Delete" << endl;
        cout << "9. Fetch" << endl;
        cout << "10. Search" << endl;
        cout << "11. Sort decease" << endl;
        cout << "12. Reverse" << endl;
        cout << "13. DeleteAllFirst" << endl;
        cout << "14. DeleteAllLast" << endl;
        cout << "15. DeleteAll" << endl;
        cout << "16. SearchFirst" << endl;
        cout << "17. SearchLast" << endl;
        cout << "18. FetchFirst" << endl;
        cout << "19. FetchLast" << endl;
        cout << "20. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(a, n);
            break;
        case 2:
            Output(a, n);
            break;
        case 3:
            int x;
            cout << "Enter x: ";
            cin >> x;
            InsertFirst(a, n, x);
            break;
        case 4:
            int y;
            cout << "Enter y: ";
            cin >> y;
            InsertLast(a, n, y);
            break;
        case 5:
            int z, k;
            cout << "Enter z: ";
            cin >> z;
            cout << "Enter k: ";
            cin >> k;
            Insert(a, n, z, k);
            break;
        case 6:
            DeleteFirst(a, n);
            break;
        case 7:
            DeleteLast(a, n);
            break;
        case 8:
            int m;
            cout << "Enter m: ";
            cin >> m;
            Delete(a, n, m);
            break;
        case 9:
            int l;
            cout << "Enter l: ";
            cin >> l;
            Fetch(a, n, l);
            break;
        case 10:
            int t;
            cout << "Enter t: ";
            cin >> t;
            Search(a, n, t);
            break;
        case 11:
            SortIncrease(a, n);
            break;
        case 12:
            Reverse(a, n);
            break;
        case 13:
            SearchFirst(a, n, t);
            break;
        case 14:
            SearchLast(a, n, t);
            break;
        case 15:
            DeleteAllFirst(a, n, t);
            break;
        case 16:
            DeleteAllLast(a, n, t);
            break;
        case 17:
            DeleteAll(a, n, t);
            break;
        case 18:
            FetchFirst(a, n);
            break;
        case 19:
            FetchLast(a, n);
            break;
        case 20:
            SortDecrease(a, n);
            break;
        case 21:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 21);
}
