#include <iostream>
using namespace std;

struct Employee
{
    int id;
    char name[30];
    char address[30];
    char phone[15];
    char email[30];
    char position[30];
    int salary;
    int age;
};
void Input(Employee &e);
void Output(Employee e);
void Count(Employee e[], int n);
void Search(Employee e[], int n);
void Sort(Employee e[], int n);
void Delete(Employee e[], int &n);
void Insert(Employee e[], int &n);
void Menu(Employee e[], int &n);
int main(int argc, char const *argv[])
{
    int n = 10;
    Employee e[100];
    Menu(e, n);
    return 0;
}
void Input(Employee &e)
{
    cout << "Enter id: ";
    cin >> e.id;
    cin.ignore();
    cout << "Enter name: ";
    cin.getline(e.name, 30);
    cout << "Enter address: ";
    cin.getline(e.address, 30);
    cout << "Enter phone: ";
    cin.getline(e.phone, 15);
    cout << "Enter email: ";
    cin.getline(e.email, 30);
    cout << "Enter position: ";
    cin.getline(e.position, 30);
    cout << "Enter salary: ";
    cin >> e.salary;
    cout << "Enter age: ";
    cin >> e.age;
}
void Output(Employee e)
{
    cout << "ID: " << e.id << endl;
    cout << "Name: " << e.name << endl;
    cout << "Address: " << e.address << endl;
    cout << "Phone: " << e.phone << endl;
    cout << "Email: " << e.email << endl;
    cout << "Position: " << e.position << endl;
    cout << "Salary: " << e.salary << endl;
    cout << "Age: " << e.age << endl;
}
void Count(Employee e[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i].salary > 1000000)
        {
            count++;
        }
    }
    cout << "Number of employees with salary > 1000000: " << count << endl;
}
void Search(Employee e[], int n)
{
    int id;
    cout << "Enter id: ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            Output(e[i]);
            return;
        }
    }
    cout << "Not found" << endl;
}
void Sort(Employee e[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (e[i].salary > e[j].salary)
            {
                Employee temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}
void Delete(Employee e[], int &n)
{
    int id;
    cout << "Enter id: ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            for (int j = i; j < n - 1; j++)
            {
                e[j] = e[j + 1];
            }
            n--;
            return;
        }
    }
    cout << "Not found" << endl;
}
void Insert(Employee e[], int &n)
{
    int id;
    cout << "Enter id: ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            cout << "ID already exists" << endl;
            return;
        }
    }
    e[n].id = id;
    cin.ignore();
    cout << "Enter name: ";
    cin.getline(e[n].name, 30);
    cout << "Enter address: ";
    cin.getline(e[n].address, 30);
    cout << "Enter phone: ";
    cin.getline(e[n].phone, 15);
    cout << "Enter email: ";
    cin.getline(e[n].email, 30);
    cout << "Enter position: ";
    cin.getline(e[n].position, 30);
    cout << "Enter salary: ";
    cin >> e[n].salary;
    cout << "Enter age: ";
    cin >> e[n].age;
    n++;
}
void Menu(Employee e[], int &n)
{
    int choice;
    do
    {
        cout << "1. Input" << endl;
        cout << "2. Output" << endl;
        cout << "3. Count" << endl;
        cout << "4. Search" << endl;
        cout << "5. Sort" << endl;
        cout << "6. Delete" << endl;
        cout << "7. Insert" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                Input(e[i]);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                Output(e[i]);
            }
            break;
        case 3:
            Count(e, n);
            break;
        case 4:
            Search(e, n);
            break;
        case 5:
            Sort(e, n);
            break;
        case 6:
            Delete(e, n);
            break;
        case 7:
            Insert(e, n);
            break;
        case 8:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 8);
}
