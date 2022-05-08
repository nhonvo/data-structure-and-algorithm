#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
};
typedef Node* tree;

int Init(tree &root)
{
	root = NULL;
}
int isempty(tree root)
{
	return root == NULL;
}
tree CreateNode(int x)
{
	tree p = new Node;
	p->data = x;
	p->left=p->right=NULL;
	return p;
}

void createtree(tree &root)
{
	char x;
	cout<<"Nhap gia tri node"<<endl;
	x = getch();
	if(isspace(x)==0)
	{
		root = new Node;
		root->data = x;
		cout<<"Con phai cua "<<x<<": (Enter la NULL) "<<endl;
		createtree(root->right);
		cout<<"Con trai cua "<<x<<": (Enter la NULL) "<<endl;
		createtree(root->left);
	}else
	{
		root=NULL;
	}
}

void NLR(tree root)
{
	if(isempty(root)){
		return ;
	}else
	{
		cout<<root->data<<" ";
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(tree root)
{
	if(isempty(root)){
		return ;
	}else
	{
		LNR(root->left);
		cout<<root->data<<" ";
		LNR(root->right);
	}
}
void LRN(tree root)
{
	if(isempty(root)){
		return ;
	}else
	{
		LRN(root->left);
		LRN(root->right);
		cout<<root->data<<" ";
	}
}
	
tree search(tree root, char x)
{
	tree p = new Node;
	if(root == NULL)
	{
		return NULL;
	}
	if(root->data == x)
	{
		return root;
	}
	p = search(root->left,x);
	if(p == NULL)
	{
		p = search(root->right,x);
	}
}
void InsertLeft(tree node, int x)
{
	if(isempty(node))
		cout<<"\nNut khong ton tai";
	else
		if(node->left != NULL)
			cout<<"\nDa co nut con ben trai";
		else if(node->data==x)
			return;
		else
			node->left= CreateNode(x);
}
void InsertRight(tree node, int x)
{
	if(isempty(node))
		cout<<"\nNut khong ton tai";
	else
		if(node->right != NULL)
			cout<<"\nDa co nut con ben phai";
		else if(node->data==x)
			return;
		else
			node->right= CreateNode(x);
}

void clear(tree &root)
{
	tree p;
	if(root==NULL)
	{
		printf("Nothing");
	}
	if(root->left)
	{
		clear(root->left);
	}
	if(root->right)
	{
		clear(root->right);
	}
	delete root;
	root = NULL;
}
int main()
{
	tree root;
	Init(root);
	createtree(root);
	
	cout<<"\nCay nhi phan: ";
	LNR(root);
	char uu;
	cout<<"\nNhap gia tri can tim: "; cin>>uu;
	cout<<"\nTim kiem node, Ket qua: ";
	if(search(root, uu)== NULL)
	{
		cout<<"Khong co";
	}else
	{
		cout<<"Co";
	}
	clear(root);
	LNR(root);	
	return 0;
}
