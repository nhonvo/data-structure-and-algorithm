#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void Input(Node *&head, Node *&tail, int &n);
void Output(Node *head, Node *tail, int &n);
void InsertFirst(Node *&head, Node *&tail, int x);
void InsertLast(Node *&head, Node *&tail, int x);
void Insert(Node *&head, Node *&tail, int x, int k);
void DeleteFirst(Node *&head, Node *&tail);
void DeleteLast(Node *&head, Node *&tail);
void Delete(Node *&head, Node *&tail, int k);
void DeleteAllLast(Node *&head, Node *&tail, int x);
void DeleteAllFirst(Node *&head, Node *&tail, int x);
void DeleteAll(Node *&head, Node *&tail, int x);
void Search(Node *head, Node *tail, int x);
void Reverse(Node *&head, Node *&tail);
void SortIncrease(Node *&head, Node *&tail);
void SortDecrease(Node *&head, Node *&tail);
void Fetch(Node *head, Node *tail, int k);
void FetchFirst(Node *head, Node *tail);
void FetchLast(Node *head, Node *tail);
void IsLinkedList(Node *head, Node *tail);
void IsEmpty(Node *head, Node *tail);
void IsFull(Node *head, Node *tail);
void Length(Node *head, Node *tail);

void Menu(Node *&head, Node *&tail, int &n);

int main()
{
    int n = 10;
    Node *head = NULL;
    Node *tail = NULL;
    Menu(head, tail, n);
    return 0;
}
void Input(Node *&head, Node *&tail, int &n)
{
    cout << "Enter number of elements of linked list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "a[" << i << "] = ";
        cin >> x;
        InsertLast(head, tail, x);
    }
}
void Output(Node *head, Node *tail, int &n)
{
    cout << "linked list: " << endl;
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void InsertFirst(Node *&head, Node *&tail, int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = head;
    head = p;
    if (tail == NULL)
    {
        tail = p;
    }
}
void InsertLast(Node *&head, Node *&tail, int x)
{
    Node *p = new Node;
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
void Insert(Node *&head, Node *&tail, int x, int k)
{
    if (k == 0)
    {
        InsertFirst(head, tail, x);
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < k - 1; i++)
        {
            p = p->next;
        }
        Node *q = new Node;
        q->data = x;
        q->next = p->next;
        p->next = q;
        if (q->next == NULL)
        {
            tail = q;
        }
    }
}
void DeleteFirst(Node *&head, Node *&tail)
{
    if (head != NULL)
    {
        Node *p = head;
        head = head->next;
        delete p;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
}
void DeleteLast(Node *&head, Node *&tail)
{
    if (head != NULL)
    {
        if (head == tail)
        {
            DeleteFirst(head, tail);
        }
        else
        {
            Node *p = head;
            while (p->next != tail)
            {
                p = p->next;
            }
            delete tail;
            tail = p;
            tail->next = NULL;
        }
    }
}
void Delete(Node *&head, Node *&tail, int k)
{
    if (k == 0)
    {
        DeleteFirst(head, tail);
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < k - 1; i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        p->next = q->next;
        delete q;
        if (p->next == NULL)
        {
            tail = p;
        }
    }
}
void DeleteAllLast(Node *&head, Node *&tail, int x)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            DeleteLast(head, tail);
        }
        p = p->next;
    }
}
void DeleteAllFirst(Node *&head, Node *&tail, int x)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            DeleteFirst(head, tail);
        }
        p = p->next;
    }
}
void DeleteAll(Node *&head, Node *&tail, int x)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            Delete(head, tail, p->data);
        }
        p = p->next;
    }
}
void Search(Node *head, Node *tail, int x)
{
    Node *p = head;
    int i = 0;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Element " << x << " is at position " << i << endl;
        }
        p = p->next;
        i++;
    }
}
void Reverse(Node *&head, Node *&tail)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    tail = head;
    head = q;
}
void SortIncrease(Node *&head, Node *&tail)
{
    Node *p = head;
    while (p != NULL)
    {
        Node *q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void SortDecrease(Node *&head, Node *&tail)
{
    Node *p = head;
    while (p != NULL)
    {
        Node *q = p->next;
        while (q != NULL)
        {
            if (p->data < q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void FetchFirst(Node *&head, Node *&tail, int &x)
{
    if (head != NULL)
    {
        x = head->data;
        DeleteFirst(head, tail);
    }
}
void FetchLast(Node *&head, Node *&tail, int &x)
{
    if (head != NULL)
    {
        x = tail->data;
        DeleteLast(head, tail);
    }
}
void IsEmpty(Node *head, Node *tail)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        cout << "Linked list is not empty" << endl;
    }
}
void IsFull(Node *head, Node *tail)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Linked list is full" << endl;
    }
    else
    {
        cout << "Linked list is not full" << endl;
    }
    delete p;
}
voiid IsLinked(Node *head, Node *tail)
{
    if (head != NULL)
    {
        cout << "Linked list is linked" << endl;
    }
    else
    {
        cout << "Linked list is not linked" << endl;
    }
}
void Length(Node *head, Node *tail)
{
    Node *p = head;
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    cout << "Length of linked list is " << i << endl;
}

void Menu(Node *&head, Node *&tail, int &n)
{
    int choice;
    cout << "1. Input linked list" << endl;
    cout << "2. Output linked list" << endl;
    cout << "3. Insert element at first position" << endl;
    cout << "4. Insert element at last position" << endl;
    cout << "5. Insert element at position k" << endl;
    cout << "6. Delete element at first position" << endl;
    cout << "7. Delete element at last position" << endl;
    cout << "8. Delete element at position k" << endl;
    cout << "9. Delete all elements at first position" << endl;
    cout << "10. Delete all elements at last position" << endl;
    cout << "11. Delete all elements at position k" << endl;
    cout << "12. Search element" << endl;
    cout << "13. Reverse linked list" << endl;
    cout << "14. Sort linked list in increasing order" << endl;
    cout << "15. Sort linked list in decreasing order" << endl;
    cout << "16. Exit" << endl;
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
        cout << "Enter element to insert: ";
        cin >> x;
        InsertFirst(head, tail, x);
        break;
    case 4:
        int y;
        cout << "Enter element to insert: ";
        cin >> y;
        InsertLast(head, tail, y);
        break;
    case 5:
        int z, k;
        cout << "Enter element to insert: ";
        cin >> z;
        cout << "Enter position to insert: ";
        cin >> k;
        Insert(head, tail, z, k);
        break;
    case 6:
        DeleteFirst(head, tail);
        break;
    case 7:
        DeleteLast(head, tail);
        break;
    case 8:
        int m;
        cout << "Enter position to delete: ";
        cin >> m;
        Delete(head, tail, m);
        break;
    case 9:
        int a;
        cout << "Enter element to delete: ";
        cin >> a;
        DeleteAllFirst(head, tail, a);
        break;
    case 10:
        int b;
        cout << "Enter element to delete: ";
        cin >> b;
        DeleteAllLast(head, tail, b);
        break;
    case 11:
        int c;
        cout << "Enter element to delete: ";
        cin >> c;
        DeleteAll(head, tail, c);
        break;
    case 12:
        int d;
        cout << "Enter element to search: ";
        cin >> d;
        Search(head, tail, d);
        break;
    case 13:
        Reverse(head, tail);
        break;
    case 14:
        SortIncrease(head, tail);
        break;
    case 15:
        SortDecrease(head, tail);
        break;
    case 16:
        exit(0);
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}
