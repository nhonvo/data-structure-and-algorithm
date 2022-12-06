#include <stdio.h>
#include <conio.h>
int main()
{
	int n, tong = 0;
	printf ("Nhap vao mot so: "); scanf ("%d", &n);
	for (int i = 1; i < n; i++)
	{
		if (n%i==0)
		tong = tong + i;
	}
	if (tong == n)
		printf ("%d la so hoan thien", n);
	else 
		printf ("%d khong la so hoan thien", n);
	return 0;
}
