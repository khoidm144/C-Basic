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
void printArr(node root)
{
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %s %s \n", temp->data.name, temp->data.phone, temp->data.email);
    }
}
node SortedMerge(node a, node b)
{
    node result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (strcmp(a->data.name, b->data.name) <= 0)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
void FrontBackSplit(node source,
                    node *frontRef, node *backRef)
{
    node fast;
    node slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(node *headRef)
{
    node head = *headRef;
    node a;
    node b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
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
    MergeSort(&root);
    printArr(root);
}