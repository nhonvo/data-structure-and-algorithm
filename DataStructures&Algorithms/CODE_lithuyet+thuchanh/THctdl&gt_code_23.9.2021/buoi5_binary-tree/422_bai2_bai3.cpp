#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef Node* Tree;

Tree root;

void Init(Tree &root)
{
	root = NULL;
}
int isEmpty(Tree root)
{
	return root == NULL;
}
Node* CreateNode(int x)
{
	Node* p = new Node;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}
void NLR(Tree root)
{
	if(root != NULL)
	{
		printf("%d", root->data);
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(Tree root)
{
	if(root != NULL)
	{
		LNR(root->left);
		printf("%d", root->data);
		LNR(root->right);
	}
}
void RNL(Tree root)
{
	if(root != NULL)
	{
		RNL(root->right);
		printf("%d", root->data);
		RNL(root->left);
	}
}
void Insert(Tree &root, int x)
{
	if(isEmpty(root)) root = CreateNode(x);
	else {
		if (x==root->data) return;
		if (x<root->data) Insert(root->left,x);
		else Insert(root->right,x);
	}
}
void InsertNode(Tree &root, int x)
{
	if (root != NULL)
	{
		if (root->data == x) return;
		if(root->data > x)
			InsertNode(root->left, x);
		else 
			InsertNode(root->right, x);
	}
	else root = CreateNode(x);
}
void CreateTree(Tree &root)
{
	int x, n;
	do {
		printf("\nNhap so node: ");
		scanf("%d", &n);
		if (n==0) return;
	} while (n<0 && printf("\n[ERROR] Khong hop le. "));
	
	for(int i = 1; i <= n; i++)
	{
		printf("\nNhap gia tri node %d: ", i);
		scanf("%d", &x); 
		InsertNode(root, x); 
	} 
}

int Remove(Tree &root,int X)
{
    if(root == NULL)    return 0;
    if(root->data > X)    return Remove(root->left,X);
    if(root->data < X)    return Remove(root->right,X);
    Node *p,*f,*rp;
	p=root;
    if(root->left == NULL)
        root = root->right;
    else if(root->right == NULL)
            root = root->left;
    else {
    	f = p;
    	rp = p->right;
    	while (rp->left != NULL)
    	{
    		f=rp;
    		rp = rp->left;
		}
		p->data = rp->data;
		if (f==p) f->right = rp->right;
		else f->left = rp->right;
		p = rp;
	}
    delete p;
    return 1;
}

bool Dung(Tree root, int minimum, int maximum)
{
    if(!root)
        return true;
    if(root->data < minimum || root->data > maximum)
        return false;
    return Dung(root->left, minimum, root->data-1) && Dung(root->right, root->data+1, maximum);
}

bool Daydu(Tree root)
{
	if (root == NULL)
    return true;

  	if (root->left == NULL && root->right == NULL)
    	return true;

 	if ((root->left) && (root->right))
    	return (Daydu(root->left) && Daydu(root->right));

  	return false;
}

Node* Search(Tree root, int x, Node* &f)
{
	Node* p = root;
    if(p!=NULL)
    	if(x<root->data)
    	{
    		f=p; 
			p=Search(root->left,x,f);
		}
        else if(x>root->data) 
        {
        	f=p; 
			p=Search(root->right,x,f);
		}	
    return p;
}

bool IsLeaf(Node* p)
{
	return (p->left == NULL) && (p->right == NULL);
}
bool IsMid(Node* p)
{
	return (p->left != NULL) && (p->right != NULL);
}
int LeafCounter(Tree root)
{
	if (root == NULL) return 0;
	else	if (IsLeaf(root)) return 1;
			else return LeafCounter(root->left) + LeafCounter(root->right);
}
int MidCounter(Tree root)
{
	if (root == NULL) return 0;
	else	if (IsMid(root)) return 1;
			else return MidCounter(root->left) + MidCounter(root->right);
}
int NodeCounter(Tree root)
{
	if (root == NULL) return 0;
	else return 1 + NodeCounter(root->left) + NodeCounter(root->right);
}

int Depth(Node* p, int &max, int d)
{
	if (p==NULL)
		return max;
	if (d>max) max = d;
	d = d+1;
	Depth(p->left,max,d);
	Depth(p->right,max,d);
	return max;
}

int LeftMostValue(Tree root)
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}

int RightMostValue(Tree root)
{
    while ( root->right != NULL )
        root = root->right;
    return root->data;
}

int Tong(Tree root)
{
	if(root == NULL) return 0;
	int l = Tong(root->left);
	int r = Tong(root->right);
	return l + r + root->data;
}

void Menu()
{
	printf("\n\n=============================MENU=====================================\n");
	
	printf("\n\t[1]: Insert");
	printf("\n\t[2]: Remove X (voi X nhap tu ban phim)");
	printf("\n\t[3]: Xuat DS tang dan");
	printf("\n\t[4]: Xuat DS giam dan");
	printf("\n\t[5]: Kiem tra cay nhi phan dung");
	printf("\n\t[6]: Kiem tra cay nhi phan day du");
	printf("\n\t[7]: Xac dinh father node cua node co data X");
	printf("\n\t[8]: Dem nut la, nut giua, kich thuoc cay");
	printf("\n\t[9]: Do sau/chieu cao cua cay");
	printf("\n\t[10]: Gia tri nho nhat tren cay");
	printf("\n\t[11]: Gia tri lon nhat tren cay");
	printf("\n\t[12]: Tong cac gia tri tren cay");
	printf("\n");
	printf("\n\t[0]: Thoat.");

	printf("\n\n======================================================================\n\n");
}

int main()
{
	Tree root;
	Init(root);
	CreateTree(root);
	char key;
	int chon;
	int X;
	
	do {
		do {
			do {
				printf("\n\n\tBT: "); NLR(root);
				Menu();
				printf("\nChon (key): "); scanf("%d",&chon);
			} while ((chon<0 || chon >12) && printf("\n[ERROR] Khong hop le. "));
			
				switch (chon)
				{
					case 1:		system("cls");
								printf("Nhap du lieu can them: "); scanf("%d",&X);
								Insert(root,X);
								break;
								
					case 2:		system("cls");
								printf("Nhap du lieu phan tu can xoa: "); scanf("%d",&X);
								if (Remove(root,X) == 0) printf("\n[ERROR] Khong the xoa. ");
								else printf("\n[SUCCESS] Da xoa %d.",X);
								break;
					
					case 3:		system("cls");
								printf("\n\nDS tang dan: ");
								LNR(root);
								break;
							
					case 4: 	system("cls");
								printf("\nDS giam dan: ");
								RNL(root);
								break;
					
					case 5:		system("cls");
								if (Dung(root, INT_MIN, INT_MAX)) printf("[CORRECT]");
								else printf("[INCORRECT]");
								break;
					
					case 6:		system("cls");
								if (Daydu(root)) printf("[CORRECT]");
								else printf("[INCORRECT]");
								break;
					
					case 7:		system("cls");
								printf("Nhap du lieu phan tu can tim father node: "); scanf("%d",&X);
								Node *f,*p;
								p = Search(root,X,f);
								if (p == NULL) printf("[ERROR] Khong the tim thay %d",X);
								else if (f == NULL) printf("[ERROR] Khong the tim thay father node cua %d",X);
								else if (root->data == X) printf("[ERROR] Root khong co cha");
								else printf("[SUCCESS] Father node cua %d la %d",X,f->data);
								break;
								
					case 8:		system("cls");
								int leaf,mid, node;
								leaf = LeafCounter(root);
								mid = MidCounter(root);
								node = NodeCounter(root);
								printf("\nSo luong node la: %d",leaf);
								printf("\nSo luong node giua: %d",mid);
								printf("\nKich thuoc cua cay: %d",node);
								break;
					
					case 9:		system("cls");
								int depth,max,d;
								d = 0;
								max = 0;
								depth = Depth(root,max,d);
								printf("\nDo sau cua cay: %d",depth);
								break;
								
					case 10:	system("cls");
								int min;
								min = LeftMostValue(root);
								printf("\nMin: %d",min);
								break;
								
					case 11:	system("cls");
								max = RightMostValue(root);
								printf("\nMax: %d",max);
								break;
								
					case 12:	system("cls");
								int sum;
								sum = Tong(root);
								printf("\nTong cac gia tri phan tu cua cay: %d",sum);
								break;
								
					default: chon = 0;
				}
		} while (chon != 0);
		
		
		printf("\nBan co muon tiep tuc? [Y/y]\nInput: ");
		key = getche();
		
	} while (key == 'y' || key == 'Y');
	
		
	return 0;
}
