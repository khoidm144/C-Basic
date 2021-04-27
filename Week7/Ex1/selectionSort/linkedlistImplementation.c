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
node selectionSort(node root)
{
    node a, b, c, d, r;

    a = b = root;

    while (b->next)
    {

        c = d = b->next;

        while (d)
        {

            if (strcmp(b->data.name, d->data.name) > 0)
            {

                if (b->next == d)
                {

                    if (b == root)
                    {

                        b->next = d->next;
                        d->next = b;

                        r = b;
                        b = d;
                        d = r;

                        c = d;

                        root = b;
                        d = d->next;
                    }

                    else
                    {

                        b->next = d->next;
                        d->next = b;
                        a->next = d;

                        r = b;
                        b = d;
                        d = r;

                        c = d;

                        d = d->next;
                    }
                }

                else
                {

                    if (b == root)
                    {

                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;

                        r = b;
                        b = d;
                        d = r;

                        c = d;

                        d = d->next;

                        root = b;
                    }

                    else
                    {

                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
                        a->next = d;

                        r = b;
                        b = d;
                        d = r;

                        c = d;

                        d = d->next;
                    }
                }
            }
            else
            {

                c = d;
                d = d->next;
            }
        }

        a = b;
        b = b->next;
    }

    return root;
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
    root = selectionSort(root);
    printArr(root);
}