#include<stdio.h>
#include<string.h>
// y tuong: tao hai stack 1 luu thu tu toan tu 1 luu thu tu bieu thuc 
struct Node
{
    float so;
    char c;
    Node *next;
};
struct Stack
{
    Node *Front;
};
void Init(Stack &x)
{
    x.Front = NULL;
}
int IsEmpty(Node *x)
{
    return x == NULL;
}
//khoi tao c luu toan tu, so luu gia tri
Node *CreateNode(char x,float so)
{
    Node *p = new Node;
    p->c = x;
    p->so=so;
    p->next = NULL;
    return p;
}
void Push(Stack &st,char x,float so)
{
    Node *p = CreateNode(x,so);
    if(IsEmpty(st.Front))
    {
        st.Front = p;
        return;
    }
    p->next = st.Front;
    st.Front = p;
}
void Remove(Stack &st,char &x,float &so)
{
    if(IsEmpty(st.Front))
		return;
    Node *p = st.Front;
//    lay node p ra
    st.Front = p->next;
//    cho node tiep theo = st.Front
    x = p->c;
    so = p->so;
//    luu lai gia tri
    delete p;
}
int Bac(char x)
{
    if(x=='(')return 0;
    if(x=='+'||x=='-')return 1;
    return 2;
}
//a*(b+c)+d/e*f*(h+g)
//abc+*de/f*hg+*+
//a*b+c = > ab*c+

void TaoBieuThucHauTo(Stack &post, Stack &dau, char c[])
{
	// vi xet tung truong hop nen dung continue de quay lai
	//
    int i = 0;
    int n = strlen(c);
    while(i<n)
    {
        if(c[i]>='0'&&c[i]<='9')
        {
            float so=0;
            while(c[i]>='0'&&c[i]<='9')
            {
                so=so*10+(c[i]-'0');
                //dung cho th nhieu hon 1 so th� cho v�o tung so roi chuyen sang n so bang cach
				// chuyen sang ascii - '48'(0) -> ... 
                i++;
            }
            Push(post,'0',so);
            printf("%.0f ",so);
            continue;
        }
        if(c[i]=='(')
        {
            Push(dau,'(',0);
            i++;
            continue;
        }
        if(c[i]==')')
        {
            char x;
			float so;
            Remove(dau,x,so);
            while(x!='(')
            {
                Push(post,x,so);
                printf("%c ",x);
                Remove(dau,x,so);
            }
            i++;
            continue;
        }
        //neu bac cua toan tu trong stack >= bac cua toan tu truyen vao lay ra cho cho post
        while(!IsEmpty(dau.Front)&&Bac(c[i])<=Bac(dau.Front->c))
        {
            char x;float so;
            Remove(dau,x,so);
            Push(post,x,so);
            printf("%c ",x);
        }
        Push(dau,c[i],0);
        i++;
    }
    //neu trong dau van con thi xuat het vao post(btht)
    while(!IsEmpty(dau.Front))
    {
        float so;char x;
        Remove(dau,x,so);
        Push(post,x,so);
        printf("%c ",x);
    }
}
float Cal(float x,float y,char z)
{
    if(z=='+')return x+y;
    if(z=='-')return x-y;
    if(z=='*')return x*y;
    if(z=='/')return x/y;
}
// tu stack post lay du 2 so lay them 1 toan tu ra ngoai hinh thanh bieu thuc
float GiaTriBieuThuc(Stack &post,Stack &dau)
{
    char x;float so;
    while(!IsEmpty(post.Front))
    {
        Remove(post,x,so);
//        lay ra 1 toan tu
        if(x=='0')
//        lay ra 2 chu so n�u x = '0'
        {
            while(!IsEmpty(dau.Front)&&dau.Front->c=='0')
            {
                char x1,x2;
                float so1,so2;
                Remove(dau,x1,so1);
                Remove(dau,x2,so2);
                so = Cal(so,so1,x2);
//                dung ham cal() de tinh gia tri
            }
        }
        Push(dau,x,so);
    }
    Remove(dau,x,so);
    return so;
}
int main()
{
    char c[1000];
    fflush(stdin);
    printf("Nhap bieu thuc can bien doi: ");
    scanf("%s",&c);
    Stack post,dau;
    Init(post);
    Init(dau);
    printf("Bieu thuc hau to: ");
	TaoBieuThucHauTo(post,dau,c);
    printf("\n");
    float t = GiaTriBieuThuc(post,dau);
    printf("%.02f",t);
}
