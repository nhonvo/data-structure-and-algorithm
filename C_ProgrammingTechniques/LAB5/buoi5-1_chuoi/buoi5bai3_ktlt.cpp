#include <stdio.h>
FILE *f1,*f2;// f1 là tr? d?n input, f2 là tr? d?n file output
int main()
{
    int n,i;
    char s[100];
    f1 = fopen("bai1_in.txt","r");// m? d? d?c (d? cùng thu m?c v?i file code)
    f2 = fopen("bai1_out.txt","w");// m? d? ghi d? li?u
    fscanf(f1,"%d\n",&n);
    printf("%d", n);
    for(i=0;i<n;i++){
        fgets(s,100,f1);
        fputs(s,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
