#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[30];
    char number[12];
    char email[30];
} phone;

int main()
{
    FILE *input, *output;
    output = fopen("output.txt", "w+");
    phone a[100];
    phone b[100];
    for (int i = 0; i < 10; i++)
    {
        scanf("%[^\n]%*c", a[i].name);
        scanf("%[^\n]%*c", a[i].number);
        scanf("%[^\n]%*c", a[i].email);
    }
    int check = 0;
    char c = '\n';
    for (int i = 0; i < 10; i++)
    {
       fwrite(&a[i],sizeof(a[i]),1,output);
        //printf("%s %s %s \n",a[i].name,a[i].number,a[i].email);
    }
    fclose(output);
    char s[30];
    printf("\n----------------------------------------------------\n");
    output = fopen("output.txt", "r+");
    for (int i = 0; i < 10; i++)
    {
        fread(&b[i],sizeof(b[i]), 1, output);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%s %s %s \n",b[i].name,b[i].number,b[i].email);
    }

    return 0;
}