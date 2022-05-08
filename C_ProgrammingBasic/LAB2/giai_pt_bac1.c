#include <stdio.h>

int main()
{
	float a, b, x;
	printf("------Giai pt bac nhat ax+b=0------\n");
	printf("nhap a: ");
	scanf("%f", &a);
	printf("nhap b: ");
	scanf("%f", &b);
	if (a == 0)
	{
		if (b == 0)
		{
			printf("Pt vo so nghiem.");
		}
		else
		{
			printf("Pt vo nghiem.");
		}
	}
	else
	{
		x = -b / a;
		printf("Nghiem x=%f", x);
	}
	return 0;
}
