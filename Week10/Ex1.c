#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
typedef struct AddressStruct
{
    char name[30];
    char email[30];
    struct AddressStruct *leftChild;
    struct AddressStruct *rightChild;
} * node;
node nodeArr[M];
int index1 = 0;
int hash(char *s)
{
    // hash function
    int rs = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        rs = (rs * 255 + s[i]) % M;
    return rs;
}
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
node freeTree(node root)
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
    // node root = NULL;
    int tempIndex = 0;
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
                tempIndex = hash(name);
                nodeArr[tempIndex] = insert(nodeArr[tempIndex], name, email);
            }
            rewind(input);
            break;
        }
        case 2:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            tempIndex = hash(str);
            temp = find(nodeArr[tempIndex], str);
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
            tempIndex = hash(name);
            nodeArr[tempIndex] = insert(nodeArr[tempIndex], name, email);
            break;
        }
        case 4:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            tempIndex = hash(str);
            nodeArr[tempIndex] = removeStudent(nodeArr[tempIndex], str);
            break;
        }
        case 5:
        {
            for (int i = 0; i < M; i++)
                display(nodeArr[i]);
            break;
        }
        case 6:
        {
            for (int i = 0; i < M; i++)
                nodeArr[i] = freeTree(nodeArr[i]);
            break;
        }
        case 7:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            tempIndex = hash(str);
            printf("%d", tempIndex);
            break;
        }
        }
    }
    return 0;
}