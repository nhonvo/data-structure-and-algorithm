#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fptr;
	
	int num;
	fptr= fopen("text.txt","w");
	
	if (fptr==NULL){
		printf("Error. File not found");
		exit(1);
	}
	printf("Enter data(number, character,...) in file text.txt:");
	scanf("%d", &num);
	fprintf(fptr, "%d", &num);
	fclose(fptr);
	return 0;
}

