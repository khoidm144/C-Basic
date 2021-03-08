#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address
{
    char name[20];
    int tel;
    char email[30];
    // address *next;
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
node insertionToTail(node root)
{
    node temp = createNode();
    node p;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        p = root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return root;
}
void printAll(node root)
{
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %d %s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
    }
}
node removeAt(node root, int index)
{
    int count = 0;
    node p = root;
    if (index == 0)
    {
        root = p->next;
        free(p);
        return root;
    }
    while (count != index - 1)
    {
        p = p->next;
        count++;
    }
    printf("%d", count);
    p->next = p->next->next;
    return root;
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
        printf("1.Insert to Tail\n");
        printf("2.Print all nodes \n");
        printf("3.Delete a node\n");
        printf("4.Freelist\n");
        printf("5.Exit \n");
        printf("Choice : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n)
        {
        case 1:
        {
            root = insertionToTail(root);
            break;
        }
        case 2:
        {
            printAll(root);
            break;
        }
        case 3:
        {
            int index;
            printf("Input the index (from 0 index) of the node you want to remove: ");
            scanf("%d%*c", &index);
            root = removeAt(root, index);
            break;
        }
        case 4:
        {
            root = freeList(root);
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