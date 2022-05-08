#include <stdio.h>
#define max 100

int main()
{
	char name[max], address[max];
	scanf("%s%s", &name, &address);
	printf("name:%s\naddress:%s", name, address);


	char str[max], k;
	scanf("%d%s", &k, &str);
	printf("%s", str);
	printf("\n%c", str[k - 1]);

	return 0;
}
