#include <iostream>
using namespace std;

// Structure for stack
struct Stack {
    int top;
    int capacity;
    int* array;

    Stack(int size) {
        top = -1;
        capacity = size;
        array = new int[size];
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        array[++top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return array[top--];
    }

    // Peek at the top element
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return array[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] array;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    while (!s.isEmpty()) {
        cout << "Popped: " << s.pop() << endl;
    }

    return 0;
}
