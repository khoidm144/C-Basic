#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    double width;
    double height;
    height = atof(argv[1]);
    width = atof(argv[2]);
    printf("The rectangle's area : %lf and perimeter: %lf", height * width, (height + width) * 2);
    return 0;
}