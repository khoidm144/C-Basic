//7h15
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct dataStruct
{
    char class[10];
    char course[10];
    char location[30];
} nodeData;
typedef struct nodeStruct
{
    nodeData data;
    struct nodeStruct *next;
} * node;

node makeNode(nodeData input)
{
    node temp = (node)malloc(sizeof(struct nodeStruct));
    temp->data = input;
    temp->next = NULL;
    return temp;
}
node read(node head)
{
    FILE *input = fopen("Schedule.txt", "r+");
    char s[10];
    nodeData temp;
    fscanf(input, "%[^\n]%*c", temp.class);
    fscanf(input, "%[^\n]%*c", temp.course);
    fscanf(input, "%[^\n]%*c", temp.location);
    head = makeNode(temp);
    node p = head;
    while (!feof(input))
    {
        if (fscanf(input, "%[^\n]%*c", s) <= 0)
        {
            break;
        }
        strcpy(temp.class, s);
        fscanf(input, "%[^\n]%*c", temp.course);
        fscanf(input, "%[^\n]%*c", temp.location);
        p->next = makeNode(temp);
        p = p->next;
    }
    return head;
}
void traverse(node head)
{
    for (node temp = head; temp != NULL; temp = temp->next)
    {
        printf("%s %s %s\n", temp->data.class, temp->data.course, temp->data.location);
    }
}
node search(node head, char *course)
{
    node p = head;
    while (1)
    {
        if (p == NULL)
        {
            return NULL;
        }
        if (strcmp(p->data.course, course) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
node delete (node head, char *class)
{
    node p = head;
    if (head == NULL)
    {
        return head;
    }
    if (strcmp(p->data.class, class) == 0)
    {
        printf("ok");
        head = head->next;
        free(p);
        return head;
    }
    while (p->next != NULL)
    {
        if (strcmp(p->next->data.class, class) == 0)
        {
            node temp = p->next;
            p->next = p->next->next;
            free(temp);
            return head;
        }
        p = p->next;
    }
    return head;
}
node reOrderList(node head, node newHead)
{
    node p = head;
    newHead = makeNode(head->data);
    p = p->next;
    node newP = newHead;
    while (p != NULL)
    {
        newP = newHead;
        if (strcmp(p->data.class, newHead->data.class) <= 0)
        {
            node temp;
            temp = makeNode(p->data);
            temp->next = newHead;
            newHead = temp;
        }
        else
        {
            newP = newHead;
            node toInsert;
            int flag = 0;
            if (newP->next == NULL)
            {
                newP->next = makeNode(p->data);
                p=p->next;
               continue;
            }
            while (strcmp(p->data.class, newP->next->data.class) > 0)
            {
                flag = 0;
                if (newP->next == NULL)
                {
                    newP->next = makeNode(p->data);
                    flag = 1;
                    break;
                }
                newP = newP->next;
            }
            if (flag == 1)
            {
                continue;
            }
            else
            {
                node temp = makeNode(p->data);
                temp->next = newP->next;
                newP->next = temp;
            }
        }
        p = p->next;
    }
    return newHead;
}
int main()
{
    node head = NULL;
    int choice;
    node secondHead = NULL;
    char list[10][20];
    while (1)
    {
        printf("1.Read file\n");
        printf("2.Traverse \n");
        printf("3.Search \n");
        printf("4.Delete \n");
        printf("5.Order the class\n");
        printf("6.Count class \n");
        printf("Choice : ");
        scanf("%d%*c", &choice);
        switch (choice)
        {
        case 1:
        {
            head = read(head);
            break;
        }
        case 2:
        {
            traverse(head);
            break;
        }
        //7h35 : spend 20 mins
        case 3:
        {
            char str[20];
            node toSearch;
            printf("Input the course code you want to search for: ");
            scanf("%[^\n]%*c", str);
            toSearch = search(head, str);
            if (toSearch == NULL)
            {
                printf("Not Found !\n");
            }
            else
            {
                printf("%s %s %s\n", toSearch->data.class, toSearch->data.course, toSearch->data.location);
            }
            break;
        }
        case 4:
        {
            char str[20];
            node toDelete;
            printf("Input the class code you want to delete: ");
            scanf("%[^\n]%*c", str);
            head = delete (head, str);
            traverse(head);
            break;
        }
        case 5:
        {
            head = reOrderList(head, secondHead);
            traverse(head);

            break;
        }
        case 6:
        {
            strcpy(list[0], head->data.course);
            int index1 = 0;
            int flag = 0;
            for (node temp = head; temp != NULL; temp = temp->next)
            {
                flag = 0;
                for (int i = 0; i < index1; i++)
                {
                    if (strcmp(list[i], temp->data.course) == 0)
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    strcpy(list[index1++], temp->data.course);
                }
            }
            int count[index1];
             for(int i=0;i<index1;i++){
                count[i]=0;
            }
            for (node temp = head; temp != NULL; temp = temp->next)
            {
                for (int i = 0; i < index1; i++)
                {
                    if (strcmp(list[i], temp->data.course) == 0)
                    {
                        count[i]++;
                        break;
                    }
                }
            }
            for(int i=0;i<index1;i++){
                printf("%s %d\n",list[i],count[i]);
            }
        }
        }
    }
}