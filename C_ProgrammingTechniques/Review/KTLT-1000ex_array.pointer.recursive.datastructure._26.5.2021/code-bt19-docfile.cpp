#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   int *num;
   FILE *fptr;
 
   if ((fptr = fopen("program.txt","r")) == NULL){
       printf("Error! opening file");
 
       exit(1);
   }
   for (int i=0;i<15;i++){
   	fscanf(fptr,"%d", &*(num+i));
   }
   
 
   printf("Value of n=%d", num);
   fclose(fptr); 
   return 0;	
}
