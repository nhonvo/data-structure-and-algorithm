
#include <stdio.h>
#define max 110

int nhapMang(int n, float a[max])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("a[%d]:", i);
		scanf("%f", &a[i]);
	}
}
int chan(int n, float a[max])
{
	int i, cnt = 0;

	for (i = 1; i <= n; i++)
	{
		if ((int)a[i] == a[i])
		{
			if ((int)a[i] % 2 == 0)
				cnt++;
		}
	}
	printf("%d", cnt);
}
int main()
{
	int n;
	float a[max];
	printf("Enter N:");
	scanf("%d", &n);
	nhapMang(n, a);
	chan(n, a);
	return 0;
}
