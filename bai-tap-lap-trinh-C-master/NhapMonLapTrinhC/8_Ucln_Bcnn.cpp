#include <stdio.h>
#include <conio.h>
int main()
{
	int a, b, c, d, r, ucln;
	printf ("nhap hai so: ");
	scanf ("%d %d", &a, &b);
	c = a; d = b;
	while (b != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	ucln = a;
	printf ("ucln la: %d\n", ucln);
	printf ("bcnn la: %d", (c*d)/ucln);
	return 0;
}
