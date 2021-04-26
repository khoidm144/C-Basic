#include <stdio.h>
#include <string.h>
typedef struct AddressStruct
{
    char name[30];
    char phone[15];
    char email[30];
} address;

void heapify(address arr[], int n, int i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && strcmp(arr[l].name, arr[largest].name) > 0)
    {
        largest = l;
    }
    if (r < n && strcmp(arr[r].name, arr[largest].name) > 0)
    {
        largest = r;
    }
    if (largest != i)
    {
        address temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(address arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        address temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
    heapSort(arr, index);
    printArr(arr, index);
}