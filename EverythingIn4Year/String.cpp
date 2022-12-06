#include <iostream>
using namespace std;

void Input(char *s);
void Output(char *s);
void Reverse(char *s);
void Split(char *s);
void Merge(char *s);
void Fetch(char *s);
void Replace(char *s);
void Delete(char *s);
void Insert(char *s);
void Copy(char *s);
void Compare(char *s);
void Length(char *s);
void Search(char *s);
void Sort(char *s);
void Upper(char *s);
void Lower(char *s);
void Title(char *s);
void Trim(char *s);
void Pad(char *s);

int main(int argc, char const *argv[])
{

    return 0;
}

void Input(char *s)
{
    cout << "Enter a string: ";
    cin.getline(s, 100);
}
void Output(char *s)
{
    cout << "The string is: " << s;
}
void Reverse(char *s)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
voidd Split(char *s)
{
    char *token;
    token = strtok(s, " ");
    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}
void Merge(char *s)
{
    char *token;
    token = strtok(s, " ");
    while (token != NULL)
    {
        cout << token;
        token = strtok(NULL, " ");
    }
}
void Fetch(char *s)
{
    int i, j, k;
    char temp[100];
    cout << "Enter the starting index: ";
    cin >> i;
    cout << "Enter the ending index: ";
    cin >> j;
    for (k = 0; i <= j; i++, k++)
    {
        temp[k] = s[i];
    }
    temp[k] = '\0';
    cout << "The substring is: " << temp;
}

void Replace(char *s)
{
    int i, j, k;
    char temp[100];
    cout << "Enter the starting index: ";
    cin >> i;
    cout << "Enter the ending index: ";
    cin >> j;
    cout << "Enter the string to be replaced: ";
    cin >> temp;
    k = 0;
    for (; k < i; k++)
    {
        s[k] = s[k];
    }
    for (; k <= j; k++)
    {
        s[k] = temp[k - i];
    }
    for (; k < strlen(s); k++)
    {
        s[k] = s[k];
    }
    s[k] = '\0';
}
void Delete(char *s)
{
    int i, j, k;
    char temp[100];
    cout << "Enter the starting index: ";
    cin >> i;
    cout << "Enter the ending index: ";
    cin >> j;
    k = 0;
    for (; k < i; k++)
    {
        s[k] = s[k];
    }
    for (; k <= j; k++)
    {
        s[k] = s[k];
    }
    for (; k < strlen(s); k++)
    {
        s[k] = s[k];
    }
    s[k] = '\0';
}
void Insert(char *s)
{
    int i, j, k;
    char temp[100];
    cout << "Enter the starting index: ";
    cin >> i;
    cout << "Enter the string to be inserted: ";
    cin >> temp;
    k = 0;
    for (; k < i; k++)
    {
        s[k] = s[k];
    }
    for (; k <= j; k++)
    {
        s[k] = temp[k - i];
    }
    for (; k < strlen(s); k++)
    {
        s[k] = s[k];
    }
    s[k] = '\0';
}
void Copy(char *s)
{
    char temp[100];
    strcpy(temp, s);
    cout << "The copied string is: " << temp;
}
void Compare(char *s)
{
    char temp[100];
    cout << "Enter the string to be compared: ";
    cin >> temp;
    if (strcmp(s, temp) == 0)
    {
        cout << "The strings are equal";
    }
    else
    {
        cout << "The strings are not equal";
    }
}
void Length(char *s)
{
    cout << "The length of the string is: " << strlen(s);
}
void Search(char *s)
{
    char temp[100];
    cout << "Enter the string to be searched: ";
    cin >> temp;
    if (strstr(s, temp) == NULL)
    {
        cout << "The string is not found";
    }
    else
    {
        cout << "The string is found";
    }
}
void Sort(char *s)
{
    int i, j;
    char temp;
    for (i = 0; i < strlen(s) - 1; i++)
    {
        for (j = i + 1; j < strlen(s); j++)
        {
            if (s[i] > s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
void Upper(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
}
void Lower(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
}
void Pad(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            s[i] = '_';
        }
    }
}
void Trim(char *s)
{
    int i, j;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '_')
        {
            for (j = i; j < strlen(s); j++)
            {
                s[j] = s[j + 1];
            }
        }
    }
}
void Title(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        if (s[i] == ' ')
        {
            s[i + 1] = s[i + 1] - 32;
        }
    }
}
