#include <stdio.h>
int main()
{
    FILE *input, *output;
    char c;
    input = fopen("lab1.txt", "r");
    output = fopen("lab1w.txt", "w+");
    while ((c = fgetc(input)) != EOF)
    {
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}