#include <iostream>
using namespace std;

void Input(int n, int a[]);
void Output(int n, int a[]);
void Fibonacci(int n, int a[]);
void Hanoi(int n, char a, char b, char c);
void Menu(int n, int a[]);

int main(int argc, char const *argv[])
{
    return 0;
}
void Input(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void Output(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
}
void Fibonacci(int n, int a[])
{
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    Output(n, a);
}
void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
    }
    else
    {
        Hanoi(n - 1, a, c, b);
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
        Hanoi(n - 1, b, a, c);
    }
}
void Menu(int n, int a[])
{
    int choice;
    do
    {
        cout << "1. Input" << endl;
        cout << "2. Output" << endl;
        cout << "3. Fibonacci" << endl;
        cout << "4. Hanoi" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(n, a);
            break;
        case 2:
            Output(n, a);
            break;
        case 3:
            Fibonacci(n, a);
            break;
        case 4:
            Hanoi(n, 'A', 'B', 'C');
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