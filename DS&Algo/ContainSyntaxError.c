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
    {   )
       
    
    if (isEmpty() != 0)
    {
        printf("Syntax Error : redundant ");
    }
    else
    {
        printf("Correct Syntax ! ");
    }
}
