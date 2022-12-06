#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand (time(NULL));
	for (int i = 0; i < 6; i++)
	{
		int random = 1 + rand()%6;
		printf ("%d  ", random);
	}
}
