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
        count = countNumberOfStack();
        if (isdigit(st[i]))
        {
            printf("%c", st[i]);
        }
        else if (st[i] == '+' || st[i] == '-')
        {
            temp = st[i];
            if (count > 0 && (peek() == '*' || peek() == '/' || peek() == '+' || peek() == '-'))
            {
                printf("%c", pop());
            }
            push(st[i]);
        }
        else if (st[i] == '*' || st[i] == '/')
        {
            if (count > 0 && (peek() == '*' || peek() == '/'))
            {
                printf("%c", pop());
            }
            push(st[i]);
        }
        else if (st[i] == '(')
        {
            push(st[i]);
        }
        else if (st[i] == ')')
        {
            while (countNumberOfStack() > 0)
            {
                if (peek() == '(')
                {
                    pop();
                    break;
                }
                printf("%c", pop());
            }
        }
        else
        {
            printf("%c", st[i]);
        }
    }
    while (countNumberOfStack() > 0)
    {    
            printf("%c", pop());
    }
}