#include <stdio.h>
#include <conio.h>

struct phanSo
{
	int tu;
	int mau;
};

void nhap(phanSo &a, phanSo &b)
{
	do
	{
		printf ("nhap vao tu va mau cua phan so thu 1 ( mau so phai khac 0):\n");
		scanf ("%d %d", &a.tu, &a.mau);
	}while(a.mau == 0);
	do
	{
		printf("\n nhap vao tu va mau cua phan so thu 2 (mau so phai khac 0):\n");
		scanf ("%d %d", &b.tu, &b.mau);
	}while(b.mau ==0);
}

phanSo congPhanSo(phanSo a, phanSo b)
{
	phanSo temp;
	if (a.tu != 0 && b.tu != 0)
	{
		temp.tu = (b.mau * a.tu) + (a.mau * b.tu);
		temp.mau = a.mau * b.mau;
	}
	if (a.tu == 0 && b.tu != 0)
	{
		temp.tu = b.tu;
		temp.mau = b.mau;
	}
	if (b.tu == 0 && a.tu != 0)
	{
		temp.tu = a.tu;
		temp.mau = a.mau;
	}	
	if (a.tu == 0 && b.tu == 0)
	{
		temp.tu = 0;
		temp.mau = 0;
	}
	return temp;
}

phanSo truPhanSo(phanSo a, phanSo b)
{
	phanSo temp;
	if (a.tu != 0 && a.mau != 0 && b.tu != 0 && b.mau != 0)
	{
		temp.tu = (b.mau * a.tu) - (a.mau * b.tu);
		temp.mau = a.mau * b.mau;
	}
	if (a.tu == 0 && a.mau != 0 && b.tu != 0 && b.mau != 0)
	{
		temp.tu = b.tu;
		temp.mau = b.mau;
	}
	if (b.tu == 0 && a.tu != 0 && a.mau != 0 && b.mau != 0)
	{
		temp.tu = a.tu;
		temp.mau = a.mau;
	}	
	if (a.tu == 0 && b.tu == 0)
	{
		temp.tu = 0;
		temp.mau = 0;
	}
	return temp;
}

phanSo nhanPhanSo (phanSo a, phanSo b)
{
	phanSo temp;
	if (a.tu == 0 || b.tu == 0)
	{
		temp.tu = 0;
		temp.mau = 0;
	}
	else
	{
		temp.tu = a.tu * b.tu;
		temp.mau = a.mau * b.mau;
	}
	return temp;
}

phanSo chiaPhanSo (phanSo a, phanSo b)
{
	phanSo temp;
	if (a.tu == 0 || b.tu == 0)
	{
		temp.tu = 0;
		temp.mau = 0;
	}
	else
	{
		temp.tu = a.tu * b.mau;
		temp.mau = a.mau * b.tu;
	}
	return temp;
}

int main()
{
	phanSo a, b;
	nhap(a, b);
	phanSo k = congPhanSo(a, b);
	if (k.tu == 0 || k.mau == 0)
 		printf ("\nCong hai phan so la: 0");
 	else
		printf ("Cong hai phan so la: %d / %d", k.tu, k.mau);
	phanSo t = truPhanSo(a, b);
	if (t.tu == 0 || t.mau == 0)
 		printf ("\nTru hai phan so la: 0");
 	else
 		printf ("\nTru hai phan so la: %d / %d", t.tu, t.mau);
 	phanSo l = nhanPhanSo(a, b);
 	if (l.tu == 0 || l.mau == 0)
 		printf ("\nNhan hai phan so la: 0");
 	else
 		printf ("\nNhan hai phan so la: %d / %d", l.tu, l.mau);
 	phanSo r = chiaPhanSo(a, b);
 	if (r.tu == 0 || r.mau == 0)
 		printf ("\nChia hai phan so la: 0");
 	else
 		printf ("\nChia hai phan so la: %d / %d", r.tu, r.mau);
	
}
