#include<stdio.h>

int linearsearch(int a[], int key){
	int i,j,vt=7;
	for( i=0;i<6;i++){
		if(a[i]==key){
			vt=i;			
		}
	}
	if(vt==7){
		return -1;
	}else{
		return vt;
	}
}

int main(){
	int a[] ={1,2,3,4,5,6};
	int key;
	for(int i=0 ;i <6; i++)
		printf("\t%d", a[i]);
	printf("\nNhap so can tim:");
	scanf("%d", &key);
	printf("\n%d",linearsearch(a,key));
	
	
}
