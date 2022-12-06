#include <stdio.h>
#include <conio.h>



void HoanVi(int &a, int &b)
{
	printf ("vao ham\n");
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int main()
{
	int a, b, temp;
	printf ("Nhap hai so a va b: ");
	scanf ("%d %d", &a, &b);
	
	HoanVi(a, b);
	
	printf ("%d %d", a, b);
	return 0;
	
	
}
