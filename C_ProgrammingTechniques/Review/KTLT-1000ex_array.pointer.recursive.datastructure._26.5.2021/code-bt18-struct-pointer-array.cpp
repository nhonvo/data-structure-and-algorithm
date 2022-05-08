#include<stdio.h>
struct name{
	char name[10];
	int manufactureday;
	float weight;
	float height;
};
typedef name na;

int main(){
	na *car, car1;
	car=&car1;//assign to the first car
	printf("Enter information to search the cars:\n");
	printf("Name of car:");
	fflush(stdin);
	gets(car->name);
	printf("\nDay of manufacture:");
	scanf("%d", &car->manufactureday);
	printf("\nHeight of car:");
	scanf("%f", &car->height);
	printf("\nWeight of car:");
	scanf("%f", &car->weight);	
	printf("\nInformation of your car:");
	printf("\nTrademark:%s",car->name);
	printf("...");
	
	return 0;
}
