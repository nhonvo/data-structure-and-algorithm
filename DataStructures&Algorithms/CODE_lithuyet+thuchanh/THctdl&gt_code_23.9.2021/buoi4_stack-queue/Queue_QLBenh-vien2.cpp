//Vo Thuong Truong Nhon 
//2080600542
//20DTHD4
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct benhnhan
{
	int stt;
	char hoten[40];
	int tuoi;
}bn;

typedef struct Node
{
	bn data;
	Node* next;
}node;

typedef struct Queue
{
	node* phead;
	node* ptail;
}queue;
//----------------------------------------------------------------
void nhap(bn &x)
{

	scanf("%d", &x.stt); 
	fflush(stdin); gets(x.hoten);
	scanf("%d", &x.tuoi);
}
void xuat(bn x)
{
	printf("\n%d--%s--%d", x.stt, x.hoten, x.tuoi);
}
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
node* createnode(bn x)
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
	int dem;
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
			bn x = q.phead->data;
			q.phead=q.phead->next;
		}
	}
	delete p;
}
//----------------------------------------------------------------
void InputData(queue &q)
{
//	int n;
	bn x;
//	printf("Nhap so luong benh nhan: ");
//	scanf("%d", &n);
	printf("\n\nNhap lan luot stt, ho va ten, tuoi: \n\n");
//	for(int i=0;i<n;i++)
//	{
		printf("Nhap thong tin benh nhan : \n");
		nhap(x);
		node* p= createnode(x);
		Push(q,p);
//	}
}
//----------------------------------------------------------------
void show(queue q)
{
	node* p=q.phead;
	if(p==NULL)
	{
		printf("\nDanh sach rong");
	}
	else
	{
		while(p!=NULL)
		{
			xuat(p->data);
			p=p->next;
		}
		printf("\n");
	}
	
}
void show_1(queue q)
{
	node* p=q.phead;
	if(p==NULL)
	{
		printf("\nDanh sach rong");
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		xuat(p->data);
		printf("\n");
	}
	
}
int dem_fun(queue q)
{
	int dem=0;
	node* p= q.phead;
	while(p!=NULL)
	{
		p=p->next;
		dem++;
	}
	return dem;
}
//----------------------------------------------------------------
int main()
{
	queue q;
	Init(q);
	int n, dem=0;
	do
	{
		system("cls");
		printf("CHUONG TRINH QUAN LY BENH VIEN BANG QUEUE\n");
		printf("\n********************************************");
		printf("\n*   1.Them 1 benh nhan vao hang doi        *");
		printf("\n*   2.Lay benh phan khoi hang doi          *");
		printf("\n*   3. So luong benh nhan da kham          *");
		printf("\n*   4. So luong benh nhan chua kham        *");
		printf("\n*   5. Xuat danh sach benh nhan trong queue*");
		printf("\n*   6. Xuat thong tin benh nhan cuoi cung  *");
		printf("\n*   0. Thoat chuong trinh                  *");
		printf("\n********************************************");

		printf("\nChon chuc nang n: ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
			{
				InputData(q);
				break;
			}
			case 2:
			{
				printf("\n Da lay ra benh nhan tiep theo!!!");
				Pop(q);
				dem++;
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 3:
			{
				printf("\nSo luong benh nhan da kham: %d", dem);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 4:
			{
				printf("\nSo luong benh nhan chua kham: %d", dem_fun(q));
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 5:
			{
				printf("\nXuat danh sach benh nhan con lai: ");
				show(q);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 6:
			{
				printf("\nXuat thong tin benh nhan cuoi cung: ");
				show_1(q);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 0:
			{
				printf("\n");
				printf("\n  Cam on da su dung chuong trinh cua chung toi!");
				getch();	
				return 0;
			}								
			default:printf("Lua chon trong 0-6! ");
			printf("\nNhan phim bat ki de tiep tuc!");
			getch();
		}
	}while(n!=0);
	return 0;
}
