#include <stdio.h>

int main()
{
    char c;
    char s[100];
    scanf("%s", &c);
    scanf("%s", s);
    int cnt = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == c)
        {
            cnt++;
        }
    }
    printf("%d", count);
    return 0;
}
