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
node addLast(char *name, node p)
{
    if (p == NULL)
    {
        return makeNode(name);
    }
    p->rightSibling = addLast(name, p->rightSibling);
    return p;
}
void addNodeChild(char *name, char *child)
{
   node p = find(name, root);
    if (p == NULL)
    {   
        return;
    }
    p->leftMostChild = addLast(child, p->leftMostChild);
    return;
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
void loadFromFile()
{
    FILE *input = fopen("family.txt", "r");
    char s[20] = "";
    fscanf(input, "%s", s);
    root = makeNode(s);
    node p = root;
    rewind(input);
    int flag = 0;
    while (1)
    {
        fscanf(input, "%s", s);
        if (strcmp(s, "$$") == 0)
        {
            break;
        }
        p = find(s, root);
        while (1)
        {
            fscanf(input, "%s", s);
            if (strcmp(s, "$") == 0)
            {
                break;
            }
            addNodeChild(p->name,s);
        }
    }
}
int main()
{
    int n;
    node p = root;
    char name[30];
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Load from file \n");
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
            loadFromFile();
            break;
        }
        case 2:
        {
            traverseTree(root);
            printf("Height : %d\n", height( root));
            break;
        }
        case 3:
        {
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
