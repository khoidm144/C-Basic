#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mystr_cat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *ans = (char *)malloc((strlen(s1) + strlen(s2)) * (sizeof(char)));
    while (1)
    {
        if (*(s1 + i) != '\0')
        {
            *(ans + i) = *(s1 + i);
            i++;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        if (*(s2 + j) != '\0')
        {
            *(ans + i) = *(s2 + j);
            i++;
            j++;
        }
        else
        {
            break;
        }
    }
    return ans;
}
int main()
{
    char s1[30];
    char s2[30];
    printf("Input the first string : ");
    scanf("%[^\n]%*c", s1);
    printf("Input the second string : ");
    scanf("%[^\n]%*c", s2);
    printf("%s", mystr_cat(s1, s2));
    return 0;
}