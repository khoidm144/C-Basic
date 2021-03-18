#include <stdio.h>
#include<string.h>
#include "item.h"
#include "stack.h"

int main()
{
    char s[30];
    scanf("%[^\n]%*c", s);
    init(strlen(s));
    for (int i = 0; i < strlen(s); i++)
    {
        item a = s[i];
        push(a);
    }
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", pop());
    }
    return 0;
}