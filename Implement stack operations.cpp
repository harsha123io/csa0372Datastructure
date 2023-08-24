#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool isFull() {
    return top == MAX_SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed onto the stack.\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    printf("%d popped from the stack.\n", stack[top--]);
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a sentinel value or handle error appropriately
    }
    return stack[top];
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    pop();
    pop();
    pop();
    pop(); // Trying to pop from an empty stack

    return 0;
}

