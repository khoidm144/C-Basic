#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
void Swap(int *number_1, int *number_2)
{
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}

void ShuffleArray(int *arr, int n)
{
    srand(time(NULL));

    int minPosition;
    int maxPosition = n - 1;
    int swapPosition;

    int i = 0;
    while (i < n - 1)
    {
        minPosition = i + 1;
        swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;

        Swap(&arr[i], &arr[swapPosition]);
        i++;
    }
}
void generateRandomNumberArray(int arr[], int markArr[], int n)
{
    int temp = 0;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        temp = (rand() % (n * 10));
        if (markArr[temp] == 1)
        {
            i--;
            continue;
        }
        else
        {
            arr[i] = temp;
            markArr[arr[i]] = 1;
        }
    }
}
void bruteForceSearchSolve(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                count++;
            }
        }
    }
    printf("Result : %d \n", count);
}
int binarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
    {
        return 0;
    }
    if (left == right)
    {
        if (arr[left] == key)
        {
            return 1;
        }
        else
            return 0;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
    {
        return 1;
    }
    if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, right, key);
    }
    return binarySearch(arr, left, mid - 1, key);
}
void binarySearchSolve(int arr[], int n, int sum)
{
    int count = 0;
    qsort(arr, n, sizeof(int), cmpfunc);
    for (int i = 0; i < n - 1; i++)
    {
        count += binarySearch(arr, i + 1, n - 1, sum - arr[i]);
    }
    printf("Result : %d \n", count);
}
void searchingAndTestComplexity(int arr[], int n)
{
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    int sum = 0;
    // qsort(arr, n, sizeof(int), cmpfunc);
    printf("Input the sum number : ");
    scanf("%d", &sum);
    fflush(stdin);
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Starting of bruteForceSearching, start_t = %ld\n", start_t);
    bruteForceSearchSolve(arr, n, sum);
    end_t = clock();
    printf("End of the  bruteForceSearching, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");

    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    start_t = clock();
    printf("Starting of binarySearching, start_t = %ld\n", start_t);
    binarySearchSolve(arr, n, sum);
    end_t = clock();
    printf("End of the binarySearching, end_t = %ld\n", end_t);
    total_t = ((double)((double)end_t - (double)start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf s\n", total_t);
    printf("Exiting of the function...\n");
}
int main()
{
    int choice;
    int n = 10000;
    int *arr = (int *)malloc(n * sizeof(int));
    int *markArr = (int *)malloc(n * 10 * sizeof(int));
    // int arr[] = {0, 2, 5, 9, 3, 6,102};
    // int n = 7;
    while (1)
    {
        printf("1.Generate the random number array \n");
        printf("2.Display the array: \n");
        printf("3.Calling searching functions and Test the Complexity \n");
        printf("Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
        {
            for (int i = 0; i < n * 10; i++)
            {
                markArr[i] = 0;
            }
            generateRandomNumberArray(arr, markArr, n);
            break;
        }
        case 2:
        {
            display(arr, n);
            break;
        }
        case 3:
        {
            searchingAndTestComplexity(arr, n);
            break;
        }
        case 4:
        {
            break;
        }
        }
    }
    return 0;
}