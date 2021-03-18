#include <stdio.h>
#include <stdlib.h>
#define max_length 5
typedef struct nodeStruct
{
    int value;
} node;
typedef struct queueStruct
{
    node arr[max_length+5];
    int front;
    int rear;
} * queue;
int count = 0;
void MakeNullQueue(queue q)
{
    q->front = -1;
    q->rear = -1;
}
node createNode()
{
    int val;
    printf("Input the value of the node : ");
    scanf("%d%*c", &val);
    node temp;
    temp.value = val;
    return temp;
}
void deQueue(queue q)
{
    if (count == 0)
    {
        return;
    }
    printf("The value %d has been removed from the queue \n", q->arr[q->front]);
    q->front = q->front + 1;
    if (q->front > q->rear)
    {
        MakeNullQueue(q);
    }
    count--;
    return;
}
void enQueue(queue q)
{
    node temp = createNode();
    if (count == 0)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[0] = temp;
        count = 1;
        return;
    }
    if (q->rear == 0)
    {
        q->rear = 1;
        q->arr[1] = temp;
        count = 2;
        return;
    }
    if (count == max_length)
    {
        deQueue(q);
        q->rear = q->rear + 1;
        q->arr[q->rear] = temp;
        count=max_length;
        return;
    }
    q->rear = q->rear + 1;
    q->arr[q->rear] = temp;
    count++;
    return;
}
void printAll(queue q)
{
    if (count == 0)
    {
        return;
    }
    for (int i = q->front; i < q->front+count; i++)
    {
        printf("%d \n", q->arr[i]);
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
            printAll(q);
            break;
        }
        case 3:
        {
            deQueue(q);
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