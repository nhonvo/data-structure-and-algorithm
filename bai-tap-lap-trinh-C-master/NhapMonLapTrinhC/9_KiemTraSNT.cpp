#include <stdio.h>
#include <conio.h>
int main()
{
	int n;
	printf ("Nhap vao mot so: ");
	scanf ("%d", &n);
	if (n < 2)
	printf (" So %d: khong phai la so nguyen to", n);
	else 
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				printf (" So %d: khong la so nguyen to", n);
				break;
			}
		}
			printf (" So %d: la so nguyen to", n);
	}
	return 0;

}
		

