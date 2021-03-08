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
   
    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w+");
    while ((check = fread(&c, sizeof(char), 1, input)) > 0)
    {
        if (check > 0)
            printf("%c",c);
    }

    fclose(input);
    fclose(output);
    return 0;
}