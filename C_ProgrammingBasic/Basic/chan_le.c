#include <stdio.h>

int main()
{
	int a;
	printf("Enter number a:");
	scanf("%d", &a);
	int i;
	i = a % 2;
	if (i != 1)
	{
		printf("a is even number");
	}
	else
	{
		printf("a is odd number");
	}

	return 0;
}
