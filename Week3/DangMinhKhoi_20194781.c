#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct productStruct
{
    char id[20];
    char name[80];
    int price;
    // address *next;
} product;
typedef struct productList
{
    struct productList *next;
    struct productList *prev;
    product prod;
} * node;
node root, tail;
int count = 0;
node createNode()
{
    node temp;
    char name[80];
    int price;
    char id[20];
    printf("Input the id: ");
    scanf("%[^\n]%*c", id);
    printf("Input the name: ");
    scanf("%[^\n]%*c", name);
    printf("Input the price: ");
    scanf("%d%*c", &price);
    temp = (node)malloc(sizeof(struct productList));
    strcpy(temp->prod.name, name);
    temp->prod.price = price;
    strcpy(temp->prod.id, id);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void printAllFromHead()
{
    if (root == NULL)
    {
        return;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %s %d\n", temp->prod.id, temp->prod.name, temp->prod.price);
    }
}
void printAllFromTail()
{
    if (tail == NULL)
    {
        return;
    }
    for (node temp = tail; temp != NULL; temp = temp->prev)
    {
        printf("%s %s %d\n", temp->prod.id, temp->prod.name, temp->prod.price);
    }
}
void insertAtTail()
{
    node temp = createNode();
    if (tail == NULL)
    {
        root = temp;
        tail = temp;
        count++;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    count++;
}
node searchByID(node root, char *id)
{
    if (root == NULL)
    {
        printf("Empty List ! \n");
        return root;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        if (strcmp(id, temp->prod.id) == 0)
        {
            return temp;
        }
    }
    return NULL;
}
void freeList()
{
    node p = root;
    while (root != NULL)
    {
        root = p->next;
        free(p);
        p = root;
    }
    tail = NULL;
    count = 0;
    return;
}
int main()
{

    root = NULL;
    tail = NULL;
    char id[20];
    int n;
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Insert to Tail\n");
        printf("2.Print all nodes \n");
        printf("3.Search by ID\n");
        printf("4.Freelist\n");
        printf("5.Exit \n");
        printf("Choice : ");
        scanf("%d%*c", &n);
        switch (n)
        {
        case 1:
        {
            insertAtTail();
            break;
        }
        case 2:
        {
            printf("Traverse from Head to Tail: \n");
            printAllFromHead();
            printf("Traverse from Tail to Head: \n");
            printAllFromTail();
            break;
        }
        case 3:
        {
            node temp;
            printf("Input the ID you want to search: ");
            scanf("%[^\n]%*c", id);
            temp = searchByID(root, id);
            if (temp == NULL)
            {
                printf("Not found ! \n");
            }
            else
            {
                printf("%s %s %d\n", temp->prod.id, temp->prod.name, temp->prod.price);
            }
            break;
        }
        case 4:
        {
            freeList();
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    }
    return 0;
}
