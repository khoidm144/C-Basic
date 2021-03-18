#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
int main()
{
    FILE *input, *output;
    char name[20];
    int tel;
    char email[30];
    item temp;
    input = fopen("data.txt", "r");
    output = fopen("dataOut.txt", "w+");
    init();
    while (!feof(input))
    {
        if (fscanf(input, "%[^\n]%*c", name) == EOF)
        {
            break;
        }
        strcpy(temp.name, name);
        fscanf(input, "%d%*c", &temp.tel);
        fscanf(input, "%[^\n]%*c", temp.email);
        push(temp);
    }
    while (countNumberOfStack()>0)
    {   
        temp = pop();
        fprintf(output, "%s\n", temp.name);
        fprintf(output, "%d\n", temp.tel);
        fprintf(output, "%s\n", temp.email);
    }
    fclose(input);
    fclose(output);
}