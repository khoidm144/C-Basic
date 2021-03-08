#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *input, *output;
    char c;
    char s[30];
    int count = 0;
    input = fopen(argv[1], "r");

    while (!feof(input))
    {
        count++;
        fscanf(input, "%[^\n]%*c", s);
        printf("%d %s\n", count, s);
    }

    fclose(input);
    return 0;
}