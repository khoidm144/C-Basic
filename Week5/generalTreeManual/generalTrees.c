#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[30];
    struct node *leftMostChild;
    struct node *rightSibling;
} * node;
node root;
node p;
void traverseTree(node p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%s\n", p->name);
    traverseTree(p->leftMostChild);
    traverseTree(p->rightSibling);
}
node makeNode(char *name)
{
    node temp = (node)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    temp->leftMostChild = NULL;
    temp->rightSibling = NULL;
    return temp;
}
node find(char *name, node cur)
{
    if (cur == NULL)
    {
        return NULL;
    }
    if (strcmp(name, cur->name) == 0)
    {
        return cur;
    }
    node temp;
    temp = find(name, cur->leftMostChild);
    if (temp != NULL)
    {
        return temp;
    }
    temp = find(name, cur->rightSibling);
    if (temp != NULL)
    {
        return temp;
    }
}
void addLast(char *name, node p)
{
    node temp = makeNode(name);
    p->rightSibling = temp;
}
void movePointer()
{
    char name[30];
    printf("Input the name of the node you  want to move to : ");
    scanf("%[^\n]%*c", name);
    node temp = find(name, root);
    if (temp == NULL)
    {
        printf("No !");
    }
    else
    {
        p = temp;
    }
}
void addNodeChild(char *name, node cur)
{
    node temp = makeNode(name);
    if (cur->leftMostChild == NULL)
    {
        cur->leftMostChild = temp;
        return;
    }
    node p = cur->leftMostChild;
    while (p->rightSibling != NULL)
    {
        p = p->rightSibling;
    }
    p->rightSibling = temp;
}
int height( node root)
{
    if(root==NULL){
        return 0;
    }
    int max=0;
    node p=root->leftMostChild;
    while(p!=NULL){
        int temp=height(p);
        max= max > temp ? max : temp;
        p=p->rightSibling;
    } 
    return max+1;
}
int main()
{
    root = makeNode("rootContent");
    int n;
    p = root;
    char name[30];
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Move pointer\n");
        printf("2.Print all nodes \n");
        printf("3.Add next to Pointer\n");
        printf("4.Print the content of Pointer\n");
        printf("5.Add Child to Pointer\n");
        printf("6.Exit \n");
        printf("Choice : ");
        scanf("%d%*c", &n);
        switch (n)
        {
        case 1:
        {
            movePointer();
            break;
        }
        case 2:
        {
            traverseTree(root);
            printf("Height : %d\n",height(root));
            break;
        }
        case 3:
        {
            printf("Input the content  of the node : ");
            scanf("%[^\n]%*c", name);
            addLast(name, p);
            break;
        }
        case 4:
        {
            printf("%s\n", p->name);
            break;
        }
        case 5:
        {
            printf("Input the content  of the node : ");
            scanf("%[^\n]%*c", name);
            addNodeChild(name, p);
            break;
        }
        }
    }
}
