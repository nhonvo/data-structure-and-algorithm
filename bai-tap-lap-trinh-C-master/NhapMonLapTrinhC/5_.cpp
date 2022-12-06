#include <stdio.h>
#include <conio.h>
int main()
{
	int n, x;
	int luythua = 1;
	int tong = 0;
	printf ("nhap: ");
	scanf ("%d %d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		luythua = luythua * x;
		tong = tong + luythua;
	}
	printf ("%d", tong);
	return 0;
		
}
