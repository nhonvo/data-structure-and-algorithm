#include <stdio.h>
#include<stdlib.h>

//--khoi tao thanh phan node bang struct
typedef struct node{
	int info;
	struct node* next;
}Node;
//--Khoi dong danh sach lien ket gan head =null---1
void init(Node* &phead)
{
	phead = NULL;
}
//--kiem tra dslk co rong khong--2
int IsEmpty(Node* phead)
{
	return phead == NULL;
}
//--cung cap mot bien dong cho dslk, tao nut du lieu x
Node* CreateNode(int x)
{
	Node* p = new Node;
	p->info=x;
	p->next=NULL;
	return p;
}
//--them node vao dau dslk --3
void InsertFirst(Node* &phead, int x)
{
	Node* p= CreateNode(x);
	if(phead==NULL)
		phead = p;
	else
	{
		p->next = phead;
		phead = p;
	}
}

//--ham them  node vao phia sau node p dslk--4
Node* Search_node(Node* phead, int x)
{
	Node* p=phead;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(int i=1;p!=NULL;p=p->next)
            if(p->info==x)
	        {
	            return p;
	        }
        printf("Trong dslk khong co node can tim :v");
	}	
}

void InsertAfter(Node* p, int x)
{
	Node* tmp= CreateNode(x);
	if(IsEmpty(p)){
		printf("Ko them duoc");
	}
	else
	{
		if(p!=NULL)
		{
			tmp->next=p->next;
			p->next =tmp;
		}
	}
}
//--them node vao cuoi dslk --
void addLast(Node* head, int value)
{
	node* p=createnode(value);
	if(IsEmpty(head))
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
//--ham xoa node dau dslk--5.1
void Deletefirst(Node* &phead)
{
	Node* p=phead;
	if(IsEmpty(phead))
	{
		printf("Nothing");
	}
	else
	{
		phead = phead->next;
		delete p;
	}
}
//--ham xoa node dau dslk--5.2
void DeleteLast(Node* &head)
{
    if(IsEmpty(head))
        printf("\nDanh sach sach rong.");
    else {
        Node* p = head;
        if (p->next == NULL) init(head);
        else {
            Node* q=p->next;
            while(q->next != NULL)
            {
                p = p->next;
                q = p->next;
            }
            p->next = NULL;
            delete q;
        }
    }
}
//	--xoa node phia sau node p dslk--6
void DeleteAfter(Node* p)
{
	Node* q=p->next;
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
//	--xoa tat ca trong dslk ---7
void DeleteAll(Node* &phead)
{
	Node* p;
	if(phead==NULL)
	{
		printf("Nothing");
	}
	else
	{
		while(phead!=NULL)
		{
			p=phead;
			phead=p->next;
			delete p;
		}
	}
}

//	--ham tìm kiem--9
void Search(Node* phead, int x)
{
	node* p=phead;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(int i=1;p!=NULL;p=p->next)
            if(p->info==x)
	        {
	            printf("\nVi tri node can tim: %d", i);
	            return;
	        }
        printf("Trong dslk khong co node can tim :v");
	}
	
}
//	--sap sep dslk--10=chua hieu lam
void sort(Node* &phead)
{
	Node* p;
	Node* q;
	Node* pmin;
	int min;
	for(p=phead; p->next!=NULL;p=p->next)
	{
		min =p->info;
		pmin = p;
		for(q=p->next; q!=NULL; q=q->next)
		{
			if(q->info < min)
			{
				min = q->info;
				pmin =q;
			}
		}
		pmin->info =p->info;
		p->info=min;
	}
}

void InputData(Node* &phead)
{
	int n, x;
	init(phead);
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap gia tri node thu %d: ", i);
		scanf("%d", &x);
		InsertFirst(phead,x);
	}
}
//xuat danh sach--8
void show(Node* phead)
{
	Node* p=phead;
	printf("\nXuat:\n");
	if(p==NULL)
		printf("\nDs rong.");
	while(p !=NULL)
	{
		printf("%d ", p->info);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	Node* phead;
	init(phead);
//	-Nhap du lieu vao node
	InputData(phead);
	show(phead);
	
//	init();---1
//	IsEmpty(); --2
//	--them vao dau --3
	printf("\nThem 5 vao dau ds.");
	InsertFirst(phead,5);
	show(phead);	

//	--them vao phia sau--4

	int phan_tu_4,phan_tu_4_1;
	printf("\nThem phan tu vao phia sau phan tu__va  phan tu__muon them: ");
	scanf("%d%d",&phan_tu_4,&phan_tu_4_1);
	Node* p_them=Search_node(phead,phan_tu_4);
	InsertAfter(p_them,phan_tu_4_1);
	show(phead);

//	--xoa dau --5
	printf("\nXoa phan tu dau tien trong ds.");
	Deletefirst(phead);
	show(phead);

//	--xoa phan tu sau--6
	int phan_tu_6;
	printf("\nXoa phan tu vao phia sau phan tu__: ");
	scanf("%d",&phan_tu_6);
	Node* p_xoa=Search_node(phead,phan_tu_6);
	DeleteAfter(p_xoa);
	show(phead);

//-- Show list,show(); --8

//		--tim node--9

	int so_can_tim;
	printf("\nNhap vao so can tim: "); scanf("%d",&so_can_tim);
	Search(phead,so_can_tim);

//	--sap xep cac phan tu trong dslk --10
	printf("\nDanh sach sau khi duoc sap xep: \n");
	sort(phead);
	show(phead);
//--Xoa tat ca phan tu trong dslk --7
	printf("\nXoa tat ca:\n");
	DeleteAll(phead);
	show(phead);
	return 0;
}
