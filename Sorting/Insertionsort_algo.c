#include<stdio.h>

void sorting(int size , int arr[]);
int main(){
    int size,i , j ,arr[50];
    printf("Enter the size of the array :\n");
    scanf("%d",&size);
    printf("Enter the elements of the array :\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    sorting(size,arr);
}

void sorting(int size , int arr[]){
    for(int i=1;i<size;i++){
    int current=arr[i];
        int j=i-1;
        while(current<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    printf("The sorted array using insertion sort is :\n");
    for(int j=0;j<size;j++){
        printf("%d\t",arr[j]);
    }
}