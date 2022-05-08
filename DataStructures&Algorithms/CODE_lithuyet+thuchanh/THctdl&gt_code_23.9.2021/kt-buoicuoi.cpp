#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
typedef struct  node* tree;

void Init(tree &p)
{
	p=NULL;
}
int empty(tree p)
{
	return p == NULL;
}
tree createnode(int x)
{
	tree p= new node;
	p->data =x;
	p->right = p->left =NULL;
	return p;
}
void insertnode(tree &p, int x)
{
	if(!empty(p))
	{
		if(p->data == x) return ;
		if(p->data > x)
			insertnode(p->left, x);
		else
			insertnode(p->right, x);
	}
	else
		p = createnode(x);
}
void createtree(tree &root)
{
	int x,n;
	cout<<"Nhap so node: "; cin>>n;
	for(int i = 1; i<=n; i++)
	{
		cout<<"\nNhap gia tri node: "; cin>>x;
		insertnode(root, x);
	}
}
void NLR(tree root)
{
	if(!empty(root))
	{
		cout<<root->data<<" ";
		NLR(root->left);
		NLR(root->right);
	}
}
//tang dan
void LNR(tree root)
{
	if(!empty(root))
	{
		LNR(root->left);
		cout<<root->data<<" ";
		LNR(root->right);
	}
}
//giam dan
void RNL(tree root)
{
	if(!empty(root))
	{
		RNL(root->right);		
		cout<<root->data<<" ";
		RNL(root->left);
	}
}
void LRN(tree root)
{
	if(!empty(root))
	{
		LRN(root->left);		
		LRN(root->right);
		cout<<root->data<<" ";
	}
}
void insert(tree &root, int x)
{
	tree p;
	if(empty(root)) 
		root = createnode(x);
	else
		if(x==root->data) return;
		if(x>root->data) 
			insert(root->right,x);
		else
			insert(root->left,x); 
}
void remove(tree &root, int x)
{
	if(root == NULL) 
		return ;
	if(root->data <x) 
		remove(root->right, x);
	if(root->data >x) 
		remove(root->left,  x);
	tree p,f,rp;
	p = root;
	if(root->left == NULL)
		root = root->right;
	else if(root->right == NULL)
		root = root->left;
	else
	{
		f = p;
		rp = p->right;
		while(rp->left != NULL)
		{
			f = rp;
			rp = rp->left;
		}
		p->data = rp->data;
		if (f==p) 
			f->right = rp->right;
		else 
			f->left = rp->right;
		p = rp;
	}
	delete p;
}

node *timchax(node *ptree,int x)
{
    if(empty(ptree))
		return NULL;
    node *p=ptree->left,*q=ptree->right;
    if(q->data==x||p->data==x)
		return ptree;
    node *e=timchax(ptree->left,x);
    if(empty(e))
        e=timchax(ptree->right,x);
    return e;
}
int treeDepth(node* p, int &max, int d)
{
	if (p==NULL)
		return max;
	
	d++;
	treeDepth(p->left,max,d);
	max = d; d=0; d++;
	treeDepth(p->right,max,d);
	if (d>max) 
		max = d;
	return max;
}
int GTNN(tree root)
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}

int GTLN(tree root)
{
    while ( root->right != NULL )
        root = root->right;
    return root->data;
}
int Tong(tree root)
{
	if(empty(root)) return 0;
	int l = Tong(root->left);
	int r = Tong(root->right);
	return l + r + root->data;
}
int main()
{
	tree root;
	Init(root);
	
	int n, dem=0;
	do
	{
		system("cls");
		cout<<"CHUONG TRINH CAY NHI PHAN TIM KIEM\n";
		cout<<"\n*********************************************";
		cout<<"\n* 1/ Nhap du lieu cho cay nhi phan          *";
		cout<<"\n* 2a.1/ Xuat cay nhi phan tang dan          *";
		cout<<"\n* 3a.2/ Xuat cay nhi phan giam dan          *";
		cout<<"\n* 4d/ Xac dinh nut cha cua nut chua khoa x  *";
		cout<<"\n* 5f/ Xac dinh do sau,chieu cao cua cay     *";
		cout<<"\n* 6g/ Tim gia tri nho nhat/lon nhat tren cay*";
		cout<<"\n* 7h/ Tinh tong cac gia tri tren cay        *";
		cout<<"\n* 0/ Thoat chuong trinh                     *";
		cout<<"\n*********************************************";

		cout<<"\nChon chuc nang n: ";cin>>n;
		switch(n)
		{
			case 1:
			{
				cout<<"\n";
				cout<<"Nhap du lieu cho cay nhi phan"<<endl;
				createtree(root);
				getch();
				break;
			}
			case 2:
			{
				cout<<"\n";				
				cout<<"Xuat cay nhi phan tang dan"<<endl;
				LNR(root);
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();
				break;
			}
			case 3:
			{
				cout<<"\n";
				cout<<"Xuat cay nhi phan giam dan"<<endl;
				RNL(root);
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();
				break;
			}
			case 4:
			{
				cout<<"\n";
				LRN(root);
				cout<<"Nut cha cua nut khoa chua x: ";
				int cau4;
				cout<<"\nNhap du lieu phan tu can tim father node: "; cin>>cau4;
				node* k=timchax(root,cau4);
				cout<<"Cha la: "<<k->data;
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();
				break;
			}
			case 5:
			{
				cout<<"\n";
				int xx=-1,mm=0;
				cout<<"Do sau cua cay la: "<<treeDepth(root,xx,mm); 
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();
				break;
			}
			case 6:
			{
				cout<<"\n";
				cout<<"Trong cay tren: \n\t-gia tri lon nhat: "<<GTLN(root)<<"\n\t-gia tri nho nhat: "<<GTNN(root);
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();
				break;
			}
			case 7:
			{
				cout<<"\n";
				cout<<"Tinh tong cac phan tu tren cay: "<<Tong(root);
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();
				break;
			}
			case 0:
			{
				printf("\n");
				printf("\n  Cam on da su dung chuong trinh cua chung toi!");
				cout<<"\nNhap phim bat ky de tiep tuc!!!";
				getch();	
				return 0;
			}								
			default:printf("Lua chon trong 0-6! ");
			printf("\nNhan phim bat ki de tiep tuc!");
			getch();
		}
	}while(n!=0);
	return 0;
}
