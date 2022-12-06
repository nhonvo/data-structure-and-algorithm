#include <iostream>
using namespace std;
struct Queue
{
    int data;
    Queue *next;
};
void Input(Queue *&head, Queue *&tail, int &n);
void Output(Queue *head, Queue *tail, int n);
void Enqueue(Queue *&head, Queue *&tail, int x);
void Dequeue(Queue *&head, Queue *&tail);
void Search(Queue *head, Queue *tail, int x);
void Fetch(Queue *head, Queue *tail);
void Menu(Queue *&head, Queue *&tail, int &n);

int main(int argc, char const *argv[])
{

    int n = 10;
    Queue *head = NULL;
    Queue *tail = NULL;
    Menu(head, tail, n);
    return 0;
}
void Input(Queue *&head, Queue *&tail, int &n)
{
    cout << "Enter number of elements of queue: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "a[" << i << "] = ";
        cin >> x;
        Enqueue(head, tail, x);
    }
}
void Output(Queue *head, Queue *tail, int n)
{
    cout << "queue: " << endl;
    Queue *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Enqueue(Queue *&head, Queue *&tail, int x)
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
        cout << "Queue is empty" << endl;
    }
    else
    {
        Queue *p = head;
        head = head->next;
        delete p;
    }
}
void Search(Queue *head, Queue *tail, int x)
{
    Queue *p = head;
    int i = 0;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Found " << x << " at position " << i << endl;
            return;
        }
        p = p->next;
        i++;
    }
    cout << "Not found " << x << endl;
}
void Fetch(Queue *head, Queue *tail)
{
    if (head == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "First element of queue is " << head->data << endl;
    }
}
void Menu(Queue *&head, Queue *&tail, int &n)
{
    int choice;
    do
    {
        cout << "1. Input queue" << endl;
        cout << "2. Output queue" << endl;
        cout << "3. Enqueue" << endl;
        cout << "4. Dequeue" << endl;
        cout << "5. Search" << endl;
        cout << "6. Fetch" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(head, tail, n);
            break;
        case 2:
            Output(head, tail, n);
            break;
        case 3:
            int x;
            cout << "Enter element to enqueue: ";
            cin >> x;
            Enqueue(head, tail, x);
            break;
        case 4:
            Dequeue(head, tail);
            break;
        case 5:
            int y;
            cout << "Enter element to search: ";
            cin >> y;
            Search(head, tail, y);
            break;
        case 6:
            Fetch(head, tail);
            break;
        case 7:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 7);
}
