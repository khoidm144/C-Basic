#include <stdio.h>
#include <string.h>
typedef struct AddressStruct
{
    char name[30];
    char phone[15];
    char email[30];
} address;
int count = 0;
void selectionSort(address arr[], int n)
{
    int i, j;
    address next;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {   
            count++;
            if (strcmp(arr[i].name, arr[j].name) > 0)
            {
                address temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    FILE *input = fopen("data.txt", "r+");
    char name[20];
    char phone[15];
    char email[30];
    address temp;
    int index = 0;
    address arr[30];
    while (!feof(input))
    {
        if (fscanf(input, "%[^\n]%*c", name) <= 0)
        {
            break;
        }
        strcpy(temp.name, name);
        fscanf(input, "%[^\n]%*c", temp.phone);
        fscanf(input, "%[^\n]%*c", temp.email);
        arr[index++] = temp;
    }
    selectionSort(arr, index);
    printArr(arr, index);
    printf("Comparision made : %d time(s)", count);
    fclose(input);
}