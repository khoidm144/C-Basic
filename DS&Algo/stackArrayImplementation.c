#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int count = 0;
char *stack;
void init()
{
    stack = malloc(MAX * sizeof(char));
    count = 0;
}
int isEmpty()
{
    return count == 0;
}
int isFull()
{
    return MAX == count;
}
void push(char new)
{
    if (count == MAX)
    {
        return;
    }
    stack[count++] = new;
}
char pop()
{
    return stack[--count];
}
char peek()
{
    return stack[count - 1];
}
int countNumberOfStack()
{
    return count;
}
void printStack()
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", stack[i]);
    }
}
int main()
{
    FILE *input = fopen("ContainSyntaxError.c", "r+");
    char c;
    init();
    int flag = 1;
    while (!feof(input))
    {   
        c = fgetc(input);
        putchar(c);
        if(c<0){
        	break;
		}
        if (c == '{' || c == '(' || c == '[')
        {
            push(c);
        }
        else if (c == '}' || c == ')' || c == ']')
        {
            char temp = pop();
            if (c == '}' && temp != '{')
            {
                printf("Syntax Error found at {}");
                return 0;
            }
            else if (c == ')' && temp != '(')
            {
                printf("Syntax Error found at ()");
                return 0;
            }
            else if (c == ']' && temp != '[')
            {
                printf("Syntax Error found at []");
                return 0;
            }
        }
    }
     printStack();
    if (isEmpty() != 1)
    {
        printf("Syntax Error : redundant or missing %c  ",pop());
    }
    else
    {
        printf("Correct Syntax ! ");
    }
}
