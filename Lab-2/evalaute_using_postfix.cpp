#include <iostream>

#define MAX_SIZE 100

using namespace std;

class Queue {
private:
    int items[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0; // Reset front if queue was empty
        }
        rear++;
        items[rear] = value;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
        int item = items[front];
        front++;
        return item;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return items[front];
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Enqueue some elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    // Display queue
    queue.display();

    // Dequeue an element
    int removedElement = queue.dequeue();
    cout << "Removed element: " << removedElement << endl;

    // Display queue after dequeue
    queue.display();

    // Peek operation
    cout << "Front element: " << queue.peek() << endl;

    return 0;
}
