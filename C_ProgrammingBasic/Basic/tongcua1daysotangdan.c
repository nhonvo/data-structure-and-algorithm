#include <stdio.h>

int tong(int s)
{
	int n, i;
	s = 0;
	i = 1;
	printf("nhap n= ");
	scanf("%d", &n);

	while (i <= n)
	{
		s += i;
		i++;
	}
	printf("tong of %d so s= %d", n, s);
}
int main()
{
	int s;
	tong(s);
	return 0;
}
