#include <stdio.h>

int calendar(int day, int month, int year)
{
	if (year > 0)
	{

		if (month >= 1 && month <= 12)
		{

			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day <= 31 && day > 0)
				{
					printf("the date exist");
				}
				else
				{
					printf("ERROR");
				}
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day <= 30 && day > 0)
				{
					printf("the date exist");
				}
				else
				{
					printf("ERROR");
				}
			}
			else
			{
				if (year % 4 == 0)
				{
					if (day <= 29 && day > 0)
					{
						printf("the date exist");
					}
					else
					{
						printf("ERROR");
					}
				}
				else
				{
					if (day <= 28 && day > 0)
					{
						printf("the date exist");
					}
					else
					{
						printf("ERROR");
					}
				}
			}
		}
		else
		{
			printf("ERROR");
		}
	}
	else
	{
		printf("ERROR");
	}
}

int main()
{
	int day, month, year;
	printf("Enter day:");
	scanf("%d", &day);
	printf("Enter month:");
	scanf("%d", &month);
	printf("Enter year:");
	scanf("%d", &year);
	calendar(day, month, year);
	return 0;
}
