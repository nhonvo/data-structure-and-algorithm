#include <stdio.h>
#include <conio.h>

struct donThuc
{
	int heso;
	int somu;
};

void nhap(donThuc &a, donThuc &b)
{
	printf ("Nhap vao he so va so mu cua don thuc a: ");
	scanf ("%d %d", &a.heso, &a.somu);
	printf ("Nhap vao he so va so mu cua don thuc b: ");
	scanf ("%d %d", &b.heso, &b.somu);
}

donThuc congHaiDonThuc(donThuc a, donThuc b)
{
	donThuc temp;
	if (a.somu == b.somu)
	{
		temp.heso = a.heso + b.heso;
		temp.somu = a.somu;
		printf ("cong la: %dX mu %d", temp.heso, temp.somu);
	}
	if (b.somu > a.somu)
		printf ("cong la: %dX mu %d + %dX mu %d", b.heso, b.somu, a.heso, a.somu);
	else
		printf ("cong la: %dX mu %d + %dX mu %d", a.heso, a.somu, b.heso, b.somu);
	if (b.somu < 0)
		printf (" %dX mu %d - %dX mu %d", a.heso, a.somu, b.heso, b.somu);
	if (a.heso == 0 && b.heso != 0)
		printf (" %dX mu %d", b.heso, b.somu);	
}

donThuc truHaiDonThuc(donThuc a, donThuc b)
{
	donThuc temp;
	if (a.somu == b.somu)
	{
		temp.heso = a.heso - b.heso;
		temp.somu = a.somu;
		printf ("\ntru la: %dX mu %d", temp.heso, temp.somu);
	}
	else
	{
		if (b.somu > a.somu)
			printf ("\ntru la: %dX mu %d - %dX mu %d", b.heso, b.somu, a.heso, a.somu);
		else
			printf ("\ntru la: %dX mu %d - %dX mu %d", a.heso, a.somu, b.heso, b.somu);
	}
}

donThuc nhanHaiDonThuc( donThuc a, donThuc b)
{
	donThuc temp;
	if (a.heso == 0 || b.heso == 0)
	{
		temp.heso = 0;
		temp.somu = 0;
	}
	else
	{
		temp.heso = a.heso * b.heso;
		temp.somu = a.somu + b.somu;
		return temp;
	}
}

donThuc chiaHaiDonThuc( donThuc a, donThuc b)
{
	donThuc temp;
	if (a.heso == 0)
	{
		temp.heso = 0;
		temp.somu = 0;
	}
	else
	{
		temp.heso = a.heso * b.heso;
		temp.somu = a.somu - b.somu;
		return temp;
	}
}
int main()
{
	donThuc a, b;
	nhap(a, b);
	congHaiDonThuc(a, b);
	truHaiDonThuc(a, b);
	donThuc k = nhanHaiDonThuc(a, b);
	printf ("\nNhan la: %dX mu %d", k.heso, k.somu);
	donThuc t = chiaHaiDonThuc(a, b);
	printf ("\nChia la: %dX mu %d", t.heso, t.somu);
}


