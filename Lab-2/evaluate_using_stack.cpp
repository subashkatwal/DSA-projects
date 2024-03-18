#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            exit(EXIT_FAILURE);
        }
        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack: ";
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.display(); // Output: Stack: 3 2 1

    cout << "Popped: " << stack.pop() << endl; // Output: Popped: 3

    cout << "Top of the stack: " << stack.peek() << endl; // Output: Top of the stack: 2

    return 0;
}