
#include <iostream>
using namespace std;

// Step 1: Implement Stack Using Struct
struct Stack {
    int* arr;
    int top;
    int capacity;

    // Constructor
    Stack(int size) {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Display the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

// Step 2: Implement Queue Using Struct
struct Queue {
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

    // Constructor
    Queue(int cap) {
        arr = new int[cap];
        front = 0;
        rear = -1;
        capacity = cap;
        size = 0;
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // Dequeue an element from the queue
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int result = arr[front];
        front = (front + 1) % capacity;
        size--;
        return result;
    }

    // Get the front element of the queue
    int getFront() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element of the queue
    int getRear() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Display the queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};

// Step 3: Demonstrate Stack and Queue Operations
int main() {
    cout << "\n--- Stack Operations ---\n";
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << "Popped: " << stack.pop() << "\n";
    stack.display();

    cout << "\n--- Queue Operations ---\n";
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    cout << "Dequeued: " << queue.dequeue() << "\n";
    queue.display();

    return 0;
}
