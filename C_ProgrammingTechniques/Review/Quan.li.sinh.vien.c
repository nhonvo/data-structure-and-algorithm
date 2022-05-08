#include<stdio.h>
#include<string.h>
#include <conio.h>
struct taotaikhoan														
{
	char taikhoan[100];
	char matkhau[100];
};

struct dangnhap
{
	char taikhoan[100];
	char xacnhan[100];
};

struct sinhvien
{
	char hoten[30];
	char masv[20];
	char tienganh[100];
	char gioitinh[20];
	char khoahoc[100];
	char nganh[100];
	float c;
	float thinghiem1;
	float thinghiem2;
	float antoan;
	float toan;
	float gdtc;
	float gdqp;
	float thuctap;
	int moss;
	char passmoss[20];
	char passgdqp[20];
	char passgdtc[20];
	
};
struct timthongtin 
{
 char timkiemmasv[20];
};
struct mamonhoc
{
	char gdtc;
	char gdqp;
	char toan[6];
	char c;
	char thinghiem1;
	char thinghiem2;
	char antoan;
	char thuctap;
};
void khoitao(void);
void dangki(void);
void banglevel(void);
void nhapthongtin(void);
void nhapdiem(void);
void bangdiem(void);
void trungbinh(void);
void trungbinh8(void);
void datmonhoc(void);
void quamon(void);
void dungtiendo(void);
void tretiendo(void);
void timkiemthongtin(void);
void thongkediem(void);
void thoatCT(void);

int n;
int main () 
{
	int mucluc;
	khoitao();
	do
	{
		printf("\n");
		printf("\t Chao mung den voi chuong trinh quan ly sinh vien khoa Dien - Dien Tu \n");
		printf("\t\t\t    ออออออออออo0oอออออออออออ");
		printf("\n");
		printf("\n");
		printf("\t			  MENU CUA CHUONG TRINH");
		printf("\n   	  	    ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n   		    บ 1.Dang nhap va nhap si so                              บ");
		printf("\n   		    บ 2.Bang level tieng anh                                 บ");
		printf("\n   		    บ 3.Nhap thong tin sinh vien                             บ");
		printf("\n   		    บ 4.Nhap diem mon hoc cua sinh vien                      บ");
		printf("\n   		    บ 5.Nhap nhung sinh vien dat mon hoc moss 2,gdqp,gdtc    บ");
		printf("\n   		    บ 6.Bang diem hoc tap cua sinh vien                      บ");
		printf("\n   		    บ 7.Diem trung binh cua sinh vien                        บ");
		printf("\n   		    บ 8.Danh sach sinh vien diem trung binh 8.0              บ");
		printf("\n   		    บ 9.Danh sach sinh vien dat moss 2,gdqp,gdtc             บ");
		printf("\n   		    บ 10.Danh sach sinh vien dat dung tien do tieng anh      บ");
		printf("\n   		    บ 11.Danh sach sinh vien khong dat dung tien do tieng anhบ");
		printf("\n   		    บ 12.Tim kiem thong tin sinh vien                        บ");
		printf("\n   		    บ 13.Tim kiem diem sinh vien                             บ");
		printf("\n   		    บ 14.Thoat chuong trinh                                  บ");
		printf("\n   		    ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
		printf("\n");
		printf("Moi ban nhap 1 so tu Menu chuong trinh: ");
		scanf("%d",&mucluc);
		printf("\n");
	switch (mucluc)
		{
			case 1: dangki();
					break;
			case 2: banglevel();
					break;		
			case 3: nhapthongtin();
					break;
			case 4: nhapdiem();
					break;
			case 5: datmonhoc();
					break;	
			case 6:	bangdiem();
					break;		
		    case 7: trungbinh();
		    		break;
			case 8:	trungbinh8();
					break;		
			case 9:	quamon();	
					break;	
			case 10:dungtiendo();
					break;
			case 11:tretiendo();
					break;	
			case 12:timkiemthongtin();
					break;
			case 13:thongkediem();
			     	break;		
			case 14:{
						thoatCT();
						return 0;
					}								
			default:printf("Lua chon trong 1-14! ");
			getch();
		}
	printf("\n");	
	}while (1);
}
void khoitao()
{
	n=0;
}
void dangki(void)
{	
	struct taotaikhoan tk;
	struct dangnhap dn;
	printf("  Hay Dang ki tai khoan truoc nhe!");
	printf("\n     ออออออออออo0oอออออออออออ");
	printf("\n");
	printf("Tai khoan ban muon tao: ");fflush(stdin);
	gets(tk.taikhoan);
	while (strlen(tk.taikhoan)==0)
	{
		printf("\tKhong duoc bo trong...!\n");
		getch();
		printf("\tMoi ban nhap tai khoan: ");fflush(stdin);
		gets(tk.taikhoan);
	}
	printf("Mat khau ban muon tao: ");fflush(stdin);
	gets(tk.matkhau);
	while (strlen(tk.matkhau)==0)
	{
		printf("\tKhong duoc bo trong...!\n");
		getch();
		printf("\tMoi ban nhap mat khau: ");fflush(stdin);
		gets(tk.matkhau);
	}
	printf("Hay xac nhan lai mat khau: ");fflush(stdin);
	gets(dn.xacnhan);
	while (strlen(dn.xacnhan)==0)
	{
		printf("\tKhong duoc bo trong...!\n");
		getch();
		printf("\tMoi ban xac nhan mat khau: ");fflush(stdin);
		gets(dn.xacnhan);
	}
	while (strcmp(tk.matkhau,dn.xacnhan)!=0)
	{
		printf("\tMat khau cua ban khong khop vui long kiem tra lai....!\n ");
		getch();
		printf("\tHay xac nhan lai mat khau: ");fflush(stdin);
		gets(dn.xacnhan);
	}
	getch();
	printf("\n   	  	    ษออออออออออออออออออออออออออออออออป");
	printf("\n   		    บ       Dang Ki thanh cong       บ");
	printf("\n   		    ศออออออออออออออออออออออออออออออออผ");
	printf("\n");
	printf("  Hay dang nhap vao chuong trinh");
	printf("\n    ออออออออออo0oอออออออออออ");
	printf("\n");	
	printf("Tai khoan: ");fflush(stdin);
	gets(dn.taikhoan);
	do
	{
		if (strcmp(tk.taikhoan,dn.taikhoan)!=0)
		{
			printf("\tTai khoan dang nhap khong hop le...!\n");
			getch();
			printf("\tNhap lai tai khoan: ");fflush(stdin);
			gets(dn.taikhoan);
		}
	}while(strcmp(tk.taikhoan,dn.taikhoan)!=0);
 	printf("Mat khau: ");fflush(stdin);
	gets(tk.matkhau);
	while (strcmp(tk.matkhau,dn.xacnhan)!=0 )
	{
		printf("\tDang nhap khong hop le!\n");
		printf("\tMoi ban nhap lai mat khau....!\n");
		getch();
		printf("\tHay nhap lai mat khau: ");fflush(stdin);
		gets(tk.matkhau);
	}
	printf("\n   	  	    ษออออออออออออออออออออออออออออออออป");
	printf("\n   		    บ     Dang nhap thanh cong       บ");
	printf("\n   		    ศออออออออออออออออออออออออออออออออผ");
	getch();
	printf("\n");
	printf("Nhap si so sinh vien:");
	scanf("%d",&n);
	do
	{
		if (n<=0)
		{
			printf("Nhap lai si so sinh vien: ");
			scanf("%d",&n);
		}
	}while(n<=0);
	printf("Chuc mung ban da hoan tat....!");
	getch();
}
void nhapthongtin(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
struct sinhvien sv[100];int i;
	for (i=0;i<n;i++)
	{
		printf("\n");
		printf("\tHay nhap thong tin cua sinh vien\n");
		printf("\t  ออออออออออo0oอออออออออออ");
		getch();
		printf("\n");
 		printf("Nhap ho va ten sinh vien thu %d: ",i+1);fflush(stdin);
 		gets(sv[i].hoten);
 		while (strlen(sv[i].hoten)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap ho va ten: ");fflush(stdin);
			gets(sv[i].hoten);
		}
		printf("Nhap ma so sinh vien thu %d: ",i+1);fflush(stdin);
		gets(sv[i].masv);
		while (strlen(sv[i].masv)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap ma sv: ");fflush(stdin);
			gets(sv[i].masv);
		}
		printf("Gioi tinh cua sinh vien thu %d: ",i+1);fflush(stdin);
		gets(sv[i].gioitinh);
		while (strlen(sv[i].gioitinh)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap gioi tinh: ");fflush(stdin);
			gets(sv[i].gioitinh);
		}
		printf("Trinh do tieng anh hien tai sinh vien thu %d: ",i+1);fflush(stdin);
		gets(sv[i].tienganh);
		while (strlen(sv[i].tienganh)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap tieng anh: ");fflush(stdin);
			gets(sv[i].tienganh);
		}
		printf("Khoa hoc hien tai cua sinh vien thu %d: ",i+1);fflush(stdin);
		gets(sv[i].khoahoc);
		while (strlen(sv[i].khoahoc)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap khoa hoc: ");fflush(stdin);
			gets(sv[i].khoahoc);
		}
		printf("Nganh cua sinh vien thu %d: ",i+1);fflush(stdin);
		gets(sv[i].nganh);
		while (strlen(sv[i].nganh)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap nganh: ");fflush(stdin);
			gets(sv[i].nganh);
		}
		
	}	
}
void banglevel(void)
{
		printf("\t                         LUU Y");
		printf("\n   	  	    ษอออออออออออออออออออออออออออออออออออออออออออป");
		printf("\n   		    บTREN HOAC BANG TIENG ANH 3 LA DUNG TIEN DO บ");
		printf("\n   		    ศอออออออออออออออออออออออออออออออออออออออออออผ");
		printf("\n");
		printf("\n   	  	    ษออออออออออออออป");
		printf("\n   		    บ 1.DU BI 1    บ");
		printf("\n   		    บ 2.DU BI 2    บ");
		printf("\n   		    บ 3.DU BI 3    บ");
		printf("\n   		    บ 1.TIENG ANH 1บ");
		printf("\n   		    บ 2.TIENG ANH 2บ");
		printf("\n   		    บ 3.TIENG ANH 3บ");
		printf("\n   		    บ 4.TIENG ANH 4บ");
		printf("\n   		    บ 5.TIENG ANH 5บ");
		printf("\n   		    บ 6.TIENG ANH 6บ");
		printf("\n   		    ศออออออออออออออผ");
		getch();
}
void nhapdiem(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	struct sinhvien sv[100];int i;
	for (i=0;i<n;i++)
	{
		printf("\n");
		printf("\t%s\n",sv[i].hoten);
		printf("Diem gdtc: ");fflush(stdin);
		scanf("%f",&sv[i].gdtc);
		while (sv[i].gdtc<0 || sv[i].gdtc>10)
		{
			printf("Diem gdtc phai lon hon 0 va nho hon 10...!");
			getch();
			printf("Nhap lai diem gdtc: ");fflush(stdin);
			scanf("%f",&sv[i].gdtc);
		}
		printf("Nhap diem Toan1E2: ",sv[i].toan);fflush(stdin);
		scanf("%f",&sv[i].toan);
		while(sv[i].toan<0 || sv[i].toan>10)
		{
			printf("Diem Toan phai lon hon 0 va nho hon 10...!");
			getch();
			printf("Nhap lai diem Toan1E2: ");fflush(stdin);
			scanf("%f",&sv[i].toan);
		}
		printf("Nhap diem An toan dien: ");fflush(stdin);
		scanf("%f",&sv[i].antoan);
	while(sv[i].antoan<0 || sv[i].antoan>10)
		{
			printf("Diem An Toan Dien phai lon hon 0 va nho hon 10...!");
			getch();
			printf("Nhap lai diem An Toan Dien: ");fflush(stdin);
			scanf("%f",&sv[i].antoan);
		}
		printf("Nhap diem Gdqp: ");fflush(stdin);
		scanf("%f",&sv[i].gdqp);
		while(sv[i].gdqp<0 || sv[i].gdqp>10)
		{
			printf("Diem Gdqp phai lon hon 0 va nho hon 10...!");fflush(stdin);
			getch();
			printf("Nhap lai diem Gdqp: ");fflush(stdin);
			scanf("%f",&sv[i].gdqp);
		}
		printf("Nhap diem Thi nghiem dien tu: ");fflush(stdin);
		scanf("%f",&sv[i].thinghiem1);
		while(sv[i].thinghiem1<0 || sv[i].thinghiem1>10)
		{
			printf("Diem Thi nghiem dien tu phai lon hon 0 va nho hon 10...!");fflush(stdin);
			getch();
			printf("Nhap lai diem Thi nghiem dien tu: ");fflush(stdin);
			scanf("%f",&sv[i].thinghiem1);
		}
		printf("Nhap diem Thi nghiem mach dien: ");fflush(stdin);
		scanf("%f",&sv[i].thinghiem2);
		while(sv[i].thinghiem2<0 || sv[i].thinghiem2>10)
		{
			printf("Diem Thi nghiem mach dien phai lon hon 0 va nho hon 10...!");fflush(stdin);
			getch();
			printf("Nhap lai diem Thi nghiem mach diem: ");fflush(stdin);
			scanf("%f",&sv[i].thinghiem2);
	    }
	    printf("Nhap diem Thuc tap dien: ");fflush(stdin);
	    scanf("%f",&sv[i].thuctap);
	    while(sv[i].thuctap<0 || sv[i].thuctap>10)
	    {
	    	printf("Diem Thuc tap dien phai lon hon 0 va nho hon 10...!");fflush(stdin);
	    	getch();
	    	printf("Nhap lai diem Thuc tap dien: ");fflush(stdin);
	    	scanf("%f",&sv[i].thuctap);
	    }
	    printf("Nhap diem Moss 2: ");fflush(stdin);
		scanf("%d",&sv[i].moss);
	while(sv[i].moss<100 || sv[i].moss>1000)
		{
			printf("Diem moss 2 phai lon hon 100 va nho hon 1000...!");fflush(stdin);
			getch();
			printf("Nhap lai diem moss 2: ");
			scanf("%d",&sv[i].moss);
		}
		printf("Nhap diem C: ");fflush(stdin);
		scanf("%f",&sv[i].c);
		while(sv[i].c<0 || sv[i].c>10)
		{
			printf("Diem C phai lon hon 0 va nho hon 10...!");fflush(stdin);
			getch();
			printf("Nhap lai diem C: ");fflush(stdin);
			scanf("%f",&sv[i].c);
		}
	}
}	

void bangdiem(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	struct sinhvien sv[100];int i; 
	printf("\n\t                BANG DIEM HOC TAP KHOA DIEN - DIEN TU ");
	printf("\n	 ษอออออออออออัอออออออออออออออออัอออออออออออออออัออออออออออัออออออออออออออป");
   	printf("\n	 บ  MaSV     ณ     Ten SV      ณ  An toan dien ณ Toan 1E2 ณ  Lap trinh C บ");
   for (i=0;i<n;i++)
	{
	printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	printf("\n	 บ%11sณ%17sณ%15.2fณ%10.2fณ%14.2fบ",sv[i].masv,sv[i].hoten,sv[i].antoan,sv[i].toan,sv[i].c);
	}
   	printf("\n	 ศอออออออออออฯอออออออออออออออออฯอออออออออออออออฯออออออออออฯออออออออออออออผ");
   	printf("\n");
	printf("\n\t            BANG DIEM HOC TAP MON GDQP VA GDTC KHOA DIEN - DIEN TU ");
	printf("\n	 ษอออออออออออัอออออออออออออออออัออออออออออออออออออออออัอออออออออออออออออออออออออป");
   	printf("\n	 บ  MaSV     ณ     Ten SV      ณ  Giao duc quoc phong ณ    Giao duc the chat    บ");
   for (i=0;i<n;i++)
   
	{
	printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	printf("\n	 บ%11sณ%17sณ%22.2fณ%25.2fบ",sv[i].masv,sv[i].hoten,sv[i].gdqp,sv[i].gdtc);
	}
   	printf("\n	 ศอออออออออออฯอออออออออออออออออฯออออออออออออออออออออออฯอออออออออออออออออออออออออผ");
   	printf("\n");
   	printf("\n\t                    BANG DIEM CAC MON THUC HANH KHOA DIEN - DIEN TU ");
	printf("\n	 ษอออออออออออัอออออออออออออออออัอออออออออออออออออออออออัอออออออออออออออออออัออออออออออออออออป");
   	printf("\n	 บ  MaSV     ณ     Ten SV      ณ  Thi nghiem mach dien ณ Thi nghiem dien tuณ Thuc tap dien  บ");
   for (i=0;i<n;i++)
	{
	printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	printf("\n	 บ%11sณ%17sณ%23.2fณ%19.2fณ%16.2fบ",sv[i].masv,sv[i].hoten,sv[i].thinghiem1,sv[i].thinghiem2,sv[i].thuctap);
	
	}
   	printf("\n	 ศอออออออออออฯอออออออออออออออออฯอออออออออออออออออออออออฯอออออออออออออออออออฯออออออออออออออออผ");
   	getch();
}
void trungbinh(void)
{
		if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	float trungbinh;
	struct sinhvien sv[100];int i; 
		printf("\n\t       BANG DIEM TRUNG BINH KHOA DIEN - DIEN TU ");
		printf("\n	 ษอออออออออออัอออออออออออออออออัออออออออออออออออออป");
   		printf("\n	 บ  MaSV     ณ     Ten SV      ณ Diem trung binh  บ");
   for (i=0;i<n;i++)
	{
		trungbinh=(sv[i].antoan+sv[i].c+sv[i].thinghiem1+sv[i].thinghiem2+sv[i].thuctap+sv[i].toan)/6;
		printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
		printf("\n	 บ%11sณ%17sณ%18.2fบ",sv[i].masv,sv[i].hoten,trungbinh);
	}
		printf("\n	 ศอออออออออออฯอออออออออออออออออฯออออออออออออออออออผ");
   	getch();
}
void trungbinh8()
{
	
		if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	float trungbinh;
	struct sinhvien sv[100];int i; 
			printf("\n\t     DANH SACH SINH VIEN 8.0 KHOA DIEN - DIEN TU ");
			printf("\n	 ษอออออออออออัอออออออออออออออออัออออออออออออออออออป");
   			printf("\n	 บ  MaSV     ณ     Ten SV      ณ Diem trung binh  บ");
   for (i=0;i<n;i++)
	{
		trungbinh=(sv[i].antoan+sv[i].c+sv[i].thinghiem1+sv[i].thinghiem2+sv[i].thuctap+sv[i].toan)/6;
		if (trungbinh>=8)
		{
			printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
			printf("\n	 บ%11sณ%17sณ%18.2fบ",sv[i].masv,sv[i].hoten,trungbinh);
		}
	}
			printf("\n	 ศอออออออออออฯอออออออออออออออออฯออออออออออออออออออผ");
   	getch();
}
void datmonhoc(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	printf("\t                         LUU Y");
		printf("\n   	  	    ษอออออออออออออออออออออออออออป");
		printf("\n   		    บ + Diem Moss 2 phai >= 500 บ");
		printf("\n   		    บ + Diem GDQP phai >=5      บ");
		printf("\n   		    บ + Diem GDTC phai >=5      บ");
		printf("\n   		    ศอออออออออออออออออออออออออออผ");
		printf("\n");
	struct sinhvien sv[100];int i; 
	for (i=0;i<n;i++)
	{
		printf("\n");
		printf("\t%s\n",sv[i].hoten);
		printf("\n");
		printf("Diem mon moss 2: %d\n ",sv[i].moss);
		printf("Sinh vien dat hay khong dat: ");fflush(stdin);
		gets(sv[i].passmoss);
		while (strlen(sv[i].passmoss)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap dat hay khong dat: ");fflush(stdin);
			gets(sv[i].passmoss);
		}
		printf("\n");
		printf("Diem mon GDQP:  %0.2f\n ",sv[i].gdqp);
		printf("Sinh vien dat hay khong dat: ");fflush(stdin);
		gets(sv[i].passgdqp);
		while (strlen(sv[i].passgdqp)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap dat hay khong dat: ");fflush(stdin);
			gets(sv[i].passgdqp);
		}
		printf("\n");
		printf("Diem mon GDTC: %0.2f\n ",sv[i].gdtc);
		printf("Sinh vien dat hay khong dat: ");fflush(stdin);
		gets(sv[i].passgdtc);
		while (strlen(sv[i].passgdtc)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap dat hay khong dat: ");fflush(stdin);
			gets(sv[i].passgdtc);
		}
	}
	getch();
}
void quamon(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	struct sinhvien sv[100];int i; 
	printf("\n\t         DANH SACH SINH VIEN DAT MOSS 2, GDTC, GDQP ");
	printf("\n	 ษอออออออออออัอออออออออออออออออัออออออออออัอออออออออัอออออออออป");
   	printf("\n	 บ  MaSV     ณ     Ten SV      ณ   GDQP   ณ   GDTC  ณ  Moss 2 บ");
   for (i=0;i<n;i++)
	{
	
	printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤถ");
	printf("\n	 บ%11sณ%17sณ%10sณ%9sณ%9sบ",sv[i].masv,sv[i].hoten,sv[i].passgdqp,sv[i].passgdtc,sv[i].passmoss);
	}
   	printf("\n	 ศอออออออออออฯอออออออออออออออออฯออออออออออฯอออออออออฯอออออออออผ");
   	getch();
}
void dungtiendo(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	struct sinhvien sv[100];int i;
	char s[]="tieng anh 3";
	printf("\t\tDANH SACH SINH VIEN DAT DUNG TIEN DO TIENG ANH");
	printf("\n");
	for (i=0;i<n;i++)
	{
		if (strcmp(sv[i].tienganh,s)==1 || strcmp(sv[i].tienganh,s)==0)
		{
			printf("\t%s\n",sv[i].hoten);
		}

	}
	getch();
}
void tretiendo(void)
{
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	struct sinhvien sv[100];int i;
	char s[]="tieng anh 3";
	printf("\t\tDANH SACH SINH VIEN KHONG DAT DUNG TIEN DO TIENG ANH");
	printf("\n");
	for (i=0;i<n;i++)
	{
		if (strcmp(sv[i].tienganh,s)==-1 )
		{
			printf("\t%s\n",sv[i].hoten);
		}

	}
	getch();
}
void timkiemthongtin(void)
{   
	
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan.....!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	printf("\n   	  	    ษออออออออออออออออออออออออออออออออป");
	printf("\n   		    บ     Thong tin cua sinh vien    บ");
	printf("\n   		    ศออออออออออออออออออออออออออออออออผ");
	struct sinhvien sv[100]; 
	printf("\n\t           MA SV BAN DA NHAP");
	printf("\n	 ษอออออออออออออออออัอออออออออออออออออออป");
	printf("\n	 บ     Ten SV      ณ Ma SV ban da nhap บ");
	int i;
	for (i=0;i<n;i++)
	{
	printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	printf("\n	 บ%17sณ%19sบ",sv[i].hoten,sv[i].masv);
	}
   	printf("\n	 ศอออออออออออออออออฯอออออออออออออออออออผ");
	getch();
	printf("\n");
	struct timthongtin checkmasv;
	int timkiem,mucluc;
	printf("\n");
		printf("Moi ban nhap ma sv de tim kiem: ");fflush(stdin);
		gets(checkmasv.timkiemmasv);
		while (strlen(checkmasv.timkiemmasv)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap ma sv de tim kiem: ");fflush(stdin);
			gets(checkmasv.timkiemmasv);
		}
	for (i=0;i<n;i++)
	{	
		if (strcmp(checkmasv.timkiemmasv,sv[i].masv)==0)
		{
			printf("Ho va ten: %s\n",sv[i].hoten);
			printf("Ma sv: %s\n",sv[i].masv);
			printf("Gioi tinh: %s\n",sv[i].gioitinh);
			printf("Level tieng anh: %s\n",sv[i].tienganh);
			printf("Khoa hoc: %s\n",sv[i].khoahoc);
			printf("Nganh: %s\n",sv[i].nganh);
		}
	}
	getch();
}
void thongkediem(void)
{
		
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan.....!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	if (n==0) 
	{
	  printf("\t\t Ban chua dang nhap tai khoan.....!\n");
	  getch();
	  printf("\t\t Nhan vao so 1 de tao tai khoan va dang nhap nhe....!");
	  getch();
	}
	printf("\n   	  	    ษออออออออออออออออออออออออออออออออป");
	printf("\n   		    บ       Diem cua sinh vien       บ");
	printf("\n   		    ศออออออออออออออออออออออออออออออออผ");
	struct sinhvien sv[100]; 
	printf("\n\t           MA SV BAN DA NHAP");
	printf("\n	 ษอออออออออออออออออัอออออออออออออออออออป");
	printf("\n	 บ     Ten SV      ณ Ma SV ban da nhap บ");
	int i;
	for (i=0;i<n;i++)
	{
	printf("\n	 วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	printf("\n	 บ%17sณ%19sบ",sv[i].hoten,sv[i].masv);
	}
   	printf("\n	 ศอออออออออออออออออฯอออออออออออออออออออผ");
	getch();
	printf("\n");
	struct timthongtin checkmasv;
	int timkiem,mucluc;
	printf("\n");
		printf("Moi ban nhap ma sv de tim kiem: ");fflush(stdin);
		gets(checkmasv.timkiemmasv);
		while (strlen(checkmasv.timkiemmasv)==0)
 		{
 			printf("\tKhong duoc bo trong...!\n");
			getch();
			printf("\tMoi ban nhap ma sv de tim kiem: ");fflush(stdin);
			gets(checkmasv.timkiemmasv);
		}
	for (i=0;i<n;i++)
	{	
		if (strcmp(checkmasv.timkiemmasv,sv[i].masv)==0)
		{
			printf("\n");
			printf("\t%s\n",sv[i].hoten);
			printf("GDTC: %0.2f\n",sv[i].gdtc);
			printf("Toan 1E2: %0.2f\n",sv[i].toan);
			printf("An toan dien: %0.2f\n",sv[i].c);
			printf("GDQP: %0.2f\n",sv[i].gdqp);
			printf("Thi nghiem dien tu: %0.2f\n",sv[i].thinghiem1);
			printf("Thi nghiem mach dien: %0.2f\n",sv[i].thinghiem2);
			printf("Thuc tap dien: %0.2f\n",sv[i].thuctap);
			printf("Moss 2: %0.2f\n",sv[i].moss);
			printf("Lap trinh C: %0.2f\n",sv[i].c);
		}
	
	}
	getch();
}
void thoatCT(void)
{
   
   printf("\n");
   printf("\n  Cam on da su dung chuong trinh cua chung toi!");
   
   getch();
}

	

