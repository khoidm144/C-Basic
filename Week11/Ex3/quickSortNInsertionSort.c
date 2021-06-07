#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void insertionSort(char arr[], int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++)
    {
        next = arr[i];
        for (j = i - 1; j >= 0 && (next < arr[j]); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = next;
    }
}
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int partition(char arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (1)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
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
void quickSort(char arr[], int left, int right)
{
    if (left <= right)
    {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
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
    char arr[200];
    int index = 0;
    int lim;
    FILE *input = fopen("data.txt", "r");
    char c;
    while (!feof(input))
    {
        if (fscanf(input, "%c", &c) == EOF)
        {
            break;
        }
        arr[index++] = c;
    }
    // printf("Please Input the limit x: ");
    // scanf("%d%*c",&lim);
    quickSort(arr,0,index-1);
    printArr(arr,index);
}