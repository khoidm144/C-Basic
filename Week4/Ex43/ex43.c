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
    int a = 0;
    int count;

    for (int i = 0; i < strlen(st); i++)
    {
        if (isdigit(st[i]))
        {
            a = (int)(st[i] - 48);
            push(a);
            if (i > 0 && (st[i-1]>='0'&&st[i-1]<='9'))
            {   
                printStack(a);
                push(pop()  + pop()*10);
            }
        }
        if (st[i] == '+')
        {
            push(pop() + pop());
        }
        if (st[i] == '-')
        {
            push(pop() - pop());
        }
        if (st[i] == '*')
        {
            push(pop() * pop());
        }
        if (st[i] == '/')
        {
            push(pop() / pop());
        }
    }
    printf("%d", pop());
}