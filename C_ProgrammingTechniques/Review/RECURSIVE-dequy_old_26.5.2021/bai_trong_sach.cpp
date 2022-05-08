#include <stdio.h>
#include <conio.h>
void nhap(int &n, int a[])
{
	do
	{
		printf("Nhap n:");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
		{
			printf("ERROR\n");
		}
	} while (n <= 0 || n > 100);

	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &a[i]);
	}
}
void xuat(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}
int tong(int n, int a[])
{ //tong dê quy
	if (n == 1)
	{
		return a[0];
	}
	return a[n - 1] + tong(n - 1, a);
}
int tongchan(int n, int a[])
{ //tong chan dêquy
	if (n == 1)
	{
		if (a[n - 1] % 2 == 0)
		{
			return a[0];
		}
		else
		{
			return 0;
		}
	}
	if (a[n - 1] % 2 == 0)
	{
		return a[n - 1] + tongchan(n - 1, a);
	}
	else
		return 0 + tongchan(n - 1, a);
}
int tongle(int n, int a[])
{ //tong le dê quy
	if (n == 1)
	{
		if (a[n - 1] % 2 != 0)
		{
			return a[0];
		}
		else
		{
			return 0;
		}
	}
	if (a[n - 1] % 2 != 0)
	{
		return a[n - 1] + tongle(n - 1, a);
	}
	else
		return 0 + tongle(n - 1, a);
}
static int i = 0;
int timchandau(int n, int a[])
{ //chan dau tien
	i++;
	if (n == 1)
	{
		if (a[n - 1] % 2 == 0)
		{
			return a[0];
		}
		else
		{
			return 0;
		}
	}
	if (a[i] % 2 == 0)
	{
		return a[i];
	}
	else
	{
		return timchandau(i, a);
	}
}

int gtln(int n, int a[])
{
	if (n == 1)
	{
		return a[0];
	}
	if (gtln(n - 1, a) > a[n - 1])
	{
		return gtln(n - 1, a);
	}
	else
	{
		return a[n - 1];
	}
}
int gtnn(int n, int a[])
{
	if (n == 1)
	{
		return a[0];
	}
	if (gtln(n - 1, a) < a[n - 1])
	{
		return gtln(n - 1, a);
	}
	else
	{
		return a[n - 1];
	}
}

int demchan(int n, int a[])
{ //dem chan dê quy
	if (n == 1)
	{
		if (a[n - 1] % 2 == 0)
		{
			return a[0];
		}
		else
		{
			return 0;
		}
	}
	if (a[n - 1] % 2 == 0)
	{
		return 1 + demchan(n - 1, a);
	}
	else
		return demchan(n - 1, a);
}

bool ktr(int n)
{
	i++;
	int dem = 0;
	if (n % i == 0)
	{
		dem++;
	}
	if (dem == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int timnt(int n, int a[])
{
	if (n == 1 && n == 2)
	{
		return a[0];
	}
	if (ktr(n))
	{
		return timnt(n - 1, a);
	}
}
int main()
{
	int n, a[101];
	nhap(n, a);
	int s = timnt(n, a);
	printf("%d", s);
}
