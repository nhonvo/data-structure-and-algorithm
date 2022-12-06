#include <iostream>
using namespace std;
void ReadFile(char *path);
void WriteFile(char *path);
void ReadArrFile(char *path);
void WriteArrFile(char *path);

void Menu(char *path);
int main(int argc, char const *argv[])
{
    char path[100];
    cout << "Enter path: ";
    cin.getline(path, 100);
    Menu(path);
    return 0;
}
void ReadFile(char *path)
{
    FILE *f;
    f = fopen(path, "r");
    if (f == NULL)
    {
        cout << "Can't open file" << endl;
        return;
    }
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        cout << c;
    }
    fclose(f);
}
void WriteFile(char *path)
{
    FILE *f;
    f = fopen(path, "w");
    if (f == NULL)
    {
        cout << "Can't open file" << endl;
        return;
    }
    char c;
    while ((c = getchar()) != EOF)
    {
        fputc(c, f);
    }
    fclose(f);
}
void ReadArrFile(char *path)
{
    FILE *f = fopen(path, "rb");
    if (f == NULL)
    {
        cout << "Can not open file!" << endl;
        return;
    }
    int n;
    fread(&n, sizeof(int), 1, f);
    int *a = new int[n];
    fread(a, sizeof(int), n, f);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    fclose(f);
    delete[] a;
}
void WriteArrFile(char *path)
{
    FILE *f = fopen(path, "wb");
    if (f == NULL)
    {
        cout << "Can not open file!" << endl;
        return;
    }
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    fwrite(&n, sizeof(int), 1, f);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    fwrite(a, sizeof(int), n, f);
    fclose(f);
    delete[] a;
}
void Menu(char *path)
{
    int choice;
    do
    {
        cout << "1. Read file" << endl;
        cout << "2. Write file" << endl;
        cout << "3. Read array file" << endl;
        cout << "4. Write array file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            ReadFile(path);
            break;
        case 2:
            WriteFile(path);
            break;
        case 3:
            ReadArrFile(path);
            break;
        case 4:
            WriteArrFile(path);
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);
}
