#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *input, *output;
    char c;
    char s[30];
    int count = 0;
    input = fopen("lab1.txt", "r");
    output = fopen("lab1w.txt", "w+");
    while (!feof(input))
    {
        fscanf(input, "%[^\n]%*c", s);
        fprintf(output, "%d %s\n", strlen(s), s);
    }

    fclose(input);
    fclose(output);
    return 0;
}