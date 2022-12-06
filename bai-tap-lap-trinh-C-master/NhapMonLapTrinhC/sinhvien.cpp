#include <stdio.h>
#include <conio.h>

struct sinhvien
{
	char hoTen[100];
	char namSinh[10];
	char lop[20];
	char mssv[20];
	float diemTB;
};
void nhap(sinhvien a[], int &n)
{
	printf (" Nhap vao so luong sinh vien: ");
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf ("\nSinh vien thu %d: ", i+1);
		printf (" \n\tHo va Ten: ");
		fflush(stdin);
		gets(a[i].hoTen);
		
		printf ("\n\tNam sinh: ");
		gets(a[i].namSinh);
		
		printf (" \n\tLop: ");
		fflush(stdin);
		gets(a[i].lop);
		
		printf ("\n\tMSSV: ");
		fflush(stdin);
		gets(a[i].mssv);
		
		printf ("\n\tDiem trung binh: ");
		scanf("%f", &a[i].diemTB);
	}
}

void xuat(sinhvien a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("\nSinh vien thu %d: ", i+1);
		printf (" \n\tHo va Ten: ");
		printf ("%s",a[i].hoTen);
		
		printf ("\n\tNam sinh: ");
		printf ("%s", a[i].namSinh);
		
		printf (" \n\tLop: ");
		printf ("%s", a[i].lop);
		
		printf ("\n\tMSSV: ");
		printf ("%s", a[i].mssv);
		
		printf ("\n\tDiem trung binh: ");
		printf("%.1f", a[i].diemTB);
	}
}

float maxTB(sinhvien a[], int n)
{
	float max = a[0].diemTB;
	for (int i = 0; i < n; i++)
	{
		if (a[i].diemTB > max)
			max = a[i].diemTB;
	}
	return max;
}

int main()
{
	sinhvien a[100];
	int n;
	nhap(a, n);
	xuat(a, n);
	float k = maxTB(a ,n);
	printf ("\nDiem trung binh cao nhat la: %.1f", k);
}
