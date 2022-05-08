#include <stdio.h>

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int partition(int a[], int left, int right)
{
	int i = left;
	int j = right - 1;	  //khong con j=right vi vtr nay gio la cua pivot
	int pivot = a[right]; //chon pivot buoc nay quyet dinh nhanh cham cua bai toan
	while (true)
	{
		while (pivot > a[i] && i <= j)
			i++;
		while (pivot < a[j] && i <= j)
			j--;
		if (i >= j)
		{		   //bat buoc dung cau truc nay khong dung i<j
			break; //duyet xong thoat vong lap
		}
		else
		{
			swap(a[i], a[j]); //chua xong doi cho
			i++;			  //dang xet nen tang,giam
			j--;
		}
	}
	swap(a[i], a[right]); //doi cho a[i] voi pivot
	return i;			  // tra ve vi de chia doi mang vtri nay la vtr dung
}
void quicksort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pi = partition(arr, left, right); //lay vitri chuan so da dug vtr chi sep hai ben trai va phai
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}
//cach 2...............................................................
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
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
void quicksort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pi = partition(arr, left, right); 
		quicksort(arr, left, pi - 1);
		quicksort(arr, pi + 1, right);
	}
}
///..../////////////////////////////////////////////
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("\t%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {10, 80, 30, 90, 40, 50, 70};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is \n");
	printArray(arr, n);
	quicksort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);

	return 0;
}
