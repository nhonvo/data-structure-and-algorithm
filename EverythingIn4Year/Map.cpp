#include <iostream>
#include <map>

using namespace std;

void Input(map<int, int> &m, int &n);
void Output(map<int, int> m, int n);
void Add(map<int, int> &m, int x);
void Delete(map<int, int> &m, int x);
void Search(map<int, int> m, int x);
void Fetch(map<int, int> m);
void Menu(map<int, int> &m, int &n);

int main()
{
    int n = 10;
    map<int, int> m;
    Menu(m, n);
    return 0;
}
void Input(map<int, int> &m, int &n)
{
    cout << "Enter number of elements of map: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "a[" << i << "] = ";
        cin >> x;
        Add(m, x);
    }
}
void Output(map<int, int> m, int n)
{
    cout << "map: " << endl;
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " ";
    }
    cout << endl;
}
void Add(map<int, int> &m, int x)
{
    m.insert(pair<int, int>(x, x));
}
void Delete(map<int, int> &m, int x)
{
    m.erase(x);
}
void Search(map<int, int> m, int x)
{
    map<int, int>::iterator it;
    it = m.find(x);
    if (it != m.end())
    {
        cout << "Found " << x << endl;
    }
    else
    {
        cout << "Not found " << x << endl;
    }
}
void Fetch(map<int, int> m)
{
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " ";
    }
    cout << endl;
}
void Menu(map<int, int> &m, int &n)
{
    int choice;
    do
    {
        cout << "1. Input" << endl;
        cout << "2. Output" << endl;
        cout << "3. Add" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Search" << endl;
        cout << "6. Fetch" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(m, n);
            break;
        case 2:
            Output(m, n);
            break;
        case 3:
            int x;
            cout << "Enter x: ";
            cin >> x;
            Add(m, x);
            break;
        case 4:
            int y;
            cout << "Enter y: ";
            cin >> y;
            Delete(m, y);
            break;
        case 5:
            int z;
            cout << "Enter z: ";
            cin >> z;
            Search(m, z);
            break;
        case 6:
            Fetch(m);
            break;
        case 7:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 7);
}