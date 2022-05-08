int tong(int n)
{
	int s, u;
	while (n > 0)
	{
		s = n % 10;
		n = n / 10;
		u += s;
	}
	return u;
}

int main()
{
	int n;
	do
	{
		printf("Nhap n=");
		scanf("%d", &n);
		if (n <= 1)
		{
			printf("Nhap sai nhap lai.");
		}
	} while (n <= 1);
	printf("\nTong so n=%d", tong(n));
}
