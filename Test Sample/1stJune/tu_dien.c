#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DictionaryStruct
{
    char english[20];
    char vietnamese[30];
    struct DictionaryStruct *leftChild;
    struct DictionaryStruct *rightChild;
} * node;
int index1 = 0;
node makeNode(char *english, char *vietnamese)
{
    node temp = (node)malloc(sizeof(struct DictionaryStruct));
    strcpy(temp->english,english);
    strcpy(temp->vietnamese, vietnamese);
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
    printf("%s \n", root->english);
    display(root->rightChild);
}
node insert(node root, char *english, char *vietnamese)
{
    if (root == NULL)
    {
        return makeNode(english, vietnamese);
    }
    int cmp = strcmp(english, root->english);
    if (cmp == 0)
    {
        return root;
    }
    else if (cmp > 0)
    {
        root->rightChild = insert(root->rightChild, english, vietnamese);
        return root;
    }
    else
    {
        root->leftChild = insert(root->leftChild, english, vietnamese);
        return root;
    }
}
node find(node root, char *english)
{
    if (root == NULL)
    {
        return NULL;
    }
    printf("Traverse through: %s\n", root->english);
    int cmp = strcmp(english, root->english);
    if (cmp == 0)
    {
        return root;
    }
    else if (cmp > 0)
    {
        return find(root->rightChild, english);
    }
    else
    {
        return find(root->leftChild, english);
    }
}


int main(int argc, char *argv[])
{
    int choice;
    int n;
    FILE *input = fopen(argv[1], "r+");
    char english[20];
    char vietnamese[30];
    node temp;
    int index = 0;
    node root = NULL;
    if(input==NULL){
        printf("The input file not found ! Preparing to Exit ! \n");
        return 0;
    }
    while (!feof(input))
    {
        if (fscanf(input, "%s%*c", english) == EOF)
        {
            break;
        }
        fscanf(input, "%[^\n]%*c", vietnamese);
        printf("Reading: %s %s \n", english, vietnamese);
        root = insert(root, english, vietnamese);
    }
    while (1)
    {
        printf("1.Traverse \n");
        printf("2.Insert new word to the dictionary\n");
        printf("3.Translate \n");
        printf("4.Exit\n");
        printf("Choice: ");
        scanf("%d%*c", &choice);
        switch (choice)
        {
        case 1:
        {
            display(root);
            break;
        }
        case 2:
        {
            printf("Input the English key word : ");
            scanf("%[^\n]%*c", english);
            printf("Input the Vietnamese meaning : ");
            scanf("%[^\n]%*c", vietnamese);
            root = insert(root, english, vietnamese);
            break;
        }
        case 3:
        {
            char str[30];
            printf("Input the English word you want to translate : ");
            scanf("%[^\n]%*c", str);
            temp = find(root, str);
            if (temp == NULL)
            {
                printf("Khong tim thay tu can tra ! \n");
                break;
            }
            printf("Tu can tra: %s in Vietnamese: %s\n", temp->english, temp->vietnamese);
            break;
        }
        case 4:{
            return 0;
        }
        }
    }
    fclose(input);
    return 0;
}