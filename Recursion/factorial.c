#include<stdio.h>

int fact(int n){
    if (n==0){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}
int main(){
int x;
printf("Enter any number :");
scanf("%d",&x);
printf("Factorial of given number is %d ",fact(x));
}