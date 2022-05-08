#include <stdio.h>
#include <conio.h>
#define MAX 101

void nhap(int n, int a[])
{
	do
	{
		printf("Nhap N=");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
		{
			printf("Error.Enter again.");
		}

	} while (n <= 0 || n > 100);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i + 1);
		scanf("%d", &a[i]);
	}
}

void xuat(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\t%d", a[i]);
	}
}

void merge(int Arr[], int right , int left, int mid){
//count elements
	int n1=(mid -left)+1;
	int n2 =(right -mid);
//declare two array with number of elements
	int *leftArr=new int[n1];
	int *rightArr=new int[n2];
//store elements in extra array leftandright
	for (int i=0;i<n1;i++){
		leftArr[i]=Arr[left+i];
	}
	for (int j=0;j<n2;j++){
		rightArr[j]=Arr[mid+1+j];
	}
	int i=0;
	int j=0;
	int current=left;
	
	//nguyen 3 vong while duoi chi de sap xep ss i va j cai nao nho hon thi lay gan vao mang cu
	while(i<n1 &&j<n2 ){
		if (leftArr[i]<=rightArr[j]){
			Arr[current]= leftArr[i];
			i++;
		}
		else{
			Arr[current]= rightArr[j];
			j++;
		}
		current++;
	}
	//hai vong while cuoi thi danh cho ptu i hoac j cuoi cung tai khi tach mang se co do dai ngan khac nhau
	while (i<n1){
		Arr[current]=leftArr[i];
		i++;
		current++;
	}
	while(j<n2){
		Arr[current]=rightArr[j];
		j++;
		current++;
	}
}
// dung de chia mang lam 2 cho den khi con dung 1 phan tu //truong hop ss 1-1=> gan vao mang co 2 ptu lenh nay o vong while biggest
void mergesort(int A[], int left, int right){
	if (left< right){//for what? condition stop??==> check. If array has only one elemeter, program will stop.
		int mid=left+(right-left)/2;
		mergesort(A,left,mid);//stop when right = mid =0
		mergesort(A,mid+1,right);
		merge(A,right,left,mid);//sap xep tu 1-1 den 2-2 den 4-4
	}
}
int main()
{
	int n, a[101];
//	int Arr[] = {12, 11, 13, 5, 6, 7,23};
//  	int Arr_size = sizeof(Arr)/sizeof(Arr[0]);	
//	printf("Given array is \n");
//	xuat(Arr_size, Arr);
//	printf("\nSorted array is \n");
//	mergesort(Arr, 0, Arr_size-1);	
//	xuat(Arr_size, Arr);

	printf("Given array is \n");
	printf("Nhap N=");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i + 1);
		scanf("%d", &a[i]);
	}
	mergesort(a, 0, n-1);

	printf("\nSorted array is \n");
	xuat(n,a);
	
	return 0;
}
