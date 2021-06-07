#include <stdio.h>
#include <string.h>
typedef struct AddressStruct
{
    char name[30];
    char phone[15];
    char email[30];
} address;
int count = 0;
void swap(address *a, address *b)
{
    address temp = *a;
    *a = *b;
    *b = temp;
}
int partition(address arr[], int low, int high)
{
    address pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (1)
    {
        while (left <= right && strcmp(arr[left].name, pivot.name) < 0)
            left++;
        while (right >= left && strcmp(arr[right].name, pivot.name) > 0)
            right--;
        if (left >= right)
        {
            break;
        }
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    swap(&arr[left], &arr[high]);
    return left;
}
void quickSort(address arr[], int left, int right)
{
    if (left <= right)
    {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
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
    quickSort(arr, 0, index-1);
    printArr(arr, index);
    printf("Comparision made : %d time(s)", index);
}