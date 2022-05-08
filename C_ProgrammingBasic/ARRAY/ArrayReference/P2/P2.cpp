#include "MyFunctions.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[1001];
	int n;
	nhapmang(a, n);
	cout << endl;
	cout <<"Tong cac so chinh phuong : "<< sumcp(a, n) << endl;
	cout <<"Tong cac so hoan chinh : "<< sumhc(a, n) << endl;
	cout <<"Tong cac so nguyen to : "<< sumsnt(a, n) << endl;
	cout <<"Tong cac so duong doi xung : "<< sumdx(a, n) << endl;
}