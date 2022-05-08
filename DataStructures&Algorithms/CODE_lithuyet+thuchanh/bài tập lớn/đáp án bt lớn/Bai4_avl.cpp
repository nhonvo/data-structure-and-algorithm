#include<stdio.h>

struct Node
{
    int data,h;
    Node *l,*r;
};
void Init(Node *&x)
{
    x=NULL;
}
int max(int x,int y)
{
    return x>y?x:y;
    //xet dk 'x>y' neu dung tra ve x, sai tra ve y.
}
int IsEmpty(Node *x)
{
    return x==NULL;
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
//cay avl: cay có chieu cao 2 cay con lech nhau nhieu nhat 1 dv
int GetHight(Node *x)
{
//	check node null tra ve 0 || chieu cao cay con
    if(IsEmpty(x))
    	return 0;
    return x->h;
}
//check can bang neu nho hon 1 la cay avl
int GetBalance(Node *x)
{
    return GetHight(x->l) - GetHight(x->r);
}
//void swap(Node *&x,Node *&y)
//{
//    Node *p = x;
//    x=y;
//    y=p;
//}
//hai phep quay: trai trai || phai phai
void LeftRotate(Node *&x)
{
//	thuat toan hd: 
    Node *y = x->r;
    Node *p = y->l;
	x->r = p;
    y->l = x;
	x->h = max(GetHight(x->l), GetHight(x->r)) + 1;
	//xet chieu cao
	y->h = max(GetHight(y->l), GetHight(y->r)) + 1;
	x=y;
//    swap(x,y); 
//??????
}

void RightRotate(Node *&x)
{
    Node *y = x->l;
    Node *p = y->r;
    x->l = p;
    y->r = x;
    x->h = max(GetHight(x->l), GetHight(x->r)) + 1;
    y->h = max(GetHight(y->l), GetHight(y->r)) + 1;
    x=y;
//    swap(x,y);
}
//Cac th quay
void Insert(Node *&x,int data)
{
    if(IsEmpty(x))
    {
        x = CreateNode(data);
        return;
    }
    if(data < x->data)
        Insert(x->l,data);
    else if(data > x->data)
        Insert(x->r,data);
    else 
		return;
    int B = GetBalance(x);
        //xac dk cây avl & th node them vào làm cay mat can bang thì xet: tìm node vi pham va 
        //tuy theo truong hop cua cay mà dung giai thuat tuong ung de cân bang. VD: lech 2 node(quay don), lech 1 node(quay kep)
    if(B > 1 && data < x->l->data)
    {
        RightRotate(x);
        return;
    }
    if(B > 1 && data > x->l->data)
    {
        LeftRotate(x->l);
        RightRotate(x);
        return;
    }
    if(B < -1 && data > x->r->data)
    {
        LeftRotate(x);
        return;
    }
    if(B < -1 && data < x->r->data)
    {
        RightRotate(x->r);
        LeftRotate(x);
        return;
    }
    x->h = max(GetHight(x->l),GetHight(x->r))+1;
	//cap nhat chieu cao
}
void NLR(Node *x)
{
    if(IsEmpty(x))
		return;
    printf("%d ",x->data);
    NLR(x->l);
    NLR(x->r);
}
int main()
{
    Node *root;
    Init(root);
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",&data);
        Insert(root,data);
        NLR(root);
        printf("\n");
    }
    NLR(root);
    return 0;
}//69 14 2 28 70 34 63 51 92 81
