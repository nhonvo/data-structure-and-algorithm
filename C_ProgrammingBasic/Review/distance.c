#include <stdio.h>
#include <conio.h>

float distance(float n)
{
	float s;
	if (n < 1)
	{
		s = n * 5000;
		printf("fee:%f", s);
	}
	else if (n > 1 || n < 30)
	{
		s = n * 1000 - 1000 + 5000;
		printf("fee:%f", s);
	}
	else if (n > 30)
	{
		s = n * 3000 - 3000 * 30 + 5000 + 1000 * 29;
		printf("fee:%f", s);
	}
}
int main()
{
	float n;
	printf("Enter distance n:");
	scanf("%f", &n);
	distance(n);
	return 0;
}
