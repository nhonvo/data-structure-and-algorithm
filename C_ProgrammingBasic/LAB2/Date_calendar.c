#include<stdio.h>

int calendar(int month){
	int year;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		printf("day:31");
	}
	else if(month==4||month==6||month==9||month==11)
	{
		printf("day:30");
		
	}else if(month==2)
	{
		printf("Enter year:");
		scanf("%d", &year);
			if(year%4==0)
			{
				printf("Day:29");
			}else
			{
				printf("Day:28");
			}
	}
}
int main(){
	int month;
	do{
		printf("Enter month:");
		scanf("%d", &month);
		if(month<0||month>12)
		printf("Enter again.");
	}while(month<0||month>12);
	
	calendar(month);
	return 0;
}
