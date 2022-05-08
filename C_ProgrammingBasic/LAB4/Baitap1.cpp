#include <stdio.h>
#include <stdbool.h>

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
	int i, cnt = 0, s = 0;
	for (i = 2; i <= n; i++)
	{
		if (ktnt(i))
		{
			printf("   %d  ", i);
			cnt++;
			s += i;
		}
	}
	float u = s / cnt;
	printf("So luong nguyen to:%d", cnt);
	printf("Tong nguyen to:%d", s);
	printf("trung binh cong so nguyen to:%f", u);
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

	xuatnt(n);
	return 0;
}
