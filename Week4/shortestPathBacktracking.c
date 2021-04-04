#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 10
int min = 1000000;
int count = 0;
int temp = 0;
void print(int maze[10][10])
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}
int is_valid(int maze[10][10], int visited[10][10], int row, int col)
{
    if (row == 10 || col == 10||row==-1||col==-1)
    {
        return 1;
    }
    if (maze[row][col] == 1 || visited[row][col] == 1)
    {
        return 0;
    }
    return 1;
}
void findShortestPath(int maze[M][N], int visited[M][N], int row, int col, int distance)
{
    if (row >= 10 || row < 0 || col >= 10 || col < 0)
    {
        min = distance < min ? distance : min;
        return;
    }
    visited[row][col] = 1;
    if (is_valid(maze, visited, row - 1, col) == 1)
    {
        findShortestPath(maze, visited, row - 1, col, distance + 1);
    }
    if (is_valid(maze, visited, row + 1, col) == 1)
    {
        findShortestPath(maze, visited, row + 1, col, distance + 1);
    }
    if (is_valid(maze, visited, row, col - 1) == 1)
    {
        findShortestPath(maze, visited, row, col - 1, distance + 1);
    }
    if (is_valid(maze, visited, row, col + 1) == 1)
    {
        findShortestPath(maze, visited, row, col + 1, distance + 1);
    }

    visited[row][col] = 0;
}
int main()
{
    int mat[M][N] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 1, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
        };
    int visited[M][N];
    memset(visited, 0, sizeof visited);
    print(mat);
    findShortestPath(mat, visited, 6, 5, 0);
    int min_dist = INT_MAX;
    printf("--------------------\n");
    printf("The shortest way is %d steps\n", min);
    return 0;
}