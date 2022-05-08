#include <stdio.h>
#include <math.h>

int cauA(int n)
{
	int i;
	printf("\nCau a\n");
	for (i = 1; i <= n; i++)
	{
		printf(" %d ", i);
	}
}
int cauB(int n)
{
	int i;
	printf("\nCau b\n");
	for (i = 2; i <= n; i += 2)
	{
		printf(" %d ", i);
	}
}
int cauC(int n)
{
	int i;
	printf("\nCau c\n");
	for (i = 1; i <= n; i++)
	{
		if (i % 3 != 0 && i % 2 != 0)
		{
			printf(" %d ", i);
		}
	}
}
int cauD1(int n)
{
	int i, s = 0;
	printf("\nCau d1\n");
	for (i = 1; i <= n; i++)
	{
		s += i;
	}
	return s;
}
int cauD2(int n)
{
	int s = 0;
	int u;
	printf("\nCau d3\n");
	for (u = 1; u <= n; u++)
	{
		s = s + (u)*pow((-1), u);
	}
	printf("%d", s);
}
void cauD3(int n)
{
	float s = 0;
	int i = 1;
	printf("\nCau d3\n");

	while (i <= n)
	{
		s = s + (float)i / (i + 1);
		i++;
	}
	printf("%f", s);
}

int cauD4(int n)
{
	printf("\nCau d4\n");
	int s;
	float x;
	printf("nhap X=");
	scanf("%f", &x);
	s = pow(x, n);
	return s;
}
int cauE(int n)
{
	int s = 0, t;
	printf("\nCau e\n");
	while (n != 0)
	{
		t = n % 10;
		n = n / 10;
		s += t;
	}
	return s;
}
int main()
{
	int n, s;
	do
	{
		printf("\nNhap n=");
		scanf("%d", &n);
		if (n < 0)
		{
			printf("Nhap sai.Nhap lai");
		}
	} while (n < 0);

	cauA(n);
	cauB(n);
	cauC(n);
	printf("\n%d", cauD1(n));
	cauD2(n);
	cauD3(n);
	printf("\n%d", cauD4(n));
	printf("%d", cauE(n));
	return 0;
}
