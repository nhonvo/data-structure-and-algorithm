#include <bits/stdc++.h>

using namespace std;

void Input(int a[], int &n);
void Output(int a[], int &n);
bool IsPrime(int n);
void ADontExistsInB(int a[], int b[], int &n, int &m);
bool ASubArray(int a[], int b[], int &n, int &m);
void LongestContinuesIncrease(int a[], int &n);

int main()
{
    // int A[] = {2, 3, 0, -5, 1, 1, 2};
    int A[] = {1, 2, 3, -5, 1, 1, 2};
    int n = sizeof(A) / sizeof(int);
    int B[] = {3, 0, 5, 1};
    int m = sizeof(B) / sizeof(int);

    // cout << "Sumest: " << SumestContinuesIncrease(A, n) << endl;
    LongestContinuesIncrease(A, n);

    return 0;
}
// ----------------------------------------------------------------

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
// Check prime numbers
bool IsPrime(int n)
{
    int count = 0;
    if (n < 2)
        return false;
    for (int i = 1; i <= sqrt(n); i++)
    {
        /* code */
        if (n % i == 0)
            count++;
    }
    if (count == 1)
        return true;
}
// check elements of array A exist in array b

void ADontExistsInB(int a[], int b[], int &n, int &m)
{
    int c[1000];
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (c[b[i]] == 0)
        {
            cout << "number: " << c[i] << endl;
        }
    }
}

// check the array A is a subarray
bool ASubArray(int a[], int b[], int &n, int &m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
            if (j == m)
            {
                return true;
            }
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
}
/**
 * Three steps for this exercise:
 * check elements a[i] < a[i+1] = true ? increase count : 
 * false: assign again max value and locations value
 * and make count values begin at 1 again 
*/
/**
 * int A[] = {2, 3, 0, 5, 1, 1, 2};
 * output: {2, 3}
 */

void LongestContinuesIncrease(int a[], int &n)
{
    int count = 0, locations = 0, max = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] < a[i + 1])
        {
            count++;
        }
        else
        {
            if (count > max)
            {
                max = count;
                locations = i - count + 1;
            }
            count = 1;
        }
    }
    printf("\nThe longest counties string is:");
    for (int i = locations; i < locations + max; i++)
    {
        cout << a[i] << " ";
    }
}