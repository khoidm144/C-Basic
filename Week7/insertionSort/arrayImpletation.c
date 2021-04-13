#include <stdio.h>
#include <string.h>
typedef struct AddressStruct
{
    char name[30];
    char phone[15];
    char email[30];
} address;

void insertionSort(address arr[], int n)
{
    int i, j;
    address next;
    for (i = 1; i < n; i++)
    {
        next = arr[i];
        for (j = i - 1; j >= 0 && (strcmp(next.name, arr->name) < 0); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = next;
    }
}
void printArr(address arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %s \n", arr[i].name, arr[i].phone, arr[i].email);
    }
}
int main()
{
    FILE *input = fopen("data.txt", "r");
    char name[20];
    int phone;
    char email[30];
    address temp;
    int index = 0;
    address arr[30];
    while (!feof(input))
    {
        if (fscanf(input, "%[^\n]%*c", name) == EOF)
        {
            break;
        }
        strcpy(temp.name, name);
        fscanf(input, "%[^\n]%*c", temp.phone);
        fscanf(input, "%[^\n]%*c", temp.email);
        arr[index++] = temp;
    }
    index++;
    insertionSort(arr, index);
    printArr(arr, index);
}