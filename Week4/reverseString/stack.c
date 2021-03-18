#include <stdlib.h>
#include "stack.h"
#include "item.h"
static item *node;
static int n;
void init(int max)
{
    node = malloc(max * sizeof(item));
    n = 0;
}
int isEmpty()
{
    return n == 0;
}
int isFull(int max)
{
    return max == n;
}
void push(item Item)
{
    node[n++] = Item;
}
item pop()
{
    return node[--n];
}