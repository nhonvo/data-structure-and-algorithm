#include <stdio.h>
#include <conio.h>

int calendar(int month, int year)
{
	if (month > 1 || month < 12)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			printf("day:31");
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			printf("day:30");
		}
		else if (month == 2)
		{
			if (year % 4 == 0)
			{
				printf("Day:29");
			}
			else
			{
				printf("Day:28");
			}
		}
		else
		{
			printf("Not have this month");
		}
	} // ket if bu
} // ket ham
int main()
{
	int month, year;
	printf("Enter month:");
	scanf("%d%d", &month);
	printf("Enter year:");
	scanf("%d%d", &year);
	calendar(month, year);
	return 0;
}
