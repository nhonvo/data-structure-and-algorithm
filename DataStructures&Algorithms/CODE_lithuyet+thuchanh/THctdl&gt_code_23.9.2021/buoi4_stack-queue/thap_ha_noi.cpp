#include<stdio.h>
#include<iostream>
using namespace std;

struct hn{
	int n;
	int nguon;
	int dich;
	int tam;
};
typedef struct node
{
	hn data;
	node* next;
}stack;

typedef node stack;

void Init(stack* &s)
{
	s = NULL;
}
int IsEmpty(stack* s)
{
	return s == NULL;
}
stack* createnode( hn x)
{
	stack* p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}
void push(stack* &s, hn x)
{
	stack* p =createnode(x);
	if(IsEmpty(s)) s=p ;
	else
	{
	p->next=s;
	s=p;
	}
}
void pop(stack* &s, hn &x)
{
	if(IsEmpty(s)) return ;
	stack* p = s;
	x= p->data;
	s = s->next;
	delete p;
}
void thap_hn(int n, int nguon, int dich, int tam)
{
	stack* s;
	Init(s);
	hn b;
	b.n=n; b.nguon = nguon;b.dich=dich;b.tam=tam;
	push(s,b);
	while(!IsEmpty(s))
	{
//		cout<<x.n<<endl;
		hn x;
		pop(s,x);
//		cout<<x.n<<endl;
		if(x.n==1)
			cout<<"\n "<<x.nguon<<" --> "<<x.dich<<endl;
		else
		{
			hn b1,b2,b3;
			b1.n = x.n-1; b1.nguon=x.nguon; b1.dich =x.tam; b1.tam= x.dich;
			b2.n = 1; b2.nguon = x.nguon; b2.dich = x.dich; b2.tam = x.tam;
			b3.n = x.n-1; b3.nguon = x.tam; b3.dich=x.dich;b3.tam=x.nguon ;
			push(s,b3); push(s,b2); push(s,b1);
		}
	}
}
int main()
{
	int n;
	cout<<"Nhap n: "; cin>>n;
	thap_hn(n,1,2,3);
	return 0;	
}





