#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit function
#include <string.h> // for strlen function

#define MAX_SIZE 100 // Maximum size of the stack

// Stack structure
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// Initialize stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push element onto stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Evaluate prefix expression
int evaluatePrefix(char *expression) {
    Stack s;
    initialize(&s);

    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            switch (expression[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&s);
}


int main() {
    char expression[] = "+*543";
    int result = evaluatePrefix(expression);
    printf("Result of evaluation: %d\n", result);
    return 0;
}
