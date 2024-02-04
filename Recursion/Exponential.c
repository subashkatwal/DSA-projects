#include<stdio.h>
 int power(int m,int n){
    if (n==0){
        return 1;
    }else{
        return power(m,n-1)*m;
    }
 }

int main(){
int x,y,p;

printf("Enter the value for base and power : \n");
scanf("%d%d",&x,&y);
p=power(x,y);
printf("The exponential of number is %d ",p);
}