#include<stdio.h>

int factorial(int n,int result){
    if(n==0 || n==1){
        return result;
    }
    return factorial(n-1,n*result);

}
int main(){
    int n=5;
    int result=factorial(n,1);
    printf("Factorial of %d is  %d\n",n,result);
    return 0;
}