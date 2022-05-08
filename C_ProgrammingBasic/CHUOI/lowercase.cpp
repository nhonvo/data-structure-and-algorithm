#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int i;
	scanf("%s", &str);
	for (i = 0; i <= strlen(str); i++)
	{
		if (str[i] > 'A' && str[i] < 'Z')
		{
			str[i] += 32;
		}
	}
	printf("%s", str);
	    for (char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c", c);
    }
    return 0;
}
