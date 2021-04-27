#include <stdio.h>
#include <string.h>

void selectionSort(char arr[], int n)
{
    int i, j;
    char next;
    for (i = 1; i < n; i++)
    {
        next = arr[i];
        for (j = i - 1; j >= 0 && next < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = next;
    }
}
void printArr(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", arr[i]);
    }
}
int main()
{
    char arr[100];
    printf("Input 10 words : ");
    scanf("%[^\n]%*c", arr);
    selectionSort(arr, strlen(arr));
    printArr(arr, strlen(arr));
}