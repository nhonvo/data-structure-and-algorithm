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
Struct Node
{
    Employee data;
    Node *next;
};
void Input(Employee &e);
void Output(Employee e);
void Input(Node *&head, Node *&tail, int &n);
void Output(Node *head, int n);
void Insert(Node *&head, Node *&tail, Employee x, int k);
void Delete(Node *&head, Node *&tail, int k);
void Search(Node *head, int k);
void Menu(Node *&head, Node *&tail, int &n);
int main(int argc, char const *argv[])
{

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
void Input(Node *&head, Node *&tail, int &n)
{
    cout << "Enter number of elements of linked list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Employee x;
        Input(x);
        Node *p = new Node;
        p->data = x;
        p->next = head;
        head = p;
        if (tail == NULL)
        {
            tail = p;
        }
    }
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
void Output(Node *head, int n)
{
    Node *p = head;
    for (int i = 0; i < n; i++)
    {
        Output(p->data);
        p = p->next;
    }
}
void Insert(Node *&head, Node *&tail, Employee x, int k)
{
    Node *p = new Node;
    p->data = x;
    if (k == 0)
    {
        p->next = head;
        head = p;
        if (tail == NULL)
        {
            tail = p;
        }
    }
    else
    {
        Node *q = head;
        for (int i = 0; i < k - 1; i++)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        if (q == tail)
        {
            tail = p;
        }
    }
}
void Delete(Node *&head, Node *&tail, int k)
{
    if (k == 0)
    {
        Node *p = head;
        head = head->next;
        delete p;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
    else
    {
        Node *q = head;
        for (int i = 0; i < k - 1; i++)
        {
            q = q->next;
        }
        Node *p = q->next;
        q->next = p->next;
        delete p;
        if (q->next == NULL)
        {
            tail = q;
        }
    }
}
void Search(Node *head, int k)
{
    Node *p = head;
    for (int i = 0; i < k; i++)
    {
        p = p->next;
    }
    Output(p->data);
}
void Menu(Node *&head, Node *&tail, int &n)
{
    int choice;
    do
    {
        cout << "1. Input linked list" << endl;
        cout << "2. Output linked list" << endl;
        cout << "3. Insert element" << endl;
        cout << "4. Delete element" << endl;
        cout << "5. Search element" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(head, tail, n);
            break;
        case 2:
            Output(head, n);
            break;
        case 3:
            Employee x;
            Input(x);
            int k;
            cout << "Enter position: ";
            cin >> k;
            Insert(head, tail, x, k);
            break;
        case 4:
            cout << "Enter position: ";
            cin >> k;
            Delete(head, tail, k);
            break;
        case 5:
            cout << "Enter position: ";
            cin >> k;
            Search(head, k);
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 6);
}