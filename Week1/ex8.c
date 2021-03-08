#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    FILE *input, *output;
    char c;
    input = fopen("lab1.txt", "r");
    output = fopen("lab1w.txt", "w+");
    while ((c = fgetc(input)) != EOF)
    {
        if (islower(c))
        {
            c = toupper(c);
        }
        else if (isupper(c))
        {
            c = towlower(c);
        }
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}