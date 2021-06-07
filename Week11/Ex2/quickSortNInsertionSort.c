#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void insertionSort(int arr[], int n)
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
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (1)
    {
        while (left <= right && arr[left]<pivot)
            left++;
        while (right >= left && arr[right]>pivot)
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
void quickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    // int arr[]={5,2,3,1,7,7};
    // int n=6;
    int n = 100000;
    int *arr = (int *)malloc(n * sizeof(int));
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    int *arr3 = (int *)malloc(n * sizeof(int));
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % n) - n / 2;
    }
    memcpy(arr1, arr, sizeof(int) * n);
    memcpy(arr2, arr, sizeof(int) * n);
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    start_t = clock();
    printf("Starting of insertionSort, start_t = %ld\n", start_t);
    insertionSort(arr1, n);
    end_t = clock();
    printf("End of the insertionSort, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");

    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    start_t = clock();
    printf("Starting of quickSort, start_t = %ld\n", start_t);
    quickSort(arr2, 0,n-1);
    end_t = clock();
    printf("End of the quickSort, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");
}