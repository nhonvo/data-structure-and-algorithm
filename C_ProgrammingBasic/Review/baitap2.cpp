#include <stdio.h>
int bacNhat(float a, float b)
{
	scanf("%f%f", &a, &b);
	printf("x=%f", -b / a);
}
int soHT(int n)
{ // tong uoc = no
	int s, i;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			s += i;
		if (s == n)
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
}
int UCLN(int a, int b)
{
	int i, s;
	scanf("%d%d", &a, &b);
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	printf("%d", a);
}
int lietKe(int n)
{ // tong uoc = no
	int s, i;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			s += i;
		if (n == s)
		{
			printf("%d", n);
		}
	}
}
int main()
{
	int n, a, b;
	/*do{
	printf("Nhap n=");
	scanf("%d", &n);
	if(n<=1||n>=100){
	printf("Nhap sai nhap lai.");
	}
	}while(n<=1||n>=100);*/
	UCLN(a, b);
	return 0;
}
