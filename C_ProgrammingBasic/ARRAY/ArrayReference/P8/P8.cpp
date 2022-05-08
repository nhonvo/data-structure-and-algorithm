#include "MyFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[1001];
	int n;
	nhapmang(a, n);
	cout << dem_6(a, n) << endl;
	cout << setprecision(2) << fixed << tbsnt(a, n) << endl;
	dempb(a, n);
}