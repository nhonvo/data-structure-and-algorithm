#include <iostream>

using namespace std;

void Input(int n, int a[]);
void Output(int n, int a[]);
void Shift(int n, int a[]);
void Subtract(int n, int a[]);
void Multiply(int n, int a[]);
void Divide(int n, int a[]);
void Modulus(int n, int a[]);
void Power(int n, int a[]);
void Factorial(int n, int a[]);
void Fibonacci(int n, int a[]);
void Prime(int n, int a[]);
void Perfect(int n, int a[]);
void Armstrong(int n, int a[]);
void Palindrome(int n, int a[]);
void Anagram(int n, int a[]);
void Ascending(int n, int a[]);
void Descending(int n, int a[]);
void Odd(int n, int a[]);
void Even(int n, int a[]);
void Positive(int n, int a[]);
void Negative(int n, int a[]);
void Zero(int n, int a[]);
void OddEven(int n, int a[]);
void PositiveNegative(int n, int a[]);
void Menu(int n, int a[]);
int main(int argc, char const *argv[])
{
    int n = 10;
    int a[n];
    Menu(n, a);
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
void Shift(int n, int a[])
{
    int temp = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = temp;
}

void Subtract(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] - 1;
    }
    Output(n, b);
}
void Multiply(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] * 2;
    }
    Output(n, b);
}
void Divide(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] / 2;
    }
    Output(n, b);
}
void Modulus(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] % 2;
    }
    Output(n, b);
}
void Power(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] * a[i];
    }
    Output(n, b);
}
void Factorial(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        for (int j = 1; j <= a[i]; j++)
        {
            temp *= j;
        }
        b[i] = temp;
    }
    Output(n, b);
}
void Fibonacci(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        int temp1 = 1;
        int temp2 = 1;
        for (int j = 1; j <= a[i]; j++)
        {
            temp = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp;
        }
        b[i] = temp;
    }
    Output(n, b);
}
void Prime(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                temp++;
            }
        }
        if (temp == 2)
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    Output(n, b);
}
void Perfect(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 1; j < a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                temp += j;
            }
        }
        if (temp == a[i])
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    Output(n, b);
}
void Armstrong(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int temp1 = 0;
        while (temp != 0)
        {
            temp1 += (temp % 10) * (temp % 10) * (temp % 10);
            temp /= 10;
        }
        if (temp1 == a[i])
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    Output(n, b);
}
void Palindrome(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int temp1 = 0;
        while (temp != 0)
        {
            temp1 = temp1 * 10 + temp % 10;
            temp /= 10;
        }
        if (temp1 == a[i])
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    Output(n, b);
}
void Anagram(int n, int a[])
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int temp1 = 0;
        while (temp != 0)
        {
            temp1 = temp1 * 10 + temp % 10;
            temp /= 10;
        }
        if (temp1 == a[i])
        {
            b[i] = 1;
        }
        else
        {
            b[i] = 0;
        }
    }
    Output(n, b);
}
void Ascending(int n, int a[])
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    Output(n, a);
}
void Descending(int n, int a[])
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    Output(n, a);
}
void Odd(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}
void Even(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}
void Positive(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}
void Negative(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}
void Zero(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}
void OddEven(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}
void PositiveNegative(int n, int a[])
{
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    Output(j, b);
}

void Menu(int n, int a[])
{
    int choice;
    do
    {
        cout << "1. Input" << endl;
        cout << "2. Output" << endl;
        cout << "3. Shift" << endl;
        cout << "4. Subtract" << endl;
        cout << "5. Multiply" << endl;
        cout << "6. Divide" << endl;
        cout << "7. Modulus" << endl;
        cout << "8. Power" << endl;
        cout << "9. Factorial" << endl;
        cout << "10. Fibonacci" << endl;
        cout << "11. Prime" << endl;
        cout << "12. Perfect" << endl;
        cout << "13. Armstrong" << endl;
        cout << "14. Palindrome" << endl;
        cout << "15. Anagram" << endl;
        cout << "16. Ascending" << endl;
        cout << "17. Descending" << endl;
        cout << "18. Odd" << endl;
        cout << "19. Even" << endl;
        cout << "20. Positive" << endl;
        cout << "21. Negative" << endl;
        cout << "22. Zero" << endl;
        cout << "23. OddEven" << endl;
        cout << "24. PositiveNegative" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
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
            Shift(n, a);
            break;
        case 4:
            Subtract(n, a);
            break;
        case 5:
            Multiply(n, a);
            break;
        case 6:
            Divide(n, a);
            break;
        case 7:
            Modulus(n, a);
            break;
        case 8:
            Power(n, a);
            break;
        case 9:
            Factorial(n, a);
            break;
        case 10:
            Fibonacci(n, a);
            break;
        case 11:
            Prime(n, a);
            break;
        case 12:
            Perfect(n, a);
            break;
        case 13:
            Armstrong(n, a);
            break;
        case 14:
            Palindrome(n, a);
            break;
        case 15:
            Anagram(n, a);
            break;
        case 16:
            Ascending(n, a);
            break;
        case 17:
            Descending(n, a);
            break;
        case 18:
            Odd(n, a);
            break;
        case 19:
            Even(n, a);
            break;
        case 20:
            Positive(n, a);
            break;
        case 21:
            Negative(n, a);
            break;
        case 22:
            Zero(n, a);
            break;
        case 23:
            OddEven(n, a);
            break;
        case 24:
            PositiveNegative(n, a);
            break;
        case 0:
            cout << "Thank you for using this program!" << endl;
            break;
        default:
            break;
        }
    } while (choice != 0);
}