#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct AddressStruct
{
    char name[30];
    char email[30];
    struct AddressStruct *leftChild;
    struct AddressStruct *rightChild;
} * node;
int index1 = 0;
node makeNode(char *name, char *email)
{
    node temp = (node)malloc(sizeof(struct AddressStruct));
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}
void display(node root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->leftChild);
    printf("%s %s\n", root->name, root->email);
    display(root->rightChild);
}
node insert(node root, char *name, char *email)
{
    if (root == NULL)
    {
        return makeNode(name, email);
    }
    int cmp = strcmp(name, root->name);
    if (cmp == 0)
    {
        return root;
    }
    else if (cmp > 0)
    {
        root->rightChild = insert(root->rightChild, name, email);
        return root;
    }
    else
    {
        root->leftChild = insert(root->leftChild, name, email);
        return root;
    }
}
node find(node root, char *name)
{
    if (root == NULL)
    {
        return NULL;
    }
    int cmp = strcmp(name, root->name);
    if (cmp == 0)
    {
        return root;
    }
    else if (cmp > 0)
    {
        return find(root->rightChild, name);
    }
    else
    {
        return find(root->leftChild, name);
    }
}
node findMin(node root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->leftChild == NULL)
    {
        return root;
    }
    return findMin(root->leftChild);
}
node freeTree(node  root)
{
    if (root == NULL)
    {
        return root;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root);
    return NULL;
}
node removeStudent(node root, char *name)
{
    if (root == NULL)
    {
        return NULL;
    }
    int cmp = strcmp(name, root->name);
    if (cmp > 0)
    {
        root->rightChild = removeStudent(root->rightChild, name);
        return root;
    }
    else if (cmp < 0)
    {
        root->leftChild = removeStudent(root->leftChild, name);
        return root;
    }
    else
    {
        if (root->leftChild != NULL && root->rightChild != NULL)
        {
            node temp = findMin(root->rightChild);
            strcpy(root->name, temp->name);
            strcpy(root->email, temp->email);
            root->rightChild = removeStudent(root->rightChild, temp->name);
        }
        else
        {
            node temp = root;
            if (root->leftChild == NULL)
            {
                root = root->rightChild;
            }
            else
            {
                root = root->leftChild;
            }
            free(temp);
        }
    }
    return root;
}
int main()
{
    int choice;
    int n;
    FILE *input = fopen("data.txt", "r");
    char name[20];
    char email[30];
    node temp;
    int index = 0;
    node root = NULL;
    while (1)
    {
        printf("1.Load \n");
        printf("2.Find \n");
        printf("3.Insert \n");
        printf("4.Remove \n");
        printf("5.Display \n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
        {
            while (!feof(input))
            {
                if (fscanf(input, "%[^\n]%*c", name) == EOF)
                {
                    break;
                }
                fscanf(input, "%[^\n]%*c", email);
                root = insert(root, name, email);
            }
            break;
        }
        case 2:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            temp = find(root, str);
            if (temp == NULL)
            {
                printf("Not found ! \n");
                break;
            }
            printf("Name : %s Email: %s\n", temp->name, temp->email);
            break;
        }
        case 3:
        {
            printf("Input the name : ");
            scanf("%[^\n]%*c", name);
            printf("Input the email : ");
            scanf("%[^\n]%*c", email);
            root = insert(root, name, email);
            break;
        }
        case 4:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            root = removeStudent(root, str);
            break;
        }
        case 5:
        {
            display(root);
            break;
        }
        case 6:
        {
            root=freeTree(root);
            break;
        }
        }
    }
    return 0;
}