#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define MAX 30
static item *node;
static int n;
void init()
{
    node = malloc(MAX * sizeof(item));
    n = 0;
}
int isEmpty()
{
    return n == 0;
}
int isFull()
{
    return MAX == n;
}
void push(item Item)
{
    if (n == MAX)
    {
        return;
    }
    node[n++] = Item;
}
item pop()
{
    return node[--n];
}
item peek()
{
    return node[n - 1];
}
int countNumberOfStack()
{
    return n;
}
void printStack()
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", node[i]);
    }
}