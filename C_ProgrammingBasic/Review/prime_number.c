#include <stdio.h>

int main()
{
	int n, i, s, u = 0, dem = 0;
	printf("Enter number n:");
	scanf("%d", &n);

	if (n > 0)
	{
		for (i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				s = i;
				printf("s=%d\n", s);
				u = u + s;
				dem++;
				if (n % i == 0)
				{
				}
			}
		}
		printf("Sum u=%d\n", u);
		printf("dem=%d", dem);
	}
	else
	{
		printf("ERROR.Enter again");
	}
	return 0;
}
