#include <iostream>
using namespace std;

// Structure for queue
struct Queue {
    int front, rear, capacity;
    int* array;

    Queue(int size) {
        front = 0;
        rear = -1;
        capacity = size;
        array = new int[size];
    }

    // Enqueue an element
    void enqueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        array[++rear] = value;
    }

    // Dequeue an element
    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return array[front++];
    }

    // Peek at the front element
    int peek() {
        if (front > rear) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return array[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front > rear;
    }

    ~Queue() {
        delete[] array;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}
