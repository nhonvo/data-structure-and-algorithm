#include <stdio.h>
#include <conio.h>

int main()
{
	int n, u;
	scanf("%d", &n);
	do
	{
		u = n % 10;
		n = n / 10;
		printf("%d", u);
	} while (n != 0);
}
