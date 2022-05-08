#include <stdio.h>

int mot(int n)
{
	printf("chu so n=%d", n);
}

int hai(int n)
{
	int cnt, s;
	while (n > 0)
	{
		s = n % 10;
		n = n / 10;
		cnt++;
		printf("    %d   ", s);
	}
	printf("\nSo cac so n=%d", cnt);
}
int ba(int n)
{
	int s, u;
	while (n > 0)
	{
		s = n % 10;
		n = n / 10;
		u += s;
	}
	printf("\nTong so n=%d", u);
}
int bon(int n)
{
	int cnt, res = 0, s;
	while (n > 0)
	{
		s = n % 10;
		res = res * 10 + s;
		n = n / 10;
	}
	printf("\nSo dao nguoc n=%d", res);
}

int main()
{
	int n;
	scanf("%d", &n);
	mot(n);
	hai(n);
	ba(n);
	bon(n);
	return 0;
}
