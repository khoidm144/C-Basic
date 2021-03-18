#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address
{
    char name[20];
    int tel;
    char email[30];
} address;
typedef struct addressList
{
    struct addressList *next;
    address addr;
} * node;
node createNode()
{
    char name[20];
    int tel;
    char email[30];
    printf("Input the name: ");
    scanf("%[^\n]", name);
    printf("Input the tel: ");
    scanf("%d%*c", &tel);
    printf("Input the email: ");
    scanf("%[^\n]", email);
    node temp;
    temp = (node)malloc(sizeof(struct addressList));
    strcpy(temp->addr.name, name);
    temp->addr.tel = tel;
    strcpy(temp->addr.email, email);
    temp->next = NULL;
    return temp;
}
node insertionToHead(node root)
{
    node temp = createNode();
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        temp->next = root;
        root = temp;
        return root;
    }
}
void printAll(node root)
{
    if (root == NULL)
    {
        printf("Empty List ! \n");
        return;
    }
    printf("Name                 Tel        Email                             \n");
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%-20s %-10d %-30s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
    }
}
node searchByName(node root, char *name)
{
    if (root == NULL)
    {
        return root;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        if (strcmp(name, temp->addr.name) == 0)
        {
            return temp;
        }
    }
    return NULL;
}
node freeList(node root)
{
    node p = root;
    while (root != NULL)
    {
        root = p->next;
        free(p);
        p = root;
    }
    return root;
}
node reverse(node root)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->next == NULL)
    {
        return root;
    }
    node newHead = reverse(root->next);
    root->next->next = root;
    root->next = NULL;
    return newHead;
}
int main()
{
    node root;
    root = (node)malloc(sizeof(struct addressList));
    root = NULL;
    int n;
    char name[20];
    int tel;
    char email[30];
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Insert at Head\n");
        printf("2.Print all nodes \n");
        printf("3.Search by name \n");
        printf("4.Reverse\n");
        printf("5.Freelist\n");
        printf("6.Exit\n");
        printf("Choice : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n)
        {
        case 1:
        {
            root = insertionToHead(root);
            break;
        }
        case 2:
        {
            printAll(root);
            break;
        }
        case 3:
        {

            node temp;
            printf("Input the name you want to search: ");
            scanf("%[^\n]%*c", name);
            temp = searchByName(root, name);
            if (temp == NULL)
            {
                printf("Not found ! \n");
            }
            else
            {
                printf("Name                 Tel        Email                             \n");
                printf("%-20s %-10d %-30s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
            }

            break;
        }
        case 4:
        {
            root = reverse(root);
            break;
        }
        case 5:
        {
            root = freeList(root);
            break;
        }
        case 6:
        {
            return 0;
        }
        }
    }
    return 0;
}