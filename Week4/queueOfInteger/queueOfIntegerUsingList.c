#include <stdio.h>
#include <stdlib.h>
typedef struct nodeStruct
{
    int value;
    struct nodeStruct *next;
} * node;
typedef struct queueStruct
{
    node front;
    node rear;
} * queue;
int count = 0;
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
    printf("Input the value of the node : ");
    scanf("%d%*c", &val);
    node temp;
    temp = (node)malloc(sizeof(struct nodeStruct));
    temp->value = val;
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
    printf("Value : %d has been removed from the queue \n", temp->value);
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
        printf(" %d \n", temp->value);
    }
}
int main()
{
    queue q;
    q = (queue)malloc(sizeof(struct queueStruct));
    MakeNullQueue(q);
    int n;
    node temp;
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
        // case 4:
        // {
        //     readFileToQueue(q);
        //     break;
        // }
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