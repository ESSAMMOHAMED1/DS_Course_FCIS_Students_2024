#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoubleCircularLinkedList {
private:
    Node* head;

public:
    DoubleCircularLinkedList() : head(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

};

int main() {
    DoubleCircularLinkedList list;

    list.add(4);
    list.add(8);
    list.add(16);
    list.add(32);

    cout << "Double Circular Linked List:  \n\n";
    list.printList();


    return 0;
}
