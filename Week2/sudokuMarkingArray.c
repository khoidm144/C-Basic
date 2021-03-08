#include <stdio.h>
int markInBox[9][9];
int markRow[9][9];
int markCol[9][9];
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
int insertToBox(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i == 0 && j == 1)
    {
        return 2;
    }
    if (i == 0 && j == 2)
    {
        return 3;
    }
    if (i == 1 && j == 0)
    {
        return 4;
    }
    if (i == 1 && j == 1)
    {
        return 5;
    }
    if (i == 1 && j == 2)
    {
        return 6;
    }
    if (i == 2 && j == 0)
    {
        return 7;
    }
    if (i == 2 && j == 1)
    {
        return 8;
    }
    if (i == 2 && j == 2)
    {
        return 9;
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
    int startRow = row / 3;
    int startCol = col / 3;
    int boxIndex = insertToBox(startRow, startCol);
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
            if (markCol[col][i - 1] == 0 && markRow[row][i - 1] == 0 && markInBox[boxIndex][i - 1] == 0)
            {
                markCol[col][i - 1] = 1;
                markRow[row][i - 1] = 1;
                markInBox[boxIndex][i - 1] = 1;
                arr[row][col] = i;
                solve(arr, row, col + 1);
                arr[row][col] = 0;
                markCol[col][i - 1] = 0;
                markRow[row][i - 1] = 0;
                markInBox[boxIndex][i - 1] = 0;
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] != 0)
            {
                int startRow = i / 3;
                int startCol = j / 3;
                int boxIndex = insertToBox(startRow, startCol);
                markRow[i][arr[i][j] - 1] = 1;
                markCol[j][arr[i][j] - 1] = 1;
                markInBox[boxIndex][arr[i][j] - 1] = 1;
            }
        }
    }
    print(arr);
    // printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    // print(markInBox);
    // printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    // print(markRow);
    // printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    // print(markCol);
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    solve(arr, 0, 0);

    return 0;
}