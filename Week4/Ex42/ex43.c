#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
int main(int argc, char *argv[])
{
    item temp;
    // char *st = argv[1];]
    char st[20];
    scanf("%[^\n]%*c", st);
    init();
    int count;

    for (int i = 0; i < strlen(st); i++)
    {
        if (isdigit(st[i]))
        {
            push(st[i]);
        }
        if (st[i] == '+')
        {
            push((pop() - '0') + (pop() - '0')+'0');
        }
        if (st[i] == '-')
        {
            push((pop() - '0') - (pop() - '0')+'0');
        }
        if (st[i] == '*')
        {
            push(((pop() - '0') * (pop() - '0'))+'0');
        }
        if (st[i] == '/')
        {
            push(((pop() - '0') / (pop() - '0'))+'0');
        }
    }
    printf("%c", pop());
}