#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *input, *output;
    char c;
    char s[30];
    size_t check;
    input = fopen("lab1.txt", "r");
    // input = fopen(argv[1], "r");
     output = fopen("new.txt", "w+");
    while(!feof(input))
    {
       fscanf(input,"%[^\n]%*c",s);
       fprintf(output,"%s\n\n",s);
    }
    fclose(input);
    fclose(output);
    char old[30]="new.txt";
    char new[30]="lab1.txt";
    int a= remove(new);
   rename(old,new);
    printf("%d",a);
    return 0;
}