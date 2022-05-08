#include "MyFunctions.h"
#include <iostream>
using namespace std;
int main()
{
	int a[1001];
	int n;
	nhapmang(a, n);
	if (checkp(a, n)) cout << "Mang co so duong."<< endl;
	else cout << "Mang khong co so duong." << endl;
	
	if (checkpall(a, n)) cout << "Mang chua toan so duong." << endl;
	else cout << "Mang khong chua toan so duong." << endl;

	cout << "Day moi khong co so duong : " << endl;
	hoandoi(a, n);
}