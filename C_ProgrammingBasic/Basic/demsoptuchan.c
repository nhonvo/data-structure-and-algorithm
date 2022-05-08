#include<stdio.h>

int sumEven(int a[1000], int n)
{
		int i, j, s=0;
		for(i=1; i<=n; i++)
		{
			if(a[i]%2==0)
			{
				s++; 
			}
		} 
		printf("Sum of even numbers is:%d", s);
}
int main(){
	int a[1000],n,i;
	printf("Enter element number of serial numbers n=");
	scanf("%d", &n);
	
	for(i=1;i<=n;i++)
	{
		printf("Enter a[%d]=", i);
		scanf("%d", &a[i]);
	}
	sumEven(a, n);
	return 0;
}


