#include<stdio.h>

typedef struct Node
{
	int data;
	Node* next;
}node;

typedef struct Queue
{
	node* phead;
	node* ptail;
}queue;
//----------------------------------------------------------------
void Init(queue &q)
{
	q.phead=q.ptail=NULL;
}
//----------------------------------------------------------------
int IsEmpty(queue q)
{
	return q.phead==NULL;
}
//----------------------------------------------------------------
node* createnode(int x)
{
	node* p=new node;
	p->data = x;
	p->next = NULL;
}
//----------------------------------------------------------------
void Push(queue &q, node* p)
{
	if(IsEmpty(q))
	{
		q.phead=q.ptail=p;
	}
	else
	{
		q.ptail->next=p;
		q.ptail=p;
	}
}
//----------------------------------------------------------------
int Pop(queue &q)
{
	node* p=q.phead;
	if(IsEmpty(q))
	{
		return 0;
	}
	else
	{
		if(q.phead==q.ptail)
		{
			Init(q);
		}
		else
		{
			int x = q.phead->data;
			q.phead=q.phead->next;//chi chuyen head chu ko head->next=NULL
		}
	}
	delete p;
}
//----------------------------------------------------------------
void InputData(queue &q)
{
	int n, x;
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap gia tri node thu %d: ", i);
		scanf("%d", &x);
		node* p= createnode(x);
		Push(q,p);
	}
}
//----------------------------------------------------------------
void show(queue q)
{
	node* p=q.phead;
	printf("\nXuat:\n");
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}
//----------------------------------------------------------------
int main()
{
	queue q;
	Init(q);
	InputData(q);
	show(q);
	printf("\nBo bot phan tu dau: ");
	Pop(q);
	show(q);
	return 0;
}
