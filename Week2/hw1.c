#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int *p = NULL;
    int sum=0;
    FILE *output;
    output = fopen("out.txt", "w+");
    scanf("%d ", &n);
    p = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (p + i));
        sum += *(p + i);
    }
    for(int i=n-1;i>=0;i--){
        fprintf(output,"%d ",*(p+i));
    }
    fprintf(output,"%d",sum);

    fclose(output);

    return 0;
}