#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	float p, s;
	printf("Enter slide a,b,c:\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a > 0 && b > 0 && c > 0)
	{
		if (a + b > c && b + c > a && c + a > b)
		{
			p = a + b + c;
			printf("Perimeter of triange is:%f\n", p);

			s = sqrt(p / 2 * (p / 2 - a) * (p / 2 - b) * (p / 2 - c));
			printf("Area of triage is:%f", s);
		}
		else
		{
			printf("khong tao thanh tam giac");
		}
	}
	else
	{
		printf("error.");
	}
	return 0;
}
