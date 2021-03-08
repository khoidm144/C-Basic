#include <stdio.h>
void print(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int check(int arr[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num == arr[row][i])
        {
            return 0;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (num == arr[i][col])
        {
            return 0;
        }
    }
    int startRow = row / 3;
    startRow = startRow * 3;
    int startCol = col / 3;
    startCol = startCol * 3;
    for (int i = startRow; i < (3 + startRow); i++)
    {
        for (int j = startCol; j < (3 + startCol); j++)
        {
            if (arr[i][j] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}
void solve(int arr[9][9], int row, int col)
{
    if (col == 9)
    {
        if (row == 8)
        {
            print(arr);
            return;
        }
        else
        {
            solve(arr, row + 1, 0);
        }
    }
    else if (arr[row][col] != 0)
    {
        solve(arr, row, col + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(arr, row, col, i) == 1)
            {
                arr[row][col] = i;
                solve(arr, row, col + 1);
                arr[row][col] = 0;
            }
        }
    }
    return;
}
int main()
{
    int arr[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    //solve(arr,0,0);
    print(arr);
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    solve(arr, 0, 0);

    return 0;
}