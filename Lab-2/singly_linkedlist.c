#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int next;
} Node;

Node linkedList[MAX_SIZE];
int head = -1;
int available = 0;

void initializeLinkedList() {
    int i;
    for (i = 0; i < MAX_SIZE - 1; i++) {
        linkedList[i].next = i + 1;
    }
    linkedList[MAX_SIZE - 1].next = -1;
}

int getNode() {
    if (available == -1) {
        printf("Memory Overflow\n");
        exit(EXIT_FAILURE);
    }
    int nodeIndex = available;
    available = linkedList[available].next;
    return nodeIndex;
}

void freeNode(int index) {
    linkedList[index].next = available;
    available = index;
}

void insert(int value) {
    int newNode = getNode();
    linkedList[newNode].data = value;
    linkedList[newNode].next = head;
    head = newNode;
}

void display() {
    int current = head;
    while (current != -1) {
        printf("%d ", linkedList[current].data);
        current = linkedList[current].next;
    }
    printf("\n");

}

int main() {
    initializeLinkedList();
    
    insert(1);
    insert(2);
    insert(3);

    printf("Array after singly linked operation is\n");
    display();

    return 0;
}
