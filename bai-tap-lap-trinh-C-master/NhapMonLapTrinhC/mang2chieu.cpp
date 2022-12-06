#include <stdio.h>
#include <conio.h>

void nhapMang(float a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf ("a[%d][%d] = ",i, j);
			scanf ("%f", &a[i][j]);
		}
	}
}

void xuatMang(float a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf ("%.1f   ", a[i][j]);
		}
		printf ("\n");
	}
}

int main()
{
	float a[100][100];
	int dong, cot;
	printf ("Nhap so dong: ");
	scanf ("%d", &dong);
	printf ("Nhap so cot: ");
	scanf ("%d", &cot);
	nhapMang(a, dong, cot);
	printf ("mang ban vua nhap la:\n");
	xuatMang(a, dong, cot);
}
