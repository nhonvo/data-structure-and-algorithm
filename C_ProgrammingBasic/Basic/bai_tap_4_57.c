#include <stdio.h>
//#define pi 3.14

int main()
{
	float s, r, p;

	printf("Enter the radius r=");
	scanf("%f", &r);

	p = 2 * 3.14 * r;

	printf("Perimeter of the circle= %f\n", p);

	s = 3.14 * r * r;
	printf("Area of the the circle=%f", s);

	return 0;
}
