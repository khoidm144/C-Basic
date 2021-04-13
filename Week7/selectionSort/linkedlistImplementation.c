#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct AddressStruct
{
    char name[30];
    char phone[15];
    char email[30];
} address;
typedef struct node
{
    address data;
    struct node *next;
} * node;
node makeNode(address newAdd)
{
    node newNode = (node)malloc(sizeof(struct node));
    newNode->data = newAdd;
    newNode->next = NULL;
    return newNode;
}
node sortedInsert(node sortedRoot, node newNode)
{
    if (sortedRoot == NULL || strcmp(sortedRoot->data.name, newNode->data.name) >= 0)
    {
        newNode->next = sortedRoot;
        return newNode;
    }
    node cur = sortedRoot;
    while (strcmp(cur->data.name, newNode->data.name) < 0 && cur->next != NULL)
    {
        cur=cur->next;
    }
    newNode->next=cur->next;
    cur->next=newNode;
    return sortedRoot;
}

void printArr(node root)
{
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %s %s \n", temp->data.name, temp->data.phone, temp->data.email);
    }
}
node insertionSort(node root)
{
    node cur = root;
    node sortedRoot = NULL;
    while (cur != NULL)
    {
        node curNext = cur->next;
        sortedRoot = sortedInsert(sortedRoot, cur);
        cur = curNext;
    }
    return sortedRoot;
}
int main()
{
    FILE *input = fopen("data.txt", "r");
    char name[20];
    int phone;
    char email[30];
    address temp;
    int index = 0;
    address arr[30];
    node root;
    node cur;
    while (!feof(input))
    {
        if (fscanf(input, "%[^\n]%*c", name) == EOF)
        {
            break;
        }
        strcpy(temp.name, name);
        fscanf(input, "%[^\n]%*c", temp.phone);
        fscanf(input, "%[^\n]%*c", temp.email);
        if (index == 0)
        {
            root = makeNode(temp);
            cur = root;
            index = 1;
            continue;
        }
        cur->next = makeNode(temp);
        cur = cur->next;
        index++;
    }
    index++;
    root = insertionSort(root);
    printArr(root);
}