#include <iostream>

using namespace std;
void Input(int a[][], int &n, int &m);
void Output(int a[][], int n, int m);
void Menu(int a[][], int &n, int &m);
void Sort(int a[][], int n, int m);
void Search(int a[][], int n, int m);
void Fetch(int a[][], int n, int m);
void Balance(int a[][], int n, int m);
void Rotate(int a[][], int n, int m);
void Mirror(int a[][], int n, int m);


int main(int argc, char const *argv[])
{
    int n = 10;
    int m = 10;
    int a[n][m];
    Menu(a, n, m);
    return 0;
}
void Input(int a[][], int &n, int &m)
{
    cout << "Enter number of rows of array: ";
    cin >> n;
    cout << "Enter number of columns of array: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}
void Output(int a[][], int n, int m)
{
    cout << "array: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void Sort(int a[][], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (a[i][j] < a[k][l])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                    }
                }
            }
        }
    }
}
void Search(int a[][], int n, int m)
{
    int x;
    cout << "Enter element to search: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == x)
            {
                cout << "Element " << x << " is at position a[" << i << "][" << j << "]" << endl;
            }
        }
    }
}
void Fetch(int a[][], int n, int m)
{
    int x;
    cout << "Enter element to fetch: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == x)
            {
                a[i][j] = 0;
            }
        }
    }
}
void Balance(int a[][], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += a[i][j];
        }
    }
    int avg = sum / (n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > avg)
            {
                a[i][j] = avg;
            }
        }
    }
}
void Rotate(int a[][], int n, int m)
{
    int b[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[j][n - i - 1] = a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void Mirror(int a[][], int n, int m)
{
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i][m - j - 1] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void Menu(int a[][], int &n, int &m)
{
    int choice;
    do
    {
        cout << "1. Input array" << endl;
        cout << "2. Output array" << endl;
        cout << "3. Sort array" << endl;
        cout << "4. Search element" << endl;
        cout << "5. Fetch element" << endl;
        cout << "6. Balance array" << endl;
        cout << "7. Rotate array" << endl;
        cout << "8. Mirror array" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(a, n, m);
            break;
        case 2:
            Output(a, n, m);
            break;
        case 3:
            Sort(a, n, m);
            break;
        case 4:
            Search(a, n, m);
            break;
        case 5:
            Fetch(a, n, m);
            break;
        case 6:
            Balance(a, n, m);
            break;
        case 7:

            Rotate(a, n, m);
            break;
        case 8:
            Mirror(a, n, m);
            break;
        case 9:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 7);
}
