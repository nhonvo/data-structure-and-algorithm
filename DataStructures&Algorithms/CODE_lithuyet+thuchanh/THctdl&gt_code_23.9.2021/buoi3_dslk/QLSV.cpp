#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

typedef struct sinhvien{
	char mssv[10];
	char ten[40];
	float diem;
}sv;
struct node{
	sv data;
	node* next;
};
typedef node Node;
void nhap_1_sv(sv &x)
{
	cout<<"\n\nNhap mssv: "; cin>>x.mssv;
	cout<<"\nNhap ho va ten: ";	fflush(stdin); gets(x.ten);
	cout<<"\nNhap diem trung binh: "; cin>>x.diem;
}
void xuat_1_sv(sv x)
{
	cout<<x.mssv<<"--"<<x.ten<<"--"<<x.diem<<endl;
}
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
Node* CreateNode(sv x)
{
	Node* p = new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
//--them node vao dau dslk --1
void InsertFirst(Node* &phead, sv x)
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
//--them node vao cuoi dslk --2???
void InsertLast(Node* &phead, sv x)
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

void InputData(Node* &phead)
{
	int n;
	sv x;
	init(phead);
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap thong tin sinh vien thu %d: ", i);
		nhap_1_sv(x);		
		InsertFirst(phead,x);
	}
}
//xuat danh sach--8
void show(Node* phead)
{
	int i=0;
	Node* p=phead;
	printf("\nDanh sach sinh vien:\n");
	if(p==NULL)
		printf("\nDs rong.");
	while(p !=NULL)
	{
		cout<<"\nThong tin sinh vien thu "<<i<<": ";
		xuat_1_sv(p->data);
		p=p->next;
		i++;
	}
	printf("\n");
}
//cau c.
void dtb_lon_5(Node* head, sv x)
{
	Node* p =new node;
	p=head;
	while(p!=NULL)
	{
		if(p->data.diem>5)
			xuat_1_sv(p->data);
		p=p->next;
	}
}
//cau d.
void tim_kiem_sv(Node* head, sv x, char ms[10])
{
	Node* p=head;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(int i=0;p!=NULL;p=p->next)
            if(strcmp(p->data.mssv,ms) == 0)
	        {
	            xuat_1_sv(p->data);
	        }
//        printf("Trong dslk khong co node can tim :v");
	}	
}
//cau e.
void swap(Node* p, Node* q)
{
	Node* tmp = p;
	p = q;
	q =tmp;
}
void sap_xep_sv(Node* phead, sv x)
{
	if(IsEmpty(phead)){
		printf("Ds rong");
	}else
	{
		Node* p;
		Node* q;
		for(p=phead; p!=NULL;p=p->next)
		{
			for(q=p->next; q!=NULL; q=q->next)
			{
				if(p->data.diem > q->data.diem)
				{
					swap(p,q);
				}
			}
		}
	}
}
int main()
{
	Node* head;
	sv x;
	init(head);
	int n;
	do
	{
		system("cls");
		printf("CHUONG TRINH LINK-LIST DAY SO\n");
		printf("\n********************************************");
		printf("\n*   1. Nhap danh sach sinh vien            *");
		printf("\n*   2. Xuat danh sach sinh vien            *");
		printf("\n*   3. Xuat sv co dtb>5                    *");
		printf("\n*   4. Tim sinh vien co ma X               *");
		printf("\n*   5. Sap xep ds tang dan theo dtb  ???   *");
		printf("\n*   6. Them sv sau sv co ma X              *");
		printf("\n*   7. Xoa sv dau danh sach                *");
		printf("\n*   8. Xoa sv cuoi danh sach               *");
		printf("\n*   9. Xoa toan bo danh sach               *");
		printf("\n*   10. Xoa sv co ma X                     *");
		printf("\n*   11. Xoa sv sau sv co ma X              *");
		printf("\n*   12. Xoa tat ca sinh vien co ten X      *");
		printf("\n*   13.Sap xep sv tang dan theo mssv       *");
		printf("\n*   14. In ds sinh vien xep loai kha       *");
		printf("\n*   15. Cho biet sv co dtb cao/thap nhat   *");	
		printf("\n*   0. Thoat chuong trinh                  *");
		printf("\n********************************************");

		printf("\nChon chuc nang n: ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
			{
				printf("\nNhap danh sach sinh vien:\n");
				InputData(head);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 2:
			{
				printf("\n Xuat danh sach sinh vien: ");
				show(head);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 3:
			{
				sv cau3;
				printf("\nDs sinh vien co dtb > 5: ");
				dtb_lon_5(head, cau3);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 4:
			{
				char cau4[10];
				cout<<"\nNhap mssv can tim: "; cin>>cau4;
				printf("\nSinh vien can tim la: ");
				tim_kiem_sv(head,x,cau4);
				printf("\nNhan phim bat ki de tiep tuc!");
				getch();
				break;
			}
			case 5:
			{
				int cau5;
				printf("\nSap xep sv tang dan theo dtb: ");
				sap_xep_sv(head, x);
				show(head);
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
			default:printf("Lua chon trong 0-15! ");
			printf("\nNhan phim bat ki de tiep tuc!");
			getch();
		}
	}while(n != 0);
	return 0;
}

