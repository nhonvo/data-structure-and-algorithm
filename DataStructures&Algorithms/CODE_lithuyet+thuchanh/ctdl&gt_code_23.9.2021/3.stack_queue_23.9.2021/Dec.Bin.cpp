#include<stdio.h>


struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
 
struct stack
{
    NODE *pTop; 
};
typedef struct stack STACK;


void KhoiTaoStack(STACK &s)
{
    s.pTop = NULL;
}
 
NODE *KhoiTaoNode(int x)
{
    NODE *p = new NODE();
    if (p == NULL)
    {
        return NULL;
    }
    p->data = x; 
    p->pNext = NULL;
    return p;
}
 
bool IsEmpty(STACK s)
{
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}
 
bool Push(STACK &s, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }
 
    if (IsEmpty(s) == false)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop; 
        s.pTop = p;
    }
    return true;
}
 
bool Pop(STACK &s, int &x) 
{
    if (IsEmpty(s) == false)
	{
        return false; 
    }
    NODE *p = s.pTop; 
    s.pTop = s.pTop->pNext;
    x = p->data; 
    return true; 
}

 
void Chuyen_Co_So(STACK &s, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % 2;
        NODE *p = KhoiTaoNode(x); 
        Push(s, p);
        hethapphan /= 2;
    }
}

void XuatStack(STACK &s)
{
    while (IsEmpty(s) == true)
    {
        int x;
        Pop(s, x);
        if (x < 10){
            printf("%d",x);
        }
    }
}


int main()
{
    STACK s;
    KhoiTaoStack(s);
     
    int hethapphan,cosocandoi;
    scanf("%d",& hethapphan);
  
    Chuyen_Co_So(s, hethapphan);
    XuatStack(s);
}



