#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address
{
    char name[20];
    int tel;
    char email[30];
    // address *next;
} address;
typedef struct addressList
{
    struct addressList *next;
    struct addressList *prev;
    address addr;
} * node;
node root, tail;
node createNode()
{
    node temp;
    char name[20];
    int tel;
    char email[30];
    printf("Input the name: ");
    scanf("%[^\n]", name);
    printf("Input the tel: ");
    scanf("%d%*c", &tel);
    printf("Input the email: ");
    scanf("%[^\n]", email);
    temp = (node)malloc(sizeof(struct addressList));
    strcpy(temp->addr.name, name);
    temp->addr.tel = tel;
    strcpy(temp->addr.email, email);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void printAllFromHead()
{
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        printf("%s %d %s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
    }
}
void printAllFromTail()
{
    for (node temp = root; temp != NULL; temp = temp->prev)
    {
        printf("%s %d %s\n", temp->addr.name, temp->addr.tel, temp->addr.email);
    }
}
void insertAtHead()
{
    node temp = createNode();
    if (root == NULL)
    {
        root = temp;
        tail = temp;
        return;
    }
    root->prev = temp;
    temp->next = root;
    root = temp;
}
void insertAtTail()
{
    node temp = createNode();
    if (tail == NULL)
    {
        root = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void deleteAtHead()
{
    if (root == NULL)
    {
        return;
    }
    if (root->next == NULL)
    {
        root = NULL;
        tail = NULL;
        return;
    }
    node p = root;
    root = root->next;
    root->prev = NULL;
    p = NULL;
}
void deleteAtTail()
{
    if (tail == NULL)
    {
        return;
    }
    if (tail->prev == NULL)
    {
        root = NULL;
        tail = NULL;
        return;
    }
    node p = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    p = NULL;
}
int main()
{

    root = NULL;
    tail = NULL;
    int n;
    while (1)
    {
        printf("Input the function you want! \n");
        printf("1.Insert to Root\n");
        printf("2.Insert to Tail\n");
        printf("3.Print all nodes \n");
        printf("4.Print all nodes Reverse\n");
        printf("5.Delete a node at Head\n");
        printf("6.Delete a node at Tail\n");
        printf("7.Exit \n");
        printf("Choice : ");
        scanf("%d", &n);
        fflush(stdin);
        switch (n)
        {
        case 1:
        {
            insertAtHead();
            break;
        }
        case 2:
        {
            insertAtTail();
            break;
        }
        case 3:
        {
            printAllFromHead();
            break;
        }
        case 4:
        {
            printAllFromTail();
            break;
        }
        case 5:
        {
            deleteAtHead();
            break;
        }
        case 6:
        {
            deleteAtTail();
            break;
        }
        case 7:
        {
            return 0;
        }
        }
    }
    return 0;
}

// Ghi chú:khi truyền vào hàm 1 giá trị, sẽ tự tạo
//một bản copy, cho nên, nếu muốn thay đổi thực chất giá trị
// trong bộ nhớ : ko truyền vào dưới 1 tham số, cho biến toàn
// lưu giữ nó