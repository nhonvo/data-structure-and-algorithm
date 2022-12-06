#include <iostream>

using namespace std;
void Input(int a[], int &n);
void Output(int a[], int &n);

void BinarySerach(int a[], int &n, int x);
void InterpolationSearch(int a[], int &n, int x);
void FibonacciSearch(int a[], int &n, int x);
void InterpolationSearch(int a[], int &n, int x);
void Menu(int a[], int &n);

int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Menu(arr, n);
    return 0;
}
void BinarySerach(int a[], int &n, int &x)
{
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            cout << "The number is in the array" << endl;
            break;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left > right)
    {
        cout << "The number is not in the array" << endl;
    }
}

void InterpolationSearch(int a[], int &n, int &x)
{
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) * (x - a[left]) / (a[right] - a[left]);
        if (a[mid] == x)
        {
            cout << "The number is in the array" << endl;
            break;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left > right)
    {
        cout << "The number is not in the array" << endl;
    }
}
void FibonacciSearch(int a[], int &n, int &x)
{
    int f1 = 0, f2 = 1, f3 = 1, mid = 0;
    while (f3 < n)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    while (f3 > 1)
    {
        mid = min(f1 + f2 - 1, n - 1);
        if (a[mid] == x)
        {
            cout << "The number is in the array" << endl;
            break;
        }
        else if (a[mid] > x)
        {
            f3 = f2;
            f2 = f1;
            f1 = f3 - f2;
        }
        else
        {
            f3 = f1;
            f2 = f2 - f1;
            f1 = f3 - f2;
            mid = mid + 1;
        }
    }
    if (a[mid] != x)
    {
        cout << "The number is not in the array" << endl;
    }
}
void InterpolationSearch(int a[], int &n, int &x)
{
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) * (x - a[left]) / (a[right] - a[left]);
        if (a[mid] == x)
        {
            cout << "The number is in the array" << endl;
            break;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left > right)
    {
        cout << "The number is not in the array" << endl;
    }
}