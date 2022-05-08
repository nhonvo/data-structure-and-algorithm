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
// dem so nut
void demnode(Node* p)
{
	int i;
	if(IsEmpty(p)){
		printf("Ko dem duoc");
	}
	else
	{
		while(p!=NULL)
		{
			p=p->next;
			i++;	
		}	
	}
	printf("\nSo no cua danh sach la: %d", i);
}
//Nhap k tim giá tri
void vitri(Node* p, int k)
{
	
	if(IsEmpty(p))
	{
		printf("Ko duoc");
	}
	else
	{
		for(int i=0;p!=NULL;p=p->next)
		{
			if(i==k)
			{
				printf("\ni= %d, k= %d", i, p->info);
			}
		}
	}
}
//tim gia tri lon nhat
void GT(Node* p)
{
	int max=p->info;
	if(IsEmpty(p))
	{
		printf("Ko duoc");
	}
	else
	{
		while(p!=NULL)
		{
			if(p->info>max)
			{
				max=p->info;
			}
			p=p->next;
		}
	}
	printf("\nGia tri node lon nhat: %d", max);
}


//	--xoa node phia sau node p dslk--6 nho sua lai
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
	GT(phead);
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


//	--xoa phan tu sau--6
	int phan_tu_6;
	printf("\nXoa phan tu vao phia sau phan tu__: ");
	scanf("%d",&phan_tu_6);
	Node* p_xoa=Search_node(phead,phan_tu_6);
	DeleteAfter(p_xoa);
	show(phead);

//-- Show list,show(); --8

	show(phead);
	return 0;
}
