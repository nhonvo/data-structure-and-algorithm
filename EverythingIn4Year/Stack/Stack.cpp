#include <iostream>
using namespace std;

struct  Stack
{
    int data;
    Stack *next;
};
void Input(Stack *&head, Stack *&tail, int &n);
void Output(Stack *head, Stack *tail, int n);
void Push(Stack *&head, Stack *&tail, int x);
void Pop(Stack *&head, Stack *&tail);
void Search(Stack *head, Stack *tail, int x);
void Fetch(Stack *head, Stack *tail);

void Menu(Stack *&head, Stack *&tail, int &n);


int main(int argc, char const *argv[])
{
    int n = 10;
    Stack *head = NULL;
    Stack *tail = NULL;
    Menu(head, tail, n);
    return 0;
}
void Input(Stack *&head, Stack *&tail, int &n)
{
    cout << "Enter number of elements of stack: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "a[" << i << "] = ";
        cin >> x;
        Push(head, tail, x);
    }
}
void Output(Stack *head, Stack *tail, int n)
{
    cout << "stack: " << endl;
    Stack *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Push(Stack *&head, Stack *&tail, int x)
{
    Stack *p = new Stack;
    p->data = x;
    p->next = head;
    head = p;
    if (tail == NULL)
    {
        tail = p;
    }
}
void Pop(Stack *&head, Stack *&tail)
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
void Search(Stack *head, Stack *tail, int x)
{
    Stack *p = head;
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
void Fetch(Stack *head, Stack *tail)
{
    if (head == NULL)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "Top of stack is " << head->data << endl;
    }
}

void Menu(Stack *&head, Stack *&tail, int &n)
{
    int choice;
    do
    {
        cout << "1. Input stack" << endl;
        cout << "2. Output stack" << endl;
        cout << "3. Push" << endl;
        cout << "4. Pop" << endl;
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
            cout << "Enter x: ";
            cin >> x;
            Push(head, tail, x);
            break;
        case 4:
            Pop(head, tail);
            break;
        case 5:
            int y;
            cout << "Enter y: ";
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
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);
}