#include <iostream>
using namespace std;
Struct Queue
{
    int data;
    Queue *next;
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
void Enqueue(Queue *&head, Queue *&tail, Employee x);
void Dequeue(Queue *&head, Queue *&tail);
void Output(Queue *head);
void Menu(Queue *&head, Queue *&tail);
int main(int argc, char const *argv[])
{
    Queue *head = NULL;
    Queue *tail = NULL;
    Menu(head, tail);
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
void Enqueue(Queue *&head, Queue *&tail, Employee x)
{
    Queue *p = new Queue;
    p->data = x;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}
void Dequeue(Queue *&head, Queue *&tail)
{
    if (head == NULL)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        Queue *p = head;
        head = head->next;
        delete p;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
}
void Output(Queue *head)
{
    if (head == NULL)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        Queue *p = head;
        while (p != NULL)
        {
            Output(p->data);
            p = p->next;
        }
    }
}
void Menu(Queue *&head, Queue *&tail)
{
    int choice;
    Employee x;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Output" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(x);
            Enqueue(head, tail, x);
            break;
        case 2:
            Dequeue(head, tail);
            break;
        case 3:
            Output(head);
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);
}
