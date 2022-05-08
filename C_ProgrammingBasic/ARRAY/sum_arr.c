#include <stdio.h>
#define max_size 100
int main()
{
	int n, m, i, j, s = 0;
	int a[max_size][max_size];
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] % 5 == 0)
				s += a[i][j];
		}
	}
	printf("%d", s);
	return 0;
}
