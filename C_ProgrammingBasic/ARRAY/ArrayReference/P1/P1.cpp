#include "MyFunctions.h"
#include <iostream>
#include<cmath>
using namespace std;
int main(int argc, const char * argv[])
{
	int a[1001], n;
	nhapmang(n,a);
	cout << "Tong cac phan tu khong am : " << Sump(n,a) << endl;
	cout <<"Tong cac phan tu chia het cho 3 : " << Sumdiv(a,n) << endl;
	cout <<"Tong cac phan tu co chu so dau tien la so le : " << sumodd(n,a) << endl;
}
