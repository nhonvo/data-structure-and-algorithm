#include<iostream>
using namespace std;

typedef struct linklist{
	struct linklist* next;
	int data;
}node;

node* createnode(int value)
{
	node* head= new node;
	head->data=value;
	head->next=NULL;
	return head;
}
node* init(node* &head)
{
	head=NULL;
}
node* ISEMPTY(node* head)
{
	return head=NULL;
}
void addhead(node* &head, int value)
{
	node* p=createnode(value);
	if(ISEMPTY(head))
	{
		cout<<"Nothing";
	}
	else
	{
		p->next=head;
		head=p;
	}
}
void addtail(node* head, int value)
{
	node* p=createnode(value);
	if(ISEMPTY(head))
	{
		head=p;		
	}
	else
	{
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next=p;
	}
}
void addafter(node* p, int value)
{
	node* node_them=createnode(value);
	if(p!=NULL)
	{
		node_them->next=p->next;
		p->next=node_them;		
	}
}

node* Search_node(node* phead, int x)
{
	node* p=phead;
	if(ISEMPTY(p)){
		printf("Ds rong");
	}else
	{
		for(int i=1;p!=NULL;p=p->next)
            if(p->data==x)
	        {
	            return p;
	        }
        printf("Trong dslk khong co node can tim \n");
        return 0;
	}	
}
void deletefirst(node* &head)
{
	node* p=head;
	if(ISEMPTY(head))
	{
		cout<<"Nothing";
	}
	else
	{
		head=head->next;
		delete p;
	}
}
void deletetail(node* head)
{
	node* p=head;
	if(ISEMPTY(head))
	{
		cout<<"Nothing";
	}
	else
	{
		while(p->next->next!=NULL)
		{
			p=p->next;
		}
		p->next=p->next->next;
	}
}
void DeleteAfter(node* p)
{
	node* q=p->next;
	if(p!=NULL and p->next!=NULL)
	{
		p->next=p->next->next;
		delete q;
	}
	else
	{
		printf("Nothing");
	}
}
void input(node* &head)
{
	int n,x;
	init(head);
	cout<<"Enter the number of elements: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i<<": ";
		cin>>x;
		addhead(head,x);
	}
}
void show(node* head)
{
	cout<<"Show linked-list:";
	if(ISEMPTY(head)){
		cout<<"Nothing";
	}
	else
	{
		while(head!=NULL)
		{
			cout<<" "<<head->data;
			head=head->next;
		}
	}
	cout<<"\n";
}
int main()
{
	node* head;
	init(head);
// Nhap xuat ds:
	input(head);
	show(head);
// them vao dau va cuoi:
	cout<<"Them vao dau va cuoi:\n";
	addhead(head,6);
	addtail(head,6);
	show(head);
//xoa phan tu
	cout<<"Xoa vao dau va cuoi:\n";
	deletefirst(head);
	deletetail(head);
	show(head);	
//them vao sau 
	int x,gtri;
	cout<<"Nhap gia tri can them: "; cin>>gtri;
	cout<<"Nhap so can tim:"; cin>>x;
	node* after=Search_node(head,x);
	addafter(after,gtri);
	show(head);

	return 0;
}
