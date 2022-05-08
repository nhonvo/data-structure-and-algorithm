#include <stdio.h>

void saoA(int n, int k)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		printf("\n");
		for (j = 1; j <= k; j++)
		{
			printf("*");
		}
	}
}

int saoB(int n, int k)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		printf("\n");
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
	}
}
int main()
{
	int n, i, j, k;
	printf("Nhap n=");
	scanf("%d", &n);
	printf("Nhap k=");
	scanf("%d", &k);

	saoA(n, k);
	saoB(n, k);
	return 0;
}
