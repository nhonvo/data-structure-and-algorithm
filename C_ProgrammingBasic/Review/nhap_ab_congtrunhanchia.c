#include <stdio.h>

int main()
{
	float s, a, b;
	char ch;
	printf("Enter a ch b:");
	scanf("%f%c%f", &a, &ch, &b);

	if (ch == '+')
	{
		s = a + b;
	}
	if (ch == '-')
	{
		s = a - b;
	}
	if (ch == '*')
	{
		s = a * b;
	}
	if (ch == '/')
	{
		s = a / b;
	}
	printf("=%f", s);
	return 0;
}
