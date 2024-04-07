#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert() {
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else {
        if (front == -1) /*If queue is initially empty */
            front = 0;
        printf("Enter the element to insert in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void deleteElement() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow \n");
    } else {
        printf("Deleted element from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display() {
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else {
        printf("Elements inside the Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        } /* End of switch */
    } /* End of while */
    return 0;
} /* End of main() */
