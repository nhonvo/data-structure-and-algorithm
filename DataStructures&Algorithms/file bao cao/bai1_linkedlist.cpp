#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct sinhvien
{
	char masv[11];
	char tensv[41];
	float diemtb;
};
typedef struct sinhvien sv;

typedef struct linkedlist
{
	sinhvien data;
	linkedlist *next;
} node;

void init(node *&phead);
int IsEmpty(node *phead);
void nhap_sv(sinhvien &x);
void xuat_sv(sinhvien x);
node *createnode(sinhvien sv);
void InsertFirst(node *&phead, sinhvien x);
void InputData(node *&phead);
void show(node *&phead);
void Search(node *phead, char x[10]);
void dtb_lon_5(node *head, sv x);

int main()
{
	node *head;
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
		printf("\n*   0. Thoat chuong trinh                  *");
		printf("\n********************************************");

		printf("\nChon chuc nang n: ");
		scanf("%d", &n);
		switch (n)
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
			printf("\nNhap mssv can tim: ");
			fflush(stdin);
			gets(cau4);
			printf("\nSinh vien can tim la: \n");
			Search(head, cau4);
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
		default:
			printf("Lua chon trong 0-4! ");
			printf("\nNhan phim bat ki de tiep tuc!");
			getch();
		}
	} while (n != 0);
	return 0;
}
void init(node *&phead)
{
	phead = NULL;
}
int IsEmpty(node *phead)
{
	return phead == NULL;
}

void nhap_sv(sinhvien &x)
{
	printf("Nhap ma so sv: ");
	fflush(stdin);
	gets(x.masv);
	printf("Nhap ten sv: ");
	fflush(stdin);
	gets(x.tensv);
	printf("Nhap diem trung binh: ");
	scanf("%f", &x.diemtb);
	printf("\n\n");
}
void xuat_sv(sinhvien x)
{
	printf("%s--%s--%.2f\n", x.masv, x.tensv, x.diemtb);
}

node *createnode(sinhvien sv)
{
	node *p = new node;
	p->next = NULL;
	p->data = sv;
	return p;
}

void InsertFirst(node *&phead, sinhvien x)
{
	node *p = createnode(x);

	if (IsEmpty(phead))
		phead = p;
	else
	{
		p->next = phead;
		phead = p;
	}
}
void InputData(node *&phead)
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	sinhvien x;
	for (int i = 0; i < n; i++)
	{
		printf("Nhap sinh vien thu %d: \n", i);
		nhap_sv(x);
		InsertFirst(phead, x);
	}
}
void show(node *&phead)
{
	node *p = phead;
	int i = 0;
	printf("\nXuat:\n");
	if (p == NULL)
		printf("\nDs rong.");
	while (p != NULL)
	{
		printf("\nSinh vien thu %d \n", i);
		xuat_sv(p->data);
		p = p->next;
		i++;
	}
	printf("\n");
}

void Search(node *phead, char x[10])
{
	node *p = phead;
	if (IsEmpty(p))
	{
		printf("Ds rong");
	}
	else
	{
		for (p = phead; p != NULL; p = p->next)
			if (strcmp(p->data.masv, x) == 0)
			{
				printf("\nThong tin sinh vien can tim: ");
				xuat_sv(p->data);
				return;
			}
		printf("Trong dslk khong co node can tim :v");
	}
}

void dtb_lon_5(node *head, sv x)
{
	node *p = new node;
	p = head;
	while (p != NULL)
	{
		if (p->data.diemtb > 5)
			xuat_sv(p->data);
		p = p->next;
	}
}
