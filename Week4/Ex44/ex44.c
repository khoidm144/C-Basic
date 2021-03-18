#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address
{
    char name[20];
    int tel;
    char email[30];
} address;
typedef struct addressList
{
    struct addressList *next;
    address addr;
} * node;
typedef struct queueStruct
{
    node front;
    node rear;
} * queue;
int count = 0;
node createNode()
{
    char name[20];
    int tel;
    char email[30];
    printf("Input the name: ");
    scanf("%[^\n]", name);
    printf("Input the tel: ");
    scanf("%d%*c", &tel);
    printf("Input the email: ");
    scanf("%[^\n]", email);
    node temp;
    temp = (node)malloc(sizeof(struct addressList));
    strcpy(temp->addr.name, name);
    temp->addr.tel = tel;
    strcpy(temp->addr.email, email);
    temp->next = NULL;
    return temp;
}
void MakeNullQueue(queue q)
{
    node temp;
    temp = (node)malloc(sizeof(struct addressList));
    temp->next = NULL;
    q->front = temp;
    q->rear = temp;
}
int isEmpty(queue q)
{
    return count == 0;
}
void enQueue(queue q)
{
    node temp = createNode();
    if (count == 0)
    {
        MakeNullQueue(q);
        q->front = temp;
        q->rear = temp;
        count = 1;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    if (count == 1)
    {
        q->front->next = temp;
    }
    count++;
    return;
}
node deQueue(queue q)
{
    if (count == 0)
    {
        return NULL;
    }
    if (count == 1)
    {
        node temp = q->front;
        q->front = NULL;
        q->rear = NULL;
        count = 0;
        return temp;
    }
    node temp = q->front;
    q->front = q->front->next;
    count--;
    return temp;
}
void printAll(node root)
{
    if (root == NULL || count == 0)
    {
        return;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %d %s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
    }
}
void printOne(node temp)
{
    if (temp == NULL)
    {
        return;
    }
    printf("%s %d %s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
}
void readFileToQueue(queue q)
{
    FILE *input, *output;
    char name[20];
    int tel;
    char email[30];
    input = fopen("data.txt", "r");
    output = fopen("dataOut.txt", "w+");
    while (!feof(input))
    {
        node temp = (node)malloc(sizeof(struct addressList));
        temp->next = NULL;
        if (fscanf(input, "%[^\n]%*c", name) == EOF)
        {
            printf("1");
            break;
        }
        strcpy(temp->addr.name, name);
        fscanf(input, "%d%*c", &tel);
        temp->addr.tel = tel;
        fscanf(input, "%[^\n]%*c", email);
        strcpy(temp->addr.email, email);
        //printf("%s %d %s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
        if (count == 0)
        {
            MakeNullQueue(q);
            q->front = temp;
            q->rear = temp;
            count = 1;
            continue;
        }
        else if (count == 1)
        {
            q->rear = temp;
            q->rear->next = NULL;
            q->front->next = q->rear;
            count = 2;
            continue;
        }
        else
        {
            q->rear->next = temp;
            q->rear = q->rear->next;
            q->rear->next = NULL;
            count++;
        }
    }
    q->rear->next = NULL;
    fclose(input);
    fclose(output);
}
int main()
{
    // node front;
    // node rear;
    // front = (node)malloc(sizeof(struct addressList));
    // front = NULL;
    // rear = (node)malloc(sizeof(struct addressList));
    // rear = NULL;
    queue q;
    q = (queue)malloc(sizeof(struct queueStruct));
    int n;
    char name[20];
    int tel;
    char email[30];
    node temp;
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Insert At\n");
        printf("2.Print all nodes \n");
        printf("3.Delete a node\n");
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
            readFileToQueue(q);
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
            printf("%d", isEmpty(q));
            break;
        }
        }
    }
    return 0;
}