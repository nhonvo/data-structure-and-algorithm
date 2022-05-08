//Vo Thuong Truong Nhon 
//2080600542
//20DTHD4
#include<stdio.h>
#include<conio.h>
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
//--them node vao dau dslk --1
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
//3. Xoa node dau dslk don
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
//Cau 4: Them vao dau dslk sao cho khong trung
int Search_node(Node* phead, int x)
{
	Node* p=phead;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(int i=1;p!=NULL;p=p->next)
            if(p->info==x)
	        {
	            return 1;
	        }
        return 0;
	}	
}
void InputData_2(Node* &phead)
{
	int n, x;
	printf("\nNhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		do{
			printf("Nhap gia tri node thu %d: ", i);
			scanf("%d", &x);
		}while(Search_node(phead,x));
		
		InsertFirst(phead, x);
	}
}
//Cau 1: Nhap
void InputData(Node* &phead)
{
	int n, x;
	printf("\nNhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		do
		{
			printf("Nhap gia tri node thu %d: ", i);
			scanf("%d", &x);
			if(x<0)
			{
				printf("\nNhap so duong!\n");
			}	
		}while(x<0);
	
		InsertFirst(phead,x);
	}
}
//Cau 2:
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
	InputData(phead);
	show(phead);
	printf("\nDanh sach lien ket sau khi xoa cuoi: ");
	DeleteLast(phead);
	show(phead);
	printf("\nThem vao dau n phan tu: ");
	InputData_2(phead);
	show(phead);
	return 0;
}
