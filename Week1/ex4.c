#include <stdio.h>
typedef struct
{
    int integer;
    double fraction;
} twoPart;
twoPart dividePart(double a)
{
    twoPart ans;
    ans.integer = (int)a;
    ans.fraction = a - (int)a;

    return ans;
}
int main()
{
    double a;
    twoPart ans;
    printf("Input the double number : ");
    scanf("%lf", &a);
    ans = dividePart(a);
    printf("%d and %.4lf", ans.integer, ans.fraction);
    return 0;
}