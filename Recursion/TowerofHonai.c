#include<stdio.h>

void toh(int n,int source,int auxiliary , int destination){
    if (n>0){
        toh(n-1,source,destination,auxiliary);
        printf("from %d to %d\n",source ,destination);
        toh(n-1,auxiliary,source,destination);
    }
}

int main(){
    toh(4,1,2,3);
}