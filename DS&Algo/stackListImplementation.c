#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int count = 0;
typedef struct node{
    char c;
    struct node *next;
} * node  ;
node root;
node makeNode(char c){
    node newNode = (node)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->c=c;
    return newNode;
}
int isEmpty()
{
    return count == 0;
}
int isFull()
{
    return MAX == count;
}
void push(char newChar)
{
    if (count == MAX)
    {
        return;
    }
    if(count==0){
    	count++;
        root=makeNode(newChar);
        return ;
    }
    count++;
    node p=root;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=makeNode(newChar);
    return ;
}
char pop()
{
    node p=root;
    node prev=p;
    while(p->next!=NULL){
    	prev=p;
    	p=p->next;
	}
    char ans=p->c;
    prev->next=NULL;
    count--;
    return ans;   
}
char peek()
{
    return root->c;
}
int countNumberOfStack()
{
    return count;
}
void printStack()
{   
node p=root;
    for (int i=0; i < count; i++)
    { 
        printf("%c",p->c);
        p=p->next;
    }
}
int main()
{
    FILE *input = fopen("ContainSyntaxError.c", "r+");
    char c;
    int flag = 1;
    while (!feof(input))
    {   
        
        c = fgetc(input);
        putchar(c);
        if(c<0){
        	break;
		}
        if (c == '{' || c == '(' || c == '[')
        {
            push(c);
        }
        else if (c == '}' || c == ')' || c == ']')
        {    
            char temp = pop();
            if (c == '}' && temp != '{')
            {    
                printf("Syntax Error found at {}");
                return 0;
            }
            else if (c == ')' && temp != '(')
            {   
                printf("Syntax Error found at ()");
                return 0;
            }
            else if (c == ']' && temp != '[')
            {
                printf("Syntax Error found at []");
                return 0;
            }
        }
    }
     printStack();
    if (isEmpty() != 1)
    {
        printf("Syntax Error : redundant or missing %c  ",pop());
    }
    else
    {
        printf("Correct Syntax ! ");
    }
}
