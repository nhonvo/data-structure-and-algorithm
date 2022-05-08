#include <stdio.h>
#include <string.h>

int main()
{
	char str[100], s[100];
	int i;
	scanf("%s", &str);
	scanf("%s", &s);
	if (strcmp(str, s) == 0)
	{
		printf("Same");
	}
	else
	{
		printf("do not Same");
	}
}
