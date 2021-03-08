#include <stdio.h>
#define N 100
int n;
int x[N];
void solution()
{
    for (int i = 1; i <= n; i++)
        printf("%d", x[i]);
    printf("\n");
}
int check(int v, int k)
{
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
        if (x[i] == 0)
        {
            ans++;
            if (ans == 2)
            {
                if (v == 1)
                {
                    return 1;
                }
                return 0;
            }
        }
    }
    if (v == 1 && ans == 1 && n - k < 1)
    {
        return 0;
    }
    if (v == 1 && ans == 0 && n - k < 2)
    {
        return 0;
    }
    return 1;
}
void try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k == n)
            {
                solution();
            }
            else
                try(k + 1);
        }
    }
}
int main()
{
    n = 5;
    try(1);

    return 0;
}