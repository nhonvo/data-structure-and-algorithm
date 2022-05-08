#include <stdio.h>

int salaryDay(int v, int r)
{
	int s, n;
	if (r < 0 || v >> 24)
	{
		printf("Error.Enter again");
	}
	else
	{
		n = r - v;
		printf("Total hour of day:%dh\n", n);
		if (n > 12)
		{
			s = n * 6000;
			s = s + (n - 12) * 7500;
		}
		else
		{
			s = n * 6000;
		}
		printf("Today's salary:%dd\n", s);
	}
}
int main()
{
	int n, r, v;
	printf("Basic\n ----------Hour in 6h---------\n--------Hour out 18h-----------\n");
	printf("Enter hour in:");
	scanf("%d", &v);
	printf("Enter hour out:");
	scanf("%d", &r);
	salaryDay(v, r);
	return 0;
}
