#include "MyFunctions.h"
#include <iostream>
using namespace std;
int main()
{
	int a[1001];
	int n;
	nhapmang(a, n);
	if (checkdx(a, n)) cout << "Mang doi xung." << endl;
	else cout << "Mang khong doi xung." << endl;

	if (checknp(a, n)) cout << "Mang co dan xen am duong." << endl;
	else cout << "Mang khong dan xen am duong." << endl;

	if (check(a, n)) cout << "Mang co cac cap phan tu khac nhau." << endl;
	else cout << "Mang khong co cac cap phan tu khac nhau." << endl;

	if (checkcsc(a, n)) cout << "Mang co 3 phan tu canh nhau lap thanh csc." << endl;
	else cout << "Mang khong co 3 phan tu canh nhau lap thanh csc." << endl;

}