#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
typedef node stack;

void Init(stack* &s)
{
	s = NULL;
}
int IsEmpty(stack* s)
{
	return s == NULL;
}
node* create_node(int x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}
void push(stack* &head, int x)
{
	stack* p = new node;
	p->data = x;
	p->next = head;
	head = p;
}

int pop(stack* &head, int x)
{
	stack* p = new node;
	p = head;
	if(IsEmpty(head)) return 0;	
	x = p->data;
	head = head->next;
	delete p;
	return x;
}
void Dec_Bin(stack* &s, int m, int k)
{
	while (m!=0)
    {
        k=m%2;
        push(s,k);
        m=m/2;
    }
    cout << "\nSo nhi phan la: ";
}
void Dec_Oct(stack* &s, int m, int k)
{
	while (m!=0)
    {
        k=m%8;
        push(s,k);
        m=m/8;
    }
    cout << "\nSo bat phan la: ";
}
void Dec_Hex(stack* &s, int m, int k)
{
	while (m!=0)
    {
        k=m%16;
        push(s,k);
        m=m/16;
    }
    cout << "\nSo thap luc phan la: ";
}
void xuat(stack* &s)
{
    while(s !=NULL)
	{
		int tmp= s->data;
		if(s->data<10)
			cout<<s->data;
		else
			if (tmp == 10)
				cout<<"A";
			if (tmp == 11)
				cout<<"B";
			if (tmp == 12)
				cout<<"C";
			if (tmp == 13)
				cout<<"D";
			if (tmp == 14)
				cout<<"E";
			if (tmp == 15)
				cout<<"F";
		s=s->next;
	}
}
int main()
{
    stack* s;
    Init(s);
    int m,k;
    cout << "Chuong trinh chuyen doi thap phan sang nhi phan!" << endl;
    do
    {
        cout << "Nhap so thap phan can chuyen: ";
        cin >> m ;
    }
    while (m<=0);
    
	Dec_Bin(s,m,k);
	xuat(s);
	Dec_Oct(s,m,k);
	xuat(s);	
	Dec_Hex(s,m,k);
	xuat(s);	
//	int xx;
//	while(s!=NULL)
//	{
//		cout<<pop(s,xx);
//		s=s->next;
//	}

}
