#include <stdio.h>
#include <math.h>

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a * b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

typedef struct
{
	int tuso, mauso;
} PS;

PS rutgon(PS a)
{
	PS c;
	c.tuso = a.tuso / UCLN(a.tuso, a.mauso);
	c.mauso = a.mauso / UCLN(a.tuso, a.mauso);
	return c;
}
void print(PS a)
{
	printf("%d/%d", a.tuso, a.mauso);
}
int main()
{
	PS a, b, c;
	printf("Nhap phan so:");
	scanf("%d%d", &a.tuso, &a.mauso);
	a = rutgon(a);
	print(a);
}
