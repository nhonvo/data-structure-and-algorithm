#include <stdio.h>
#include <stdbool.h>

int tongUoc(int n)
{
	int s = 0, i;
	for (i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			s += i;
	}
	return s;
}

bool ktnt(int n)
{
	int i, cnt = 0;

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cnt++;
		}
	}
	if (cnt == 2)
	{
		printf("true");
		return true;
	}
	else
	{
		printf("false");
		return false;
	}
}

int main()
{
	int n;
	do
	{
		printf("Nhap n=");
		scanf("%d", &n);
		if (n <= 1 || n >= 100)
		{
			printf("Nhap sai nhap lai.");
		}
	} while (n <= 1 || n >= 100);
	ktnt(n);
	printf("\nTong so s=%d\n", tongUoc(n));

	int s = tongUoc(n);
	if (s == n)
	{
		printf("\n%d la so hoan thien", n);
	}
	else
	{
		printf("\n%d khong phai so hoan thien", n);
	}
	return 0;
}
