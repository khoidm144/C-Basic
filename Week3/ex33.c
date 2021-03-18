#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char id[10];
    char name[30];
    int grade;
} student;
typedef struct studentList
{
    struct studentList *next;
    student stu;
} * node;
node createNode()
{
    char name[20];
    int grade;
    char id[10];
    printf("Input the id of the Student: \n");
    scanf("%[^\n]%*c", id);
    printf("Input the name of the Student: \n");
    scanf("%[^\n]%*c", name);
    printf("Input the grade of the Student: \n");
    scanf("%d%*c", &grade);
    node temp;
    temp = (node)malloc(sizeof(struct studentList));
    strcpy(temp->stu.name, name);
    temp->stu.grade = grade;
    strcpy(temp->stu.id, id);
    temp->next = NULL;
    return temp;
}
void printAll(node root)
{
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %s %d\n", temp->stu.id, temp->stu.name, temp->stu.grade);
    }
}
void printOne(node temp)
{
    if (temp == NULL)
    {
        return;
    }
    printf("%s %s %d\n", temp->stu.id, temp->stu.name, temp->stu.grade);
}
node insertInOrder(node root)
{
    if (root == NULL)
    {
        root = createNode();
        return root;
    }
    node p = root;
    node temp = createNode();
    int grade = temp->stu.grade;
    if (grade >= (root->stu.grade))
    {
        root = temp;
        root->next = p;
        return root;
    }
    //int a=p->next->stu.grade;
    int count = 0;
    node prev = root;
    int check = 0;
    while (p->stu.grade > grade && p->next != NULL)
    {
        prev = p;
        p = p->next;
        if (p->stu.grade <= grade)
        {
            check = 1;
        }
        count++;
    }
    if (p->next == NULL && check == 0)
    {
        p->next = temp;
        return root;
    }
    prev->next = temp;
    temp->next = p;
    // node cur = p->next;
    // p->next = temp;
    // p->next->next = cur;
    return root;
}
node searchByID(node root, char *id)
{
    if (root == NULL)
    {
        printf("No\n");
        return root;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        if (strcmp(id, temp->stu.id) == 0)
        {
            printf("%s %s %d\n", temp->stu.id, temp->stu.name, temp->stu.grade);
            return temp;
        }
    }
    return NULL;
}
node deleteByID(node root, char *id)
{
    if (root == NULL)
    {
        printf("No\n");
        return root;
    }
    if (strcmp(id, root->stu.id) == 0)
    {
        root = root->next;
        return root;
    }
    node prev = root;
    for (node temp = root; temp != NULL;)
    {
        if (strcmp(id, temp->stu.id) == 0)
        {
            prev->next = temp->next;
            return root;
        }
        prev = temp;
        temp = temp->next;
    }
    return root;
}
node changeGrade(node root, node toChange, int grade)
{
    char name[20];
    strcpy( name,toChange->stu.name);
    char id[10];
    strcpy(id,toChange->stu.id);
    root = deleteByID(root, id);
    node temp;
    temp = (node)malloc(sizeof(struct studentList));
    strcpy(temp->stu.name, name);
    temp->stu.grade = grade;
    strcpy(temp->stu.id, id);
    temp->next = NULL;
    node p = root;
    if (grade <= (root->stu.grade))
    {
        root = temp;
        root->next = p;
        return root;
    }
    int count = 0;
    node prev = root;
    int check = 0;
    while (p->stu.grade < grade && p->next != NULL)
    {
        prev = p;
        p = p->next;
        if (p->stu.grade >= grade)
        {
            check = 1;
        }
        count++;
    }
    if (p->next == NULL && check == 0)
    {
        p->next = temp;
        return root;
    }
    prev->next = temp;
    temp->next = p;
    return root;
}

int main()
{
    node root;
    root = (node)malloc(sizeof(struct studentList));
    root = NULL;
    int n;
    char name[20];
    int grade;
    char id[10];
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Insert to List\n");
        printf("2.Print all nodes \n");
        printf("3.Searching\n");
        printf("4.Delete by ID\n");
        printf("5.Change the grade \n");
        printf("6.Exit \n");
        printf("Choice : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n)
        {
        case 1:
        {    
                root = insertInOrder(root);
            break;
        }
        case 2:
        {
            printAll(root);
            break;
        }
        case 3:
        {
            char st[10];
            printf("Input the id that you want to search: ");
            scanf("%[^\n]%*c", st);
            printOne(searchByID(root, st));
            break;
        }
        case 4:
        {
            char st[10];
            printf("Input the id of the Student: \n");
            scanf("%[^\n]%*c", st);
            root = deleteByID(root, st);
            break;
        }
        case 5:
        {
            char st[10];
            printf("Input the id that you want to modify grade: ");
            scanf("%[^\n]%*c", st);
            printf("Input the new grade: ");
            scanf("%d%*c", &grade);
            node temp1 = searchByID(root, st);
            if (temp1 == NULL)
            {
                break;
            }
            else
            {
                root = changeGrade(root, temp1, grade);
            }
            break;
        }
        case 6:
        {

            break;
        }
        }
    }
    return 0;
}