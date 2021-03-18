#include <stdlib.h>
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
    if (n == 0)
    {
        item temp;
        temp.tel = -1;
        return temp;
    }
    return node[--n];
}
int countNumberOfStack(){
    return n;
}