#include<stdio.h>

typedef struct node{
	int data;
	node* next;
}stack;

void Init(stack* &s)
{
	s=NULL;
}
int IsEmpty(stack* s)
{
	return s==NULL;
}
void Push(stack* &s, int x)
{
	stack* p= new node;
	p->data =x;
	p->next =s;
	s=p;
}
bool Pop(stack* &head,int x)
{
	stack* p= new node;
	p=head;
	if(IsEmpty(head)) return 0;
	x=head->data;
	head=head->next;
	delete p;
	return true;
}
void InputData(stack* &phead)
{
	int n, x;
	Init(phead);
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap gia tri node thu %d: ", i);
		scanf("%d", &x);
		Push(phead,x);
	}
}
//xuat danh sach--8
void show(stack* phead)
{
	stack* p=phead;
	printf("\nXuat:\n");
	if(p==NULL)
		printf("\nDs rong.");
	while(p !=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}


int main()
{
	stack* head;
	Init(head);
	InputData(head);
	show(head);
	int x;
	if(Pop(head,x))
	{
		printf("\nDa lay ra");
	}
	else
	{
		printf("\nChua lay");
	}
	show(head);
	
	return 0;
}
