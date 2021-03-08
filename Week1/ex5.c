#include <stdio.h>
#include <string.h>
void replace_char(char *s, char a, char b)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (*(s + i) == a)
        {
            *(s + i) = b;
        }
    }
}
int main()
{
    char s[30];
    char a, b;

    printf("Input the string : ");
    scanf("%[^\n]%*c", s);
    printf("Input the first character : ");
    scanf("%c%*c", &a);
    printf("Input the second character : ");
    scanf("%c%*c", &b);
    replace_char(s, a, b);
    printf("%s\n", s);
    return 0;
}