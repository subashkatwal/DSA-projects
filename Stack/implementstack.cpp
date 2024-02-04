
// Stack implementation
#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
    void initStack()
    {
        cout << "Enter the size of the stack:" << endl;
        cin >> this->size;
        this->arr = new int[this->size];
        this->top = -1;
    }

    void push(int n)
    {
        if (this->isFull())
        {
            cout << "Stack overflow \n"<< endl;
            exit(0);
        }
        this->arr[++this->top] = n;
    }

    int pop()
    {
        if (this->isempty())
        {
            cout << "Stack underflow \n"
                 << endl;
            exit(0);
        }
        return this->arr[this->top--];
    }

    int peek()
    {
        return this->arr[this->top];
    }

    int getSize()
    {
        return this->size;
    }

    bool isempty()
    {
        return this->top == -1;
    }
    bool isFull()
    {
        return (this->top == (this->size - 1));
    }

    void StackValues()
    {
        if (this->isempty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are : " << endl;
        for (int i = 0; i < this->top; i++)
        {
            cout << this->arr[i] << endl;
        }
    }
    void checkStatus()
    {
        if (this->isempty())
        {
            cout << "Stack is empty" << endl;
        }
        else if (this->isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "The stack is neither empty nor full " << endl;
        }
    }
};
int main()
{
    Stack st;
    st.initStack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.StackValues();

    cout << "Top element is : " << st.peek() << endl;
    cout << "Popped element is : " << st.pop() << endl;
    cout << "Size of stack is : " << st.getSize() << endl;

    st.checkStatus();
}

