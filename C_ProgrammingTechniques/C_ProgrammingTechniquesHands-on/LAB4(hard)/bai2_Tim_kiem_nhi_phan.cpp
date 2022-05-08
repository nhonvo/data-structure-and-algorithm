#include<stdio.h>
void Nhap(int a[], int n){
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
}

void Xuat(int a[], int n){
    printf("\n----------------\n");
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}

int binarySearch_Dequy(int arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2; 
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch_Dequy(arr, l, mid - 1, x);
		return binarySearch_Dequy(arr, mid + 1, r, x);
	}
	return -1;
}

int binarySearch(int arr[], int n, int x) {
int r = n - 1; 
int l = 0; 
	while (r >= l) {
	int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
	if (arr[mid] > x)
		r = mid - 1;
	if (arr[mid] < x)
		l = mid + 1;
}
	return -1;
}
int main(){
	int a[100];
	int n;
	printf("n = ");
    scanf("%d",&n);
    Nhap(a,n);
    Xuat(a,n);
    int x;
    scanf("%d",&x);
    int result =binarySearch_Dequy(a,0,n-1,x);
    printf("\nDe quy\n");
    if (result == -1)
    printf("%d xuat hien tai chi so %d", x, result);
  else
    printf("%d xuat hien tai chi so %d", x, result);
    
printf("\nKhong de quy\n");
	int keq= binarySearch(a,n,x);
	 if (keq == -1)
    printf("%d xuat hien tai chi so %d", x, keq );
  else
    printf("%d xuat hien tai chi so %d", x, keq);
}
