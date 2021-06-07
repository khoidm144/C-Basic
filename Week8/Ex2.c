#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct AddressStruct
{
    char name[30];
    char email[30];
} address;
int index1 = 0;
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void display(address a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", a[i].name, a[i].email);
    }
}
void insert(address a[], address temp)
{
    int i = 0;
    while (i < index1)
    {
        if (strcmp(a[i].name, temp.name) > 0)
        {
            break;
        }
        else
        {
            i++;
        }
    }
    printf("index to insert : %d ", i);
    for (int j = index1; j > i; j--)
    {
        a[j] = a[j - 1];
    }
    a[i] = temp;
    index1++;
}
void removeStudent(address arr[], int count)
{
    for (int i = count; i < index1 - 1; i++)
        arr[i] = arr[i + 1];
    index1--;
}
int binarySearch(address arr[], int left, int right, char *key)
{
    if (left > right)
    {
        return -1;
    }
    if (left == right)
    {
        if (strcmp(arr[left].name, key) == 0)
        {
            return left;
        }
        else
            return -1;
    }
    int mid = left + (right - left) / 2;
    if (strcmp(arr[mid].name, key) == 0)
    {
        return mid;
    }
    if (strcmp(arr[left].name, key) > 0)
    {
        return binarySearch(arr, mid + 1, right, key);
    }
    return binarySearch(arr, left, mid - 1, key);
}
int main()
{
    int choice;
    int n;
    FILE *input = fopen("data.txt", "r");
    char name[20];
    char email[30];
    address temp;
    int index = 0;
    address arr[30];
    while (1)
    {
        printf("1.Load \n");
        printf("2.Find \n");
        printf("3.Insert \n");
        printf("4.Remove \n");
        printf("5.Display \n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
        {
            while (!feof(input))
            {
                if (fscanf(input, "%[^\n]%*c", name) == EOF)
                {
                    break;
                }
                strcpy(temp.name, name);
                fscanf(input, "%[^\n]%*c", temp.email);
                insert(arr, temp);
            }
            break;
        }
        case 2:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            int temp = binarySearch(arr, 0, index1, str);
            if (temp == -1)
            {
                printf("Not found! ");
                break;
            }
            printf("Name : %s Email: %s\n", arr[temp].name, arr[temp].email);
            break;
        }
        case 3:
        {
            printf("Input the name : ");
            scanf("%[^\n]%*c", name);
            printf("Input the email : ");
            scanf("%[^\n]%*c", email);
            strcpy(temp.name, name);
            strcpy(temp.email, email);
            insert(arr, temp);
            break;
        }
        case 4:
        {
            char str[30];
            printf("Input the string : ");
            scanf("%[^\n]%*c", str);
            int temp = binarySearch(arr, 0, index1, str);
            if (temp == -1)
            {
                printf("Not found! ");
                break;
            }
            removeStudent(arr,temp);
            break;
        }
        case 5:
        {
            display(arr, index1);
            break;
        }
        }
    }
    return 0;
}