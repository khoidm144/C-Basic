#include <stdio.h>
#define n 6
int checkArray(int a[], int b[], int numbers)
{
    for (int i = 0; i < numbers; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a[n];
    int b[n];
    printf("Input the first array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Input the second array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    if (checkArray(a, b, n) == 1)
    {
        printf("They are equal! \n");
    }
    else
    {
        printf("They are not equal ! \n");
    }
    return 0;
}
