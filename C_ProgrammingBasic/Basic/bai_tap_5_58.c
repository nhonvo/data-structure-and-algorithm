#include <stdio.h>

int main()
{
	float a, b, c;
	printf("enter number a,b,c=");
	scanf("%f%f%f", &a, &b, &c);
	printf("a=%f,b=%f,c=%f\n", a, b, c);
	//	a=max;
	if (b > a)
	{
		if (b > c)
		{
			printf("Max la b");
		}
		else
		{
			printf("max la c");
		}
	}
	else
	{
		if (c > a)
		{
			printf("max la c");
		}
		else
		{
			printf("max la a");
		}
	}
	return 0;
}
