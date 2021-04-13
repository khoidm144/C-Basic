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
    for (i = 0; i < n-1; i++)
    {   
        for(j=i+1;j<n;j++)
        if(strcmp(arr[i].name,arr[j].name)>0){
            address temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
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
        if (fscanf(input, "%[^\n]%*c", name) <=0)
        {
            break;
        }
        strcpy(temp.name, name);
        fscanf(input, "%[^\n]%*c", temp.phone);
        fscanf(input, "%[^\n]%*c", temp.email);
        arr[index++] = temp;
        printf("%s",name);
    }
    index++;
    printArr(arr,index);
    insertionSort(arr, index);
    printArr(arr, index);
    fclose(input);
}