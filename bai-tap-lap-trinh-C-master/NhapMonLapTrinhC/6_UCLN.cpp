#include <stdio.h>
#include <conio.h>
int TimUCLN(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int NhapsoDuong(int &a, int &b)
{
	do
	{
		printf ("Nhap vao hai so lon hon 0: ");
		scanf ("%d %d", &a, &b);
	}while ((a <= 0)||(b <= 0));
}
int main()
{
	int a, b;
	NhapsoDuong(a, b);
	int kq = TimUCLN(a,b);
	printf ("UCLN la: %d", kq);
	return 0;
}
