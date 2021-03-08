#include <stdio.h>
typedef struct point
{
    double x;
    double y;
} point_t;
typedef struct circle
{
    point_t center;
    double radius;

} circle_t;
int is_in_circle(circle_t a,point_t p){
 double xDistance=a.center.x-p.x;
 double yDistance=a.center.y-p.y;
 return ((xDistance*xDistance+yDistance*yDistance)<=a.radius*a.radius);
}
int main()
{
   circle_t a;
   point_t  p;
   int check=0;
   printf("Input the center coordinate of the circle : \n");
   printf("X : ");
   scanf("%lf",&a.center.x);
   printf("Y: ");
   scanf("%lf",&a.center.y);
   printf("The Radius : R =");
   scanf("%lf",&a.radius);
   printf("Input the center coordinate of a point :");
   printf("X : ");
   scanf("%lf",&p.x);
   printf("Y: ");
   scanf("%lf",&p.y);
   check=is_in_circle(a,p);
   if(check){
       printf("It is covered");
   }
   else{
       printf("It is not covered");
   }
       return 0;
}