#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Overflow\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    int poppedValue = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return poppedValue;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return top->data;
}

void display() {
    Node *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);

    display();

    printf("Popped: %d\n", pop());

    display();

    printf("Top of the stack: %d\n", peek());

    return 0;
}