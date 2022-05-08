#include <stdio.h>

int main()
{
    int i, j, s;
    printf("\nBang cuu chuong\n");

    for (i = 1; i <= 10; i++)
    {
        printf("Bang nhan %d\n", i);
        for (j = 0; j <= 10; j++)
        {
            s = i * j;
            printf("%d x %d = %d\n", i, j, s);
        }
    }
    return 0;
}
