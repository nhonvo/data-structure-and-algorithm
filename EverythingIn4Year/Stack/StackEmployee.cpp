#include <iostream>
using namespace std;
Struct Stack
{
    int data;
    Stack *next;
};
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
void Push(Stack *&head, Employee x);
void Pop(Stack *&head);
void Output(Stack *head);
void Menu(Stack *&head);
int main(int argc, char const *argv[])
{
    Stack *head = NULL;
    Menu(head);
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
void Push(Stack *&head, Employee x)
{
    Stack *p = new Stack;
    p->data = x;
    p->next = head;
    head = p;
}
void Pop(Stack *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        Stack *p = head;
        head = head->next;
        delete p;
    }
}
void Output(Stack *head)
{
    Stack *p = head;
    while (p != NULL)
    {
        Output(p->data);
        p = p->next;
    }
}
void Menu(Stack *&head)
{
    int choice;
    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Output" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Employee x;
            Input(x);
            Push(head, x);
            break;
        }
        case 2:
        {
            Pop(head);
            break;
        }
        case 3:
        {
            Output(head);
            break;
        }
        case 4:
        {
            cout << "Goodbye!" << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);
}

