#include <stdio.h>
#include <string.h>
int main()
{
    char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char str[30];
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }
    printf("Input the string ! : \n");
    scanf("%[^\n]%*c", str);
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == alphabet[j])
            {
                count[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            printf("The letter %c appears %d times !\n", alphabet[i], count[i]);
        }
    }
    return 0;
}