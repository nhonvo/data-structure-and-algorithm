#include <stdio.h>
#include <conio.h>

int main()
{
	int h;
	printf ("Nhap vao chieu cao tam giac: ");
	scanf ("%d", &h);
	for (int i = 0; i < h; i++)
   {
      for (int j = 0; j <= i; j++)
      {
         if (i == 1 || i == h  || j == i)
            printf(" * ");
         else
            printf("  ");
      }
      printf("\n\n");
   }
	return 0;
}
