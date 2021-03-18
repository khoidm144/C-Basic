#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct nodeStruct
{
    char time[30];
    char place[20];
    char people[20];
    char des[20];
    struct nodeStruct *next;
} * node;
typedef struct queueStruct
{
    node front;
    node rear;
} * queue;
int count = 0;
char *getTime()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    static char s[30];
    strcpy(s, asctime(timeinfo));
    s[strlen(s) - 1] = '\0';
    return s;
}
void MakeNullQueue(queue q)
{
    node temp;
    temp = (node)malloc(sizeof(struct nodeStruct));
    temp->next = NULL;
    temp = NULL;
    q->front = temp;
    q->rear = temp;
}
node createNode()
{
    int val;
    node temp;
    temp = (node)malloc(sizeof(struct nodeStruct));
    strcpy(temp->time, getTime());
    printf("Input the value of 'place' : ");
    scanf("%[^\n]%*c", temp->place);
    printf("Input the value of 'people' : ");
    scanf("%[^\n]%*c", temp->people);
    printf("Input the value of 'description' : ");
    scanf("%[^\n]%*c", temp->des);
    temp->next = NULL;
    return temp;
}
node deQueue(queue q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    if (count == 1)
    {
        node temp = q->front;
        q->front = NULL;
        q->rear = NULL;
        return temp;
    }
    node temp = q->front;
    q->front = q->front->next;
    return temp;
}
void printOne(node temp)
{
    if (temp == NULL)
    {
        return;
    }
    printf(" %s %s %s %s  \n", temp->time, temp->people, temp->place, temp->des);
}
void enQueue(queue q)
{
    node temp = createNode();
    if (q->front == NULL)
    {
        q->front = temp;
        q->rear = temp;
        count = 1;
        return;
    }
    if (q->front->next == NULL)
    {
        q->rear = temp;
        q->front->next = q->rear;
        count = 2;
        return;
    }
    if (count == 5)
    {
        printOne(deQueue(q));
        q->rear->next = temp;
        q->rear = q->rear->next;
        return;
    }
    q->rear->next = temp;
    q->rear = q->rear->next;
    count++;
    return;
}
void printAll(node root)
{
    if (root == NULL)
    {
        return;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf(" %s %s %s %s  \n", temp->time, temp->people, temp->place, temp->des);
    }
}
void modifyNode(queue q, int index)
{
    if (index == 0)
    {
    }
}
int main()
{
    queue q;
    q = (queue)malloc(sizeof(struct queueStruct));
    MakeNullQueue(q);
    int n;
    node temp;
    printf("%s", getTime());
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Enqueue\n");
        printf("2.Print all nodes \n");
        printf("3.Dequeue\n");
        printf("4.Freelist\n");
        printf("5.Reverset \n");
        printf("6.Exit\n");
        printf("Choice : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n)
        {
        case 1:
        {
            enQueue(q);
            break;
        }
        case 2:
        {
            printAll(q->front);
            break;
        }
        case 3:
        {
            printOne(deQueue(q));
            break;
        }
        case 4:
        {
            int index;
            printf("Input the value of the index you want to modify: ");
            scanf("%d%*c", &index);
            modifyNode(q, index);
            break;
        }
        // case 5:
        // {
        //     front = reverse(front);
        //     break;
        // }
        case 6:
        {
            MakeNullQueue(q);
            break;
        }
        }
    }
    return 0;
}