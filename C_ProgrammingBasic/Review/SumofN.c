#include <stdio.h>

int main()
{
	int n, i, u, s;
	printf("Nhap n=");
	scanf("%d", &n);
	if (n > 0)
	{
		for (i = 1; i <= n; i++)
		{
			u = n % 10;
			n = n / 10;
			s = s + u;
		}
		printf("\nSum of number is: %d", s);
	}
	return 0;
}
