#include<stdio.h>

#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue (int num){
    if (rear==MAX-1){
        printf("Stack overflow\n");
    }else if (front==-1 && rear== -1){
        front=rear=0;
        queue[rear]=num;

    }else{
        rear++;
        queue[rear]=num;
    }

}
 void dequeue(){
    if (front == -1 && rear== -1){
        printf("Stack underflow\n");
    }else if (front== rear){
        printf("Last element removed is %d\n ",queue[front]);
        front=rear=-1;
    }else{
        printf("Removed element is %d\n",queue[front]);
        front++;
    }
 }

 void display(){
    int i;
    if (front== -1 && rear == -1){
        printf("Queue is empty")
    }
 }