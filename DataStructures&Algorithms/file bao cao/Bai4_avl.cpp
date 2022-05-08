// Phạm Đức Tài 
// 2080601324 
// 08/03/2002 
// taidotcpp@gmail.com

#include <stdio.h>

struct Node
{
    int data, h;
    Node *l, *r;
};
void Init(Node *&x)
{
    x = NULL;
}
int max(int x, int y)
{
    return x > y ? x : y;
}
int IsEmpty(Node *x)
{
    return x == NULL;
}
Node *CreateNode(int data)
{
    Node *q = new Node;
    q->data = data;
    q->h = 1;
    Init(q->l);
    Init(q->r);
    return q;
}
int GetHight(Node *x)
{
    if (IsEmpty(x))
        return 0;
    return x->h;
}
int GetBalance(Node *x)
{
    return GetHight(x->l) - GetHight(x->r);
}

void LeftRotate(Node *&x)
{
    Node *y = x->r;
    Node *p = y->l;
    x->r = p;
    y->l = x;
    x->h = max(GetHight(x->l), GetHight(x->r)) + 1;
    y->h = max(GetHight(y->l), GetHight(y->r)) + 1;
    x = y;
}

void RightRotate(Node *&x)
{
    Node *y = x->l;
    Node *p = y->r;
    x->l = p;
    y->r = x;
    x->h = max(GetHight(x->l), GetHight(x->r)) + 1;
    y->h = max(GetHight(y->l), GetHight(y->r)) + 1;
    x = y;
}
void Insert(Node *&x, int data)
{
    if (IsEmpty(x))
    {
        x = CreateNode(data);
        return;
    }
    if (data < x->data)
        Insert(x->l, data);
    else if (data > x->data)
        Insert(x->r, data);
    else
        return;
    int B = GetBalance(x);
    if (B > 1 && data < x->l->data)
    {
        RightRotate(x);
        return;
    }
    if (B > 1 && data > x->l->data)
    {
        LeftRotate(x->l);
        RightRotate(x);
        return;
    }
    if (B < -1 && data > x->r->data)
    {
        LeftRotate(x);
        return;
    }
    if (B < -1 && data < x->r->data)
    {
        RightRotate(x->r);
        LeftRotate(x);
        return;
    }
    x->h = max(GetHight(x->l), GetHight(x->r)) + 1;
}
void NLR(Node *x)
{
    if (IsEmpty(x))
        return;
    printf("%d ", x->data);
    NLR(x->l);
    NLR(x->r);
}
int main()
{
    Node *root;
    Init(root);
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &data);
        Insert(root, data);
        NLR(root);
        printf("\n");
    }
    printf("\nKet qua cuoi cung: ");
    NLR(root);
    return 0;
}
