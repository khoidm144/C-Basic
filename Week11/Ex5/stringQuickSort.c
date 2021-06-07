#include <stdio.h>
#include <string.h>

int count = 0;
void swap(char *a, char *b)
{
    char temp[30];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
int partition(char arr[][30], int low, int high)
{   
    char pivot[30];
    strcpy(pivot, arr[high]);
    int left = low;
    int right = high - 1;
    while (1)
    {
        while (left <= right && strcmp(arr[left], pivot) < 0)
            left++;
        while (right >= left && strcmp(arr[right], pivot) > 0)
            right--;
        if (left >= right)
        {
            break;
        }
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
void quickSort(char arr[][30], int left, int right)
{
    if (left <= right)
    {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}
void printArr(char arr[][30], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}
int main()
{
    FILE *input = fopen("data.txt", "r");
    char name[20];
    char temp[30];
    int index = 0;
    char arr[30][30];
    while (!feof(input))
    {
        if (fscanf(input, "%[^\n]%*c", name) == EOF)
        {
            break;
        }
        strcpy(arr[index++], name);
    }
    quickSort(arr, 0, index - 1);
    printArr(arr, index);
    printf("Comparision made : %d time(s)", index);
}