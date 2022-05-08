#include<stdio.h>

void nhap(int n,int a[])
{
	for(int i=0;i<n;i++)
	{
		printf("\na[%d]=",i); scanf("%d",&a[i]);
	}
}
void xuat(int n,int a[])
{
	printf("\nCac phan tu cua mang:");
	for(int i=0;i<n;i++)
	{
		printf("\na[%d]=%d",i,a[i]);
	}
}
//tinh tong
int tinh_tong(int n,int a[])
{

	int s=0;
	for(int i=0;i<n;i++)
	{
		s+=a[i];
	}
	return s;
}
//tinh tb cong
float trung_binh(int n, int a[])
{
	return (float)tinh_tong(n,a)/n;
}
//sap xep doi cho
void swap(int &a, int &b)
{
	int x = a;
	a = b;
	b = x;
}
void interchangesort(int a[], int n)
{
	for (int i = 0; i < n-1;i++)
		for (int j = i + 1; j < n;j++)
		if (a[i]>a[j])
			swap(a[i], a[j]);
}
//sap xep noi bot
void bubbleSort(int a[], int n)
{
   int i, j;
   for (i = 0; i < n; i++)
   {
       for (j = n-1; j > i; j--)
       {
           if(a[j] < a[j-1])
               swap(a[j], a[j-1]);
       }
   }
}
//sap xep chon
void selectionsort(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		int min_dx = i;
		for (int j = i + 1; j < n; j++)
		{
			if(a[j]<a[min_dx]){
				min_dx=j;
			}
			swap(a[min_dx],a[i]);
		}
	}
}

//sap xep chen
void insertionSort(int n, int a[])
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = a[i];
       j = i-1;

       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}
//sap xep nhanh

int partition(int a[], int left, int right)
{
	int i = left;
	int j = right - 1;	  
	int pivot = a[right]; 
	while (true)
	{
		while (pivot > a[i] && i <= j)
			i++;
		while (pivot < a[j] && i <= j)
			j--;
		if (i >= j)
		{		  
			break; 
		}
		else
		{
			swap(a[i], a[j]); 
			i++;			  
			j--;
		}
	}
	swap(a[i], a[right]); 
	return i;			  
}
void quicksort(int a[], int left, int right)
{
	if (left <= right)
	{
		int pi = partition(a, left, right); 
		quicksort(a, left, pi - 1);
		quicksort(a, pi + 1, right);
	}
}
//tim kiem tuyen tinh
int linearsearch(int a[], int key){
	int i,j,vt=-1;
	for( i=0;i<6;i++){
		if(a[i]==key){
			vt=i;			
		}
	}
	if(vt==-1){
		return -1;
	}else{
		return vt;
	}
}
//tim kiem nhi phan
int binarysearch(int n, int a[], int key){
	
	int left = 0, right =n - 1;
	int mid;
	int vt=-1;
	
	while(left <= right){
	mid =(right + left)/2 ;
		if(a[mid] == key){
			return mid;
		}else if(a[mid] > key){
			right =mid -1;
		}else{
			left =mid +1;
		}
	}
	return -1;
}
int main()
{
	int n;
	int a[101];
	do
	{
		printf("Nhap n: "); scanf("%d",&n);
		if(n<=0||n>100)
		{
			printf("\nNhap sai! Moi nhap lai.\n");
		}
	}while(n<=0||n>100);

	nhap(n,a);
	xuat(n,a);
//	tinh tong v trung binh cong
	int sum = tinh_tong(n,a);
	printf("\nTong cac phan tu:");
	printf("%d",sum);
	printf("\nTrung binh mang: %.2f",trung_binh(n,a));
// cac thuat toan sap xep
//1.  sap xep doi cho
	printf("\nSap xep doi cho: ");
	interchangesort(a,n);
	xuat(n,a);
//2.  sap xep noi bot
	printf("\nSap xep noi bot: ");
	bubbleSort(a,n);
	xuat(n,a);	
//3.  sap xep chon
	printf("\nSap xep chon: ");
	selectionsort(n,a);
	xuat(n,a);
//4.  sap xep chen
	printf("\nSap xep cheh: ");
	insertionSort(n,a);
	xuat(n,a);
//5.  sap xep nhanh
	printf("\nSap xep nhanh: ");
	quicksort(a,0,n-1);
	xuat(n,a);
//6.tim kiem tuyen tinh
	int key;
	printf("\nNhap so can tim bang tim kiem tuyen tinh:");
	scanf("%d", &key);
	printf("\nVi tri cua so can tim: %d",linearsearch(a,key));
//7.tim kiem nhi phan
	int key_2;
	printf("\nNhap so can tim bang tim kiem nhi phan:");
	scanf("%d", &key_2);
	printf("\nVi tri so can tim:\t%d",binarysearch(n,a,key_2));
	return 0;
	
}
