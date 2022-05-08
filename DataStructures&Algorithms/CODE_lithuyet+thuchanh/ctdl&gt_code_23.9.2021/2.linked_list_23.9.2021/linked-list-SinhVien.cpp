//Vo Thuong Truong Nhon
//2080600542
//20DTHD4

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sinhvien{
	char masv[10];
	char tensv[20];
	float diemtb;
};
typedef struct linkedlist{
	sinhvien data ;
	struct linkedlist* next;
}node;

//--Khoi dong danh sach lien ket gan head =null---1
void init(node* &phead)
{
	phead = NULL;
}
//--kiem tra dslk co rong khong--2
int IsEmpty(node* phead)
{
	return phead == NULL;
}

void nhap_sv(sinhvien &x)
{
	
	printf("Nhap ma so sv: ");fflush(stdin); gets(x.masv);
	printf("Nhap ten sv: "); fflush(stdin); gets(x.tensv);
	printf("Nhap diem trung binh: "); scanf("%f",&x.diemtb);
	printf("\n----------------------------------------------\n");
}
void xuat_sv(sinhvien x)
{
	printf("%s--%s--%.2f\n",x.masv,x.tensv,x.diemtb);
}

node* createnode(sinhvien sv)
{
	node* p= new node;	
	p->next=NULL;
	p->data = sv;
	return p;
}

//--them node vao dau dslk --3

void InsertFirst(node* &phead, sinhvien x)
{
	node* p= createnode(x);
	
	if(phead==NULL)
		phead = p;
	else
	{
		p->next = phead;
		phead = p;
	}
}
//--ham them  node vao phia sau node p dslk--4
node* Search_node(node* phead, char x[])
{
	node* p=phead;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(int i=1;p!=NULL;p=p->next)
            if(strcmp( p->data.masv,x)==0)
	        {
	            return p;
	        }
        printf("Trong dslk khong co node can tim :v");
	}	
}
void InsertAfter(node* &p, sinhvien x)
{
	node* tmp= createnode(x);
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
//xoa node dau dslk --5
void Deletefirst(node* &phead)
{
	node* p=phead;
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
//	--xoa node phia sau node p dslk--6
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
//	--xoa tat ca trong dslk ---7
void DeleteAll(node* &phead)
{
	node* p;
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
void Search(node* phead, char x[])
{
	node* p=phead;
	if(IsEmpty(p)){
		printf("Ds rong");
	}else
	{
		for(p=phead;p!=NULL;p=p->next)
            if(strcmp(p->data.masv,x)==0)
	        {
	            printf("\nThong tin sinh vien can tim: ");
				xuat_sv(p->data);
	            return;
	        }
        printf("Trong dslk khong co node can tim :v");
	}
	
}
//--ham sapxep dslk don--10
void swap(sinhvien &a, sinhvien &b)
{
	sinhvien c=a;
	a=b;
	b=c;
}
void sapXep(node* &phead)
{
	node* i= phead;
	while(i !=NULL)
	{
		node* j= phead;
		for(j; j!=NULL; j=j->next)
		{
			if(j->data.diemtb > i->data.diemtb) 
				swap(j->data,i->data);
		}
		i=i->next;
	}	
}

void InputData(node* &phead)
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	sinhvien x;
	for(int i=0;i<n;i++)
	{
		printf("Nhap sinh vien thu %d: \n", i);
		nhap_sv(x); 
		InsertFirst(phead,x);
	}
}
//xuat danh sach--8
void show(node* &phead)
{
	node* p=phead;
	int i=0;
	printf("\nXuat:\n");
	if(p==NULL)
		printf("\nDs rong.");
	while(p !=NULL)
	{
		printf("\nSinh vien thu %d \n",i);
		xuat_sv(p->data);
		p=p->next;
		i++;
	}
	printf("\n");
}

int main()
{
	
	node* head;
	init(head);
//nhap du lieu
	InputData(head);	
	show(head);
//them sv vao dau ds--3
	sinhvien sv;
	printf("\nNhap thong tin sinh vien de them vao dau: \n");
	nhap_sv(sv);
	InsertFirst(head,sv);
	show(head);
//them sv vao cuoi--4
	char haha[10];
	sinhvien sv2;
	printf("\nNhap ma so sv can tim de them:"); fflush(stdin); gets(haha);
	printf("\nNhap thong tin sinh vien de them vao sau: \n");
	nhap_sv(sv2);
	node* them_cuoi = Search_node(head,haha);
	InsertAfter(them_cuoi,sv2);
	show(head);
//xoa node dau --5
	printf("\nXoa node dau tien: ");
	Deletefirst(head);
	show(head);
//xoa node sau --6
	char huhu[10];
	printf("\nNhap ma so sv can tim de xoa:"); fflush(stdin); gets(huhu);
	node* xoa_node = Search_node(head,huhu);
	DeleteAfter(xoa_node);
	show(head);
//xoa tat ca --7
	DeleteAll(head);
	show(head);
//tim kiem --9
	char hihi[10];
	printf("\nNhap ma so sv can tim de tim:"); fflush(stdin); gets(hihi);
	Search(head,hihi);
//sap xep --10
	printf("\nSap xep danh sach sinh vien theo diem trung binh:\n");
	sapXep(head);
	show(head);
	return 0;
}
