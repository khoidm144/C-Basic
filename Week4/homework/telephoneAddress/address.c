#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct itemStruct
{
    char name[20];
    char tel[20];
    char email[30];
} nodeItem;
typedef struct nodeStruct {
	nodeItem data;
	struct nodeStruct * next;
} * node ;
node front;
node rear;
int count = 0;
void init()
{
    front = NULL;
    rear = NULL;
}
int countNumberOfQueue()
{
    return count;
}
void enQueue(node temp)
{

    if (front == NULL)
    {
        front = temp;
        rear = temp;
        count = 1;
        return;
    }
    if (front->next == NULL)
    {
        rear = temp;
        front->next = rear;
        count = 2;
        return;
    }
    rear->next = temp;
    rear = rear->next;
    count++;
    return;
}
node deQueue()
{
    if (front == NULL)
    {
        return NULL;
    }
    if (count == 1)
    {
        node temp = front;
        front = NULL;
        rear = NULL;
        count = 0;
        return temp;
    }
    node temp = front;
    front = front->next;
    count--;
    return temp;
}
int main()
{
    FILE *input, *output;
    init();
    node temp;
    temp = (node)malloc(sizeof(struct nodeStruct));
    input = fopen("data.txt", "r");
    output = fopen("data.dat", "wb+");
    char st[30];
    while (!feof(input))
    {       
            nodeItem cur;
            if(fscanf(input,"%[^\n]%*c",st)<=0){
            	break;
			}
            strcpy(cur.name,st);
            fscanf(input,"%[^\n]%*c",cur.tel);
            fscanf(input,"%[^\n]%*c",cur.email);
            fwrite(&cur, sizeof(struct itemStruct), 1, output);
    }
    rewind(output);
    fclose(output);
    fclose(input);
    input = fopen("data.dat", "rb+");
    output = fopen("newOut.dat", "wb+");
    rewind(input);
    rewind(output);
    nodeItem cur;
    while(fread(&cur, sizeof(struct itemStruct), 1, input)>0){
    temp = (node)malloc(sizeof(struct nodeStruct));
    temp->next=NULL;
    strcpy(temp->data.name,cur.name);
    strcpy(temp->data.tel,cur.tel);
    strcpy(temp->data.email,cur.email);
    enQueue(temp);
	}
    while (count > 0)
    {   
        temp = deQueue();
        fprintf(output, "%s\n", temp->data.name);
        fprintf(output, "%s\n", temp->data.tel);
        fprintf(output, "%s\n", temp->data.email);
    }
    fclose(input);
    fclose(output);
}
