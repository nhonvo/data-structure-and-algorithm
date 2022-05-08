#include "MyFunctions.h"
#include <iostream>
using namespace std;
int main()
{
	int a[1001], b[1001];
	int n, m;
	nhapmang(a, b, n, m);
	xuatpt(a, b, n, m);
	cout << endl;
	day_c(a, b, n, m);
}