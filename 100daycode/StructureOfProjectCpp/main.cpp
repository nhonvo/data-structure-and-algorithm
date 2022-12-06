#include "MyFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int A[] = {1, 2, 3, -5, 1, 1, 2};
    int n = sizeof(A) / sizeof(int);
    Output(A, n);
    // ShellSortGeekforGeek(A, n);
    QuickSort(A, 1,5);    
    Output(A, n);
    return 0;
}
