#include "MyFunctions.h"
#include <iostream>
using namespace std;
int main()
{
	float a[1001];
	int n;
	nhapmang(a, n);
	cout << "So phan tu am : " << dem(a, n);
}