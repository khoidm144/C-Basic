#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
} * node;
node root;
node p;
void traverseTree(node p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d\n", p->data);
    traverseTree(p->leftChild);
    traverseTree(p->rightChild);
}
node makeNode(int new)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->data = new;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}
node find(int new, node cur)
{

    if (cur == NULL)
    {
        return NULL;
    }
    if (new == cur->data)
    {
        return cur;
    }
    node p;
    p = find(new, cur->leftChild);
    if (p != NULL)
    {
        return p;
    }
    p = find(new, cur->rightChild);
    if (p != NULL)
    {
        return p;
    }
}
void addRightChild(int cur, int new)
{
    node temp = find(cur, root);
    if (temp == NULL)
    {
        printf("Parent nodes doesn't exist ! \n");
        return;
    }
    if (temp->rightChild != NULL)
    {

        printf("Nodes to add is not empty ! \n");
        return;
    }
    temp->rightChild = makeNode(new);
}
void clearBuffer()
{
    char c;
    while ((c = getchar() != '\n') && c != EOF)
        ;
}
void addLeftChild(int cur, int new)
{
    node temp = find(cur, root);
    if (temp == NULL)
    {
        printf("Parent nodes doesn't exist ! \n");
        return;
    }
    if (temp->leftChild != NULL)
    {

        printf("Nodes to add is not empty ! \n");
        return;
    }
    temp->leftChild = makeNode(new);
}
int height(node root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}
int main()
{
    root = makeNode(100);
    int n;
    p = root;
    int data;
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Print all nodes \n");
        printf("2.Add right node\n");
        printf("3.Add left node\n");
        printf("4.Print the content of Pointer\n");
        printf("5.Add Child to Pointer\n");
        printf("6.Exit \n");
        printf("Choice : ");
        scanf("%d%*c", &n);
        switch (n)
        {
        case 1:
        {
            traverseTree(root);
            printf("Height : %d\n", height(root));
            break;
        }
        case 2:
        {
            int temp;
            printf("Input the data of the parent node and rightNode of it :");
            scanf("%d %d", &temp, &data);
            addRightChild(temp, data);
            break;
        }
        case 3:
        {
            int temp;
            printf("Input the data of the parent node and leftNode of it :");
            scanf("%d %d", &temp, &data);
            addLeftChild(temp, data);
            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {

            break;
        }
        }
    }
}
