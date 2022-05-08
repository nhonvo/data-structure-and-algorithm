#include <stdio.h>
#include <string.h>

int main()
{
	int k, i;
	char str[100];
	int index = -1;
	char s;
	scanf("%s", &str);
	scanf("%s", &s);
	for (i = 1; i <= strlen(str); i++)
	{
		if (str[i] == s)
		{
			index = 1;
			break;
		}
	}
	printf("%d", index);

	return 0;
}
