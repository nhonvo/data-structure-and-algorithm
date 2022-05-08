#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


struct node{
	int data;
	node* left;
	node* right;
};
typedef struct node* tree;

void Init(tree & root);
int IsEmpty(tree root);
tree CreateNode(int x);
void InsertNode(tree &root , int x);
void CreateTree(tree &root);
int Remove(tree &root,int x);
void cleartree(tree root);
void LNR(tree root);
void RNL(tree root);
int Check_Dung(node *root,int &Max);
bool Check_Daydu(tree root);
tree TimChaX(tree root, int x);

int main()
{
	tree root;
	Init(root);
	
	int n, dem=0;
	do
	{
		system("cls");
		printf("CHUONG TRINH CAY NHI PHAN TIM KIEM\n");
		printf("\n*************************************************");
		printf("\n* 1/ Nhap du lieu cho cay nhi phan              *");
		printf("\n* 2/ Xuat cay nhi phan tang dan                 *");
		printf("\n* 3/ Xuat cay nhi phan giam dan                 *");
		printf("\n* 4/ Xoa node x tren cay                        *");
		printf("\n* 5/ Xoa toan bo cay                            *");
		printf("\n* 6/ Kiem tra xem co phai cay nhi phan day du   *");
		printf("\n* 7/ Kiem tra xem co phai cay nhi phan dung     *");
		printf("\n* 8/ Tim node cha cua node x                    *");
		printf("\n* 0/ Thoat chuong trinh                         *");
		printf("\n*************************************************");

		printf("\nChon chuc nang n: ");scanf("%d", &n);
		switch(n)
		{
			case 1:
			{
				printf("\n");
				printf("Nhap du lieu cho cay nhi phan\n");
				CreateTree(root);
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 2:
			{
				printf("\nXuat cay nhi phan tang dan\n");
				LNR(root);
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 3:
			{
				printf("\n 3/ Xuat cay nhi phan giam dan\n");
				RNL(root);
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 4:
			{
				printf("\n 4/ Xoa node x tren cay nhi phan\n");
				int cau4;
				printf("\nNhap nut x can xoa: "); scanf("%d", &cau4);
				if(Remove(root,cau4) == 1)
					printf("\nDa xoa thanh cong");
				else
					printf("\nChua xoa duoc");
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 5:
			{
				printf("\n5/ Xoa toan bo cay: \n");
				cleartree(root);
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 6:
			{
				printf("\n6/ Kiem tra xem co phai cay nhi phan day du\n");
				if(Check_Daydu(root))
					printf("\nDung la cay nhi phan DAY DU");
				else
					printf("\nKhong phai cay nhi phan DAY DU");
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 7:
			{
				printf("\n7/ Kiem tra xem co phai cay nhi phan dung\n");
				int max = -10000;
				if(Check_Dung(root,max))
					printf("\nLa cay nhi phan dung.");
				else
					printf("\nLa cay nhi phan dung");
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
			case 8:
			{
				printf("\n8/ Tim node cha cua node x\n");
				int cau8;
				printf("\nNhap gia tri node x: "); scanf("%d", &cau8);
				tree p = TimChaX(root,cau8);
				if(p == NULL)
					printf("\nNode khong co cha.");
				else
					printf("\nCha cua node %d la: %d",cau8,p->data);
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();
				break;
			}
	
			case 0:
			{
				printf("\n  Cam on da su dung chuong trinh cua chung toi!");
				printf("\nNhap phim bat ky de tiep tuc!!!");
				getch();	
				return 0;
			}								
			default:printf("Lua chon trong 0-9!! ");
			printf("\nNhan phim bat ki de tiep tuc!");
			getch();
		}
	}while(n!=0);
	return 0;
}

void Init(tree & root)
{
	root = NULL;
}
int IsEmpty(tree root)
{
	return root == NULL;
}
tree CreateNode(int x)
{
	tree p = new node;
	p->data = x;
	p->left=p->right=NULL;
	return p;
}
void InsertNode(tree &root , int x)
{
	if(IsEmpty(root))
	{
		root = CreateNode(x);
		return;
	}
	else
	{
		if(root->data==x)
			return;
		else if(root->data >x)
			InsertNode(root->left, x);
		else
			InsertNode(root->right,x);
	}
}
void CreateTree(tree &root)
{
	int x, n;
	printf("Nhap so luong node: "); scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap gia tri cho node %d: ", i); scanf("%d", &x);
		InsertNode(root, x);
	}
}

int Remove(tree &root,int x)
{
    if(root==NULL)
        return 0;
    if(root->data>x)
        return Remove(root->left,x);
    if(root->data<x)
        return Remove(root->right,x);
    node *p,*f,*rp;
    p=root;
    if(root->left==NULL)
    {
        root = root->right;
        delete p;
    }
    else if(root->right==NULL)
    {
        root = root->left;
        delete p;
    }
    else
    {
        f = p;
        rp = p->right;
		//tim node the mang trai nhat cua cay con phai
        while(rp->left!=NULL)
        {
            f = rp;
            rp = rp->left;
        }
        p->data = rp->data;
        //gan gia tri = node the mang
        if(f==p)
            p->right = rp->right;
        else
            f->left = rp->right;
        delete rp;
    }
    return 1;
}

void cleartree(tree root)
{
	if(root!=NULL)
	{
		cleartree(root->left);
		cleartree(root->right);
		delete root;
	}
}
//tang dan
void LNR(tree root)
{
	if(!IsEmpty(root))
	{
		LNR(root->left);
		printf("%d ",root->data);
		LNR(root->right);
	}
	else
		return;
}
//giam dan
void RNL(tree root)
{
	if(!IsEmpty(root))
	{
		RNL(root->right);		
		printf("%d ", root->data);
		RNL(root->left);
	}
	else
		return;
}
//Thu tu dung lon hon nhanh ben trai va nho hon nhanh ben phai || chi can maximum
// luc nao cac node cung lon hon max nen h�m khong the sai
int Check_Dung(node *root,int &Max)
{
    if(IsEmpty(root))
		return 1;
    int x=Check_Dung(root->left,Max);
    if(!x)
		return 0;
    if(Max>root->data) 
		return 0;
	Max = root->data;
    return Check_Dung(root->right,Max);
}

//Cay day du la cay co du 2 con 
bool Check_Daydu(tree root)
{
	if (root == NULL)
    return true;

  	if (root->left == NULL && root->right == NULL)
    	return true;

 	if ((root->left) && (root->right))
    	return (Check_Daydu(root->left) && Check_Daydu(root->right));
  	return false;
}

tree TimChaX(tree root, int x)
{
    if(IsEmpty(root))
		return NULL;
    if(!IsEmpty(root->left)&&root->data>x)
//    duyet dan sang ben trai den node can tim thi dung lai roi xuat ra node cha, Tuong tu o duoi
    {
        if(root->left->data==x)
//        dung tai node cha can tim nhung tro gia tri den node con tiep theo
			return root;
        return TimChaX(root->left,x);
    }
    if(!IsEmpty(root->right)&&root->data<x)
    {
        if(root->right->data==x)
			return root;
        return TimChaX(root->right,x);
    }
    return NULL;
}
