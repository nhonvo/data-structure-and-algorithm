#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
typedef node* tree;

void Init(tree &root)
{
	root = NULL;
}

int isEmpty(tree root)
{
	return root == NULL;
}

tree createnode(int x)
{
	tree p =new node;
	p->data = x;
	p->left=p->right = NULL;
	return p;
}
void Insertnode(tree &root, int x)
{
	if(root!=NULL)
		if(root->data > x)
			Insertnode(root->left, x);
		else
			Insertnode(root->right,x);
	else
		root = createnode(x);
}
void CreateTree(tree &root, int n)
{
	int x;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap gia tri node thu "<<i<<": "; cin>>x;
		Insertnode(root, x);
	}
	
}
void RNL(tree root)
{
	if(root!=NULL)
	{	RNL(root->right);
		cout<<root->data<<" ";
		RNL(root->left);
	
	}
}
void LNR (tree root)
{
    if(root != NULL)
    { 
		LNR(root->left);
		cout<<root->data<<" ";
        LNR(root->right);
    }    
}
tree Search(tree root, int x)
{
	tree p = new node;
	if(root == NULL)
		return NULL;
	if(root->data ==x)
	{
		return root;
	}else{
		if(root->data > x)
		{
			p=Search(root->right,x);
		}else
		{
			p=Search(root->left,x);	
		}
	}
	
	if(p==NULL)
	{
		p = Search (root->right,x);
	}
}
int remove(tree root, int x)
{
	
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
int tong(tree x)
{
    if(x==NULL)return 0;
    return tong(x->left)+tong(x->right)+x->data;
}
int main()
{
	tree root;
	Init(root);
	int n;
	cout<<"Nhap so luong node: "; cin>>n;
	CreateTree(root, n);
	cout<<"Duyet giam dan: ";
	RNL(root);
	cout<<"\nDuyet tang dan: ";
	LNR(root);
	cout<<"\nTong: "<<tong(root);
}

