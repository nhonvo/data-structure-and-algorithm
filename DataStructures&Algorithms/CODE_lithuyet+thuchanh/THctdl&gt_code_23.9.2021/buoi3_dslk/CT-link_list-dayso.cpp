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
//--them node vao cuoi dslk --2
void InsertLast(Node* &phead, int x)
{
	Node* p= CreateNode(x);
	if(phead==NULL)
		phead = p;
	else
	{
		while(phead!=NULL)
		{
			phead= phead->next;
		}
		phead->next=p;
	}
}
//--ham them  node vao phia sau node p dslk--3
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
        return NULL;
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
//ham tim kiem phan tu
int timkiem_node(Node* phead, int x)
{
	Node* p=phead;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(int i=0;p!=NULL;p=p->next)
            if(p->info==x)
	        {
	            return i;
	        }
        printf("Trong dslk khong co node can tim :v");
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
//sap xep chon
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

//Xoa dau
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
void InputLast(Node* &phead)
{
	int n, x;
	init(phead);
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap gia tri node thu %d: ", i);
		scanf("%d", &x);
		InsertLast(phead,x);
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
	int n, dem=0;
	do
	{
		system("cls");
		printf("CHUONG TRINH LINK-LIST DAY SO\n");
		printf("\n********************************************");
		printf("\n*   1.Them vao dau                         *");
		printf("\n*   2.Them vao cuoi                        *");
		printf("\n*   3. Them vao sau                        *");
		printf("\n*   4. Xoa dau                             *");
		printf("\n*   5. Xoa sau                             *");
		printf("\n*   6. Xoa tat ca                          *");
		printf("\n*   7.Them vao n phan tu vao dau           *");
		printf("\n*   8. Xuat day so                         *");
		printf("\n*   9. Them vao n phan tu vao cuoi         *");
		printf("\n*   10.Tim phan tu                         *");
		printf("\n*   11.Dem so luong Node                   *");
		printf("\n*   12.Tim Gia tri lon nhat                *");
		printf("\n*   13.Sap xep day so theo kieu chon       *");
		printf("\n*   14.Tim vi tri phan tu                  *");	
		printf("\n*   0. Thoat chuong trinh                  *");
		printf("\n********************************************");

		printf("\nChon chuc nang n: ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
			{
				int cau1;
				printf("\nNhap so de them vao dau: ");
				scanf("%d", &cau1);
				InsertFirst(phead,cau1);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 2:
			{
				int cau2;
				printf("\nNhap so de them vao cuoi: ");
				scanf("%d", &cau2);
				InsertLast(phead,cau2);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 3:
			{
				int phan_tu_4,phan_tu_4_1;
				printf("\nThem phan tu vao phia sau phan tu__va  phan tu__muon them: ");
				scanf("%d%d",&phan_tu_4,&phan_tu_4_1);
				Node* p_them=Search_node(phead,phan_tu_4);
				if(p_them==NULL)
				{
					printf("Trong dslk khong co node can tim :v");
				}else
				{
					InsertAfter(p_them,phan_tu_4_1);
				}
				
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 4:
			{
				Deletefirst(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 5:
			{
				int phan_tu_6;
				printf("\nXoa phan tu vao phia sau phan tu__: ");
				scanf("%d",&phan_tu_6);
				Node* p_xoa=Search_node(phead,phan_tu_6);
				DeleteAfter(p_xoa);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 6:
			{
				DeleteAll(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 7:
			{
				InputData(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 8:
			{
				show(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 9:
			{
				InputLast(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 10:
			{
				int cau10;
				printf("\nNhap phan tu can tim: ");
				scanf("%d", &cau10);
				timkiem_node(phead,cau10);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 11:
			{
				demnode(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 12:
			{
				GT(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 13:
			{
				sort(phead);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 14:
			{
				int cau14;
				printf("\nNhap gia tri phan tu can tim vt: ");
				scanf("%d", &cau14);	
				vitri(phead, cau14);
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
			default:printf("Lua chon trong 0-5! ");
			printf("\nNhan phim bat ki de tiep tuc!");
			getch();
		}
	}while(n!=0);
	return 0;
}
