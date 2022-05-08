#include <stdio.h>
#include <math.h>


int main()
{
	float s = 0, u = 0;
	int n=2;	
	s = sqrt(2);
	for (int i = 2; i <= n; i ++)
	{
		u += sqrt(2+s);
	}
	printf("%f", u);
	return 0;
}


