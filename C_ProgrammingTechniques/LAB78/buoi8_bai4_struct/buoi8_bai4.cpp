#include <stdio.h>
#include <stdlib.h>
#include<string.h>

FILE *f1;


typedef struct computer
{
	char ten[20];
	int ma;
	int bonho;
	int tocdo;
	float gia;
	char nsx[20];	
} mt;

void nhap_1_mt(mt &a)
{
	fflush(stdin);
	printf("\nTen may tinh:");
	gets(a.ten);
	printf("Ma may tinh:");
	scanf("%d",&a.ma);
	printf("Bo nho may tinh:");
	scanf("%d",&a.bonho);
	printf("Toc do may tinh:");
	scanf("%d",&a.tocdo);
	printf("Gia tien may tinh:");
	scanf("%f",&a.gia);
	fflush(stdin);
	printf("Nha san xuat may tinh: ");
	gets(a.nsx);
}
void xuat_1_mt(mt a){
	printf("\nTen may tinh: ");
	puts(a.ten);
	printf("Ma may tinh: %d",a.ma);
	printf("\nBo nho may tinh: %d",a.bonho);
	printf("\nToc do may tinh: %d",a.tocdo);
	printf("\nGia tien may tinh: %f",a.gia);
	printf("\nNha san xuat may tinh: ");
	puts(a.nsx);
}
void nhap_N(mt a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nNhap may thu %d",i+1);
		nhap_1_mt(a[i]);
	}
}
void xuat_N(mt a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nMay thu %d",i+1);
		xuat_1_mt(a[i]);
	}
}


void xuatfile(mt a[], int n)
{
	f1 =fopen("bai4_out","w");
	for(int i=0;i<n;i++){
		
		fprintf(f1,"\nMay tinh thu %d:",i+1);
		fprintf(f1,"\nTen may tinh: ");
		fputs(a[i].ten,f1);
		fprintf(f1,"\nMa may tinh: %d",a[i].ma);
		fprintf(f1,"\nBo nho may tinh: %d",a[i].bonho);
		fprintf(f1,"\nToc Do may tinh: %d",a[i].tocdo);
		fprintf(f1,"\nGia may tinh: %f",a[i].gia);
		fprintf(f1,"\nNha san xuat may tinh: ");
		fputs(a[i].nsx,f1);
	}
	fclose(f1);
}
int maxbonho(mt a[], int n)
{
	int m = a[0].bonho;
	for(int i=0;i<n;i++)
	{
		if(a[i].bonho>m)
		{
			m=a[i].bonho;
		}
	}
	return m;
}
void xuatmaxbonho(mt a[],int n)
{
	int m = maxbonho(a,n);
	printf("\nCac may co bo nho lon nhat la:\n");
	for(int i=0;i<n;i++)
	{
		if(a[i].bonho==m)
		{
			xuat_1_mt(a[i]);
		}
	}
}


int max(mt a[], int n)
{
	int m = a[0].tocdo;
	for(int i=0;i<n;i++)
	{
		if(a[i].tocdo>m)
		{
			m=a[i].tocdo;
		}
	}
	return m;
}
void xuatmaxtocdo(mt a[],int n)
{
	int m = max(a,n);
	printf("\nCac may co toc do lon nhat la:\n");
	for(int i=0;i<n;i++)
	{
		if(a[i].tocdo==m)
		{
			xuat_1_mt(a[i]);
		}
	}
}



void nsx(mt a[],int n)
{
	int dem[100];
	int d;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (strcmp(a[i].nsx, a[j].nsx) == 0)
			{
				d++;
			}
		}
		dem[i]=d;
	}
	int max=dem[0];
	int c;
	for(int i=0;i<n;i++)
	{
		if(dem[i]>max)
		{
			max=dem[i];
		}	
	}
	for(int i=0;i<n;i++)
	{
		if(dem[i]=max)
		{
			c=i;
			break;
		}	
	}
	printf("\n\n\nNha san xuat co nhieu san pham nhat la: ");
	puts(a[c].nsx);
}







int main()
{
	mt a[100];
	int n;
	printf("nhap so luong may tinh: ");
	scanf("%d",&n);
	nhap_N(a,n);
	xuat_N(a,n);
	xuatfile(a,n);
	xuatmaxtocdo(a,n);
	xuatmaxbonho(a,n);
	nsx(a,n);
	
}
