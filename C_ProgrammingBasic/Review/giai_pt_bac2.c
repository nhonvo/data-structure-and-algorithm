#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	printf("------Giai pt bac hai Ax^2+Bx+C=0------\n");
	printf("nhap a: ");
	scanf("%f", &a);
	printf("nhap b: ");
	scanf("%f", &b);
	printf("nhap c: ");
	scanf("%f", &c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("Pt vo so nghiem");
			}
			else
			{
				printf("Pt vo nghiem");
			}
		}
		else
		{
			printf("phuong trinh co nghiem x=-c/b=%f", -c / b);
		}
	}
	else
	{
		float x1, x2, Delta;
		Delta = b * b - 4 * a * c;
		printf("Delta=%f", Delta);
		if (Delta < 0)
		{
			printf("\nPt vo nghiem");
		}
		if (Delta == 0)
		{
			printf("\nphuong trinh co nghiem kep x=%f", -b / 2 * a);
		}
		else
		{
			if (Delta > 0)
			{
				x1 = (-b + sqrt(Delta)) / (2 * a);
				x2 = (-b - sqrt(Delta)) / (2 * a);
				printf("\nPhuong trinh co 2 nghiem: x1= %f,x2= %f", x1, x2);
			}
		}
	}
	return 0;
}
