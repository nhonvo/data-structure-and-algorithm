#include <stdio.h>
#include <conio.h>

int main()
{
	float n;
	printf("Enter distance n:");
	scanf("%f", &n);
	printf("\n          Distance is %f km\n", n);
	if (n <= 1)
	{
		int s = 5000;
		printf("              fee:%d vnd", s);
	}
	else if (n > 1 && n <= 30)
	{
		int t;
		int tien;
		int duong = n * 1000;
		if (duong % 200 == 0)
		{
			t = (duong - 1000) / 200;
		}
		else
		{
			t = (duong - 1000) / 200 + 1;
		}

		tien = t * 1000 + 5000;
		printf("%d", tien);
	}
	else if (n > 30)
	{
		int duong = n;
		int tien = (duong - 30) * 3000 + 150000;
		printf("     Tien =%d   ", tien);
	}
}
