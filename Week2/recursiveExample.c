#include<stdio.h>
#include<math.h>
int solve(int n){
    if(n==1){
        return 1;
    }
  return solve(n-1)-pow((-1),n)*n;
}
int main(){
   printf("%d",solve(4));


}