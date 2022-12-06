#include <iostream>
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};
void Input(Tree *&root, int &n);
void Output(Tree *root, int n);
void Insert(Tree *&root, int x);
void Sort(Tree *&root, int x);
void Search(Tree *root, int x);
void Fetch(Tree *root);
void Menu(Tree *&root, int &n);
void Balance(Tree *&root, int n);
void BearthFirstSearch(Tree *root);
void DepthFirstSearch(Tree *root);

int main(int argc, char const *argv[])
{
    int n = 10;
    Tree *root = NULL;
    Menu(root, n);
    return 0;
}
void Input(Tree *&root, int &n)
{
    cout << "Enter number of elements of tree: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "a[" << i << "] = ";
        cin >> x;
        Insert(root, x);
    }
}
void Output(Tree *root, int n)
{
    cout << "tree: " << endl;
    Tree *p = root;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Insert(Tree *&root, int x)
{
    Tree *p = new Tree;
    p->data = x;
    p->next = head;
    head = p;
    if (tail == NULL)
    {
        tail = p;
    }
}
void Search(Tree *root, int x)
{
    Tree *p = root;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Found " << x << " in tree" << endl;
            return;
        }
        p = p->next;
    }
    cout << "Not found " << x << " in tree" << endl;
}
void Fetch(Tree *root)
{
    Tree *p = root;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Sort(Tree *&root, int x)
{
    Tree *p = new Tree;
    p->data = x;
    p->next = NULL;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        Tree *q = root;
        while (q->next != NULL && q->next->data < x)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}
void Balance(Tree *&root, int n)
{
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    Tree *p = root;
    int i = 0;
    while (p != NULL)
    {
        a[i] = p->data;
        p = p->next;
        i++;
    }
    root = NULL;
    for (int i = 0; i < n; i++)
    {
        Insert(root, a[i]);
    }
}
void BearthFirstSearch(Tree *root)
{
    Tree *p = root;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void DepthFirstSearch(Tree *root)
{
    Tree *p = root;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Menu(Tree *&root, int &n)
{
    int choice;
    do
    {
        cout << "1. Input tree" << endl;
        cout << "2. Output tree" << endl;
        cout << "3. Search tree" << endl;
        cout << "4. Sort tree" << endl;
        cout << "5. Balance tree" << endl;
        cout << "6. Bearth first search" << endl;
        cout << "7. Depth first search" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(root, n);
            break;
        case 2:
            Output(root, n);
            break;
        case 3:
            int x;
            cout << "Enter x: ";
            cin >> x;
            Search(root, x);
            break;
        case 4:
            Sort(root, n);
            break;
        case 5:
            Balance(root, n);
            break;
        case 6:
            BearthFirstSearch(root);
            break;
        case 7:
            DepthFirstSearch(root);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);
}