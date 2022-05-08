#include <stdio.h>

int main()
{
	int n;
	printf("nhap vao so nguyen co hai chu so\n ");
	do
	{
		printf("Enter number n:");
		scanf("%d", &n);
		if (n < 0 || n > 100)
			printf("nhap sai nhap lai");
	} while (n < 0 || n > 100);

	/*	switch(n/100) {
			   case 1: printf("Tram"); break;
			  case 2: printf("Hai Tram"); break;
			  case 3: printf("Ba Tram"); break;
			  case 4: printf("Bon Tram"); break;
			  case 5: printf("Nam Tram"); break;
			  case 6: printf("Sau Tram"); break;
			  case 7: printf("Bay Tram"); break;
			  case 8: printf("Tam Tram"); break;
			  case 9: printf("Chin Tram"); break;
			 }*/
	switch (n / 10)
	{
	case 1:
		printf("Muoi");
		break;
	case 2:
		printf("Hai Muoi");
		break;
	case 3:
		printf("Ba Muoi");
		break;
	case 4:
		printf("Bon Muoi");
		break;
	case 5:
		printf("Nam Muoi");
		break;
	case 6:
		printf("Sau Muoi");
		break;
	case 7:
		printf("Bay Muoi");
		break;
	case 8:
		printf("Tam Muoi");
		break;
	case 9:
		printf("Chin Muoi");
		break;
	}
	switch (n % 10)
	{
	case 1:
		printf(" mot");
		break;
	case 2:
		printf(" Hai");
		break;
	case 3:
		printf(" Ba");
		break;
	case 4:
		printf(" Bon");
		break;
	case 5:
		printf(" Nam");
		break;
	case 6:
		printf(" Sau");
		break;
	case 7:
		printf(" Bay");
		break;
	case 8:
		printf(" Tam");
		break;
	case 9:
		printf(" Chin");
		break;
	}
	return 0;
}
