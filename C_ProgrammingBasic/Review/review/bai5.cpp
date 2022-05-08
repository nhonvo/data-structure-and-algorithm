#include <stdio.h>

void nhap(int &n, int &m)
{
	scanf("%d%d", &n, &m);
}
int ucln(int n, int m)
{
	while (n != m)
	{
		if (n > m)
		{
			n -= m;
		}
		else
		{
			m -= n;
		}
	}
	return n;
}
int bcnn(int n, int m)
{
	int s;
	for (int i = 1; i < (m * n); i++)
	{
		if (i % n == 0 && i % m == 0)
		{
			s = i;
			break;
		}
	}
	return s;
}
void xuat(int n)
{
	printf("\n%d", n);
}
int main()
{
	int n, m;
	nhap(n, m);
	/*int s=ucln(n,m);
		xuat(s);*/
	int o = bcnn(n, m);
	xuat(o);
}
