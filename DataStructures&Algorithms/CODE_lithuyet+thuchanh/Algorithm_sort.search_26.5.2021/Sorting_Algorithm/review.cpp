#include<stdio.h>

int swap(int &a, int &b){
	int tmp=a;
	a=b; 
	b=tmp;
}

void bubblesort(int n, int arr[]){
	for (int i=0;i<n-1;i++){
		for(int j=i+1; j<n; j++){
			if(arr[i]>arr[j]){
				swap(arr[i],arr[j]);
			}
		}
	}
}

void selectedsort(int n, int arr[]){
	for (int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[min]){
				min=j;
			}
			swap(arr[min],arr[i]);
		}	
	}
}
void insertsort(int n, int arr[]){
	int i,j,key;
	for(int i=1;i<n;i++){
		key=arr[i];
		j=j-1;
		while(j>=0&&arr[j]>key){
//			if(arr[j]>key){
				arr[j+1]=arr[j];
				j--;
			
		}
			arr[j+1]=key;
	}
}

int merge(int arr[], int left,int mid, int right){
	int n1=(mid-left+1);
	int n2=(right-mid);
	int *leftArr=new int[n1];
	int *rightArr=new int[n2];
	int current=left;
	
	for(int i=0;i<n1;i++){
		leftArr[i]=arr[left+i];
	}
	for(int j=0;j<n2;j++){
		rightArr[j]=arr[mid+1+j];
	}
	int i=0,j=0;
	while(i<n1&&j<n2){
		if(leftArr[i]<rightArr[j]){
			arr[current]=leftArr[i];
			i++;
		}else{
			arr[current]=rightArr[j];
			j++;
		}
		current++;
	}
	while(i<n1){
		arr[current]=leftArr[i];
		i++;
		current++;
	}
	while(j<n2){
		arr[current]=rightArr[j];
		j++;
		current++;
	}
}
void mergesort(int arr[], int left, int right){
	if(left<right){
		int mid =(left+right)/2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr, left,mid, right);
	}
}
int quick(int arr[], int left, int right){
	int pivot =arr[right];
	int i=left;
	int j=right-1;
	while(true){
		while(i<=j&&arr[i]<pivot) i++;
		while(i<=j&&arr[j]>pivot) j--;
		if(i>=j){
			break;
		}else{
			swap(arr[i],arr[j]);
			i++;j--;
		}
	}
	swap(arr[i],arr[right]);
	return i;
}
void quicksort(int arr[], int left, int right){
	if(left<=right){
		int pi=quick(arr,left, right);
		quicksort(arr, left,pi-1);
		quicksort(arr, pi+1,right);
	}
}
int printarray(int n, int arr[]){
	for(int i=0;i<n;i++){
		printf("\t%d",arr[i]);
	}
}

int main(){
	int arr[]={6,30,54,23,68,12,80,45};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Give array is:\n");
	printarray(n,arr);
	printf("\nArray sorted is:\n");
	/*function*/
//	quicksort(arr,0,n-1);
	insertsort(n,arr);
	printarray(n,arr);
}
