#include <stdio.h>
#include <stdbool.h>

void uoc(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			printf("   %d   ", i);
	}
}

int tongUoc(int n)
{
	int s, i;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			s += i;
	}
	return s;
}

int demUoc(int n)
{
	int i, cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			cnt++;
	}
	return cnt;
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
		// printf("true");
		return true;
	}
	else
	{
		//	printf("false");
		return false;
	}
}
int xuatnt(int n)
{
	int i;
	for (i = 2; i <= n; i++)
	{
		if (ktnt(i))
			printf("   %d  ", i);
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
	uoc(n);
	printf("\nso cac so uoc=%d\n", demUoc(n));
	printf("\nTong so s=%d\n", tongUoc(n));
	xuatnt(n);
	return 0;
}
