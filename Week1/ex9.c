#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    FILE *input, *output;
    char c;
    char s[30];
    input = fopen("lab1.txt", "r");
    output = fopen("lab1w.txt", "w+");
    while (!feof(input))
    {
        fgets(s, 30, input);
        fputs(s, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}