#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct AddressStruct
{
    char name[30];
    char phone[15];
    char email[30];
} address;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
void selectionSort(int arr[], int n)
{
    int i, j;
    int next;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
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
    int n = 1000000;
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
    memcpy(arr3, arr, sizeof(int) * n);
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Starting of selectionSort, start_t = %ld\n", start_t);
    selectionSort(arr, n);
    end_t = clock();
    printf("End of the selectionSort, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");

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
    printf("Starting of bubbleSort, start_t = %ld\n", start_t);
    bubbleSort(arr2, n);
    end_t = clock();
    printf("End of the bubbleSort, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");

    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    start_t = clock();
    printf("Starting of heapSort, start_t = %ld\n", start_t);
    heapSort(arr3, n);
    end_t = clock();
    printf("End of the heapSort, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");
}