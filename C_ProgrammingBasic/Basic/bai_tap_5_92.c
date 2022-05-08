#include <stdio.h>

int main()
{
	int i;
	// 1	printf("Enter even number i:");
	//	scanf("%d",i)
	for (i = 2; i < 10; i = i + 2)
	{
		printf("_%d", i);
	}
	return 0;
}
