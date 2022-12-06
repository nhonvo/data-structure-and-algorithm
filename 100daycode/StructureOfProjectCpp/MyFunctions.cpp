#include "MyFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;

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
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// Bubble sort (n−1)+(n−2)+...+2+1= (n−1)n​ /2
//=> O(n^2)

void BubbleSort(int a[], int &n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}
// InterchangeSort
void InterchangeSort(int a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
// SelectionSort
void SelectionSort(int a[], int &n)
{

    for (int i = 0; i < n; i++)
    {
        int minLocations = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minLocations])
            {
                minLocations = j;
            }
        }
        swap(a[minLocations], a[i]);
    }
}
// InsertSort
void InsertSort(int a[], int &n)
{
    int pos, x;
    for (int i = 1; i < n; i++)
    {
        pos = i - 1, x = a[i];
        while (pos >= 0 && a[pos] > x) // compare 2 elements (back and front)
        {
            a[pos + 1] = a[pos]; // assign to front
            pos--;               // counties decrease to condition false
        }
        a[pos + 1] = x; // assign to back
    }
}
/**
 * gap = 2, 1
 * 12 34 54 2 3
 *    (2)  (34)
 *
 */
// ShellSort THE Average Case Complexity: O(n*log n)
void ShellSortGeekforGeek(int a[], int &n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = a[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            //  put temp (the original a[i]) in its correct location
            a[j] = temp;
        }
    }
}
// Another Shell sort in hutech docmentation - error can't working
void ShellSort(int a[], int n, int h[], int k)
{
    int step, i, pos, x, len;
    for (step = 0; step < k; step++)
    {
        len = h[step];
        for (i = len; i < n; i++)
        {
            x = a[i];
            pos = i - len;
            while ((x < a[pos] && pos >= 0))
            {
                a[pos + len] = a[pos];
                pos = pos - len;
            }
        }
        a[pos + len] = x;
    }
}

/**
 * 3 5 4 1 2 
 * 2 5 4 1 3
 * 2 1 4 5 3
 * 2 1 3 5 4
 * 2 1 
*/

int partition(int a[], int left, int right)
{
	int i = left;
	int j = right - 1;	  //khong con j=right vi vtr nay gio la cua pivot
	int pivot = a[right]; //chon pivot buoc nay quyet dinh nhanh cham cua bai toan
	while (true)
	{
		while (pivot > a[i] && i <= j)
			i++;
		while (pivot < a[j] && i <= j)
			j--;
		if (i >= j)
		{		   //bat buoc dung cau truc nay khong dung i<j
			break; //duyet xong thoat vong lap
		}
		else
		{
			swap(a[i], a[j]); //chua xong doi cho
			i++;			  //dang xet nen tang,giam
			j--;
		}
	}
	swap(a[i], a[right]); //doi cho a[i] voi pivot
	return i;			  // tra ve vi de chia doi mang vtri nay la vtr dung
}
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pi = partition(arr, left, right); //lay vitri chuan so da dug vtr chi sep hai ben trai va phai
		QuickSort(arr, left, pi - 1);
		QuickSort(arr, pi + 1, right);
	}
}