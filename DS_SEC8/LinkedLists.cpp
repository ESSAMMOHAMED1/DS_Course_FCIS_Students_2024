
#include <iostream>
using namespace std;

// Step 1: Define Structures for All Linked List Types

// Node structure for Single Linked List
struct SNode {
    int data;               // Data part
    SNode* next;            // Pointer to the next node

    // Constructor for easy SNode creation
    SNode(int value) : data(value), next(nullptr) {}
};

// Node structure for Doubly Linked List
struct DNode {
    int data;               // Data part
    DNode* next;            // Pointer to the next node
    DNode* prev;            // Pointer to the previous node

    // Constructor for easy DNode creation
    DNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Node structure for Circular Linked List
struct CNode {
    int data;               // Data part
    CNode* next;            // Pointer to the next node

    // Constructor for easy CNode creation
    CNode(int value) : data(value), next(nullptr) {}
};

// Step 2: Implement Functions for Single Linked List
struct SingleLinkedList {
    SNode* head;

    // Constructor
    SingleLinkedList() : head(nullptr) {}

    // Insert a new node at the end
    void insert(int value) {
        SNode* newNode = new SNode(value);
        if (!head) {
            head = newNode;  // If list is empty
        } else {
            SNode* temp = head;
            while (temp->next) {
                temp = temp->next; // Traverse to the end
            }
            temp->next = newNode;
        }
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        SNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SingleLinkedList() {
        while (head) {
            SNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Step 3: Implement Functions for Doubly Linked List
struct DoublyLinkedList {
    DNode* head;

    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Insert a new node at the end
    void insert(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Step 4: Implement Functions for Circular Linked List
struct CircularLinkedList {
    CNode* head;

    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Insert a new node at the end
    void insert(int value) {
        CNode* newNode = new CNode(value);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        CNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }

    ~CircularLinkedList() {
        if (!head) return;

        CNode* temp = head;
        do {
            CNode* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
    }
};

// Step 5: Demonstrate Linked List Types
int main() {
    cout << "\n--- Single Linked List ---\n";
    SingleLinkedList singleList;
    singleList.insert(10);
    singleList.insert(20);
    singleList.insert(30);
    singleList.display();

    cout << "\n--- Doubly Linked List ---\n";
    DoublyLinkedList doubleList;
    doubleList.insert(10);
    doubleList.insert(20);
    doubleList.insert(30);
    doubleList.display();

    cout << "\n--- Circular Linked List ---\n";
    CircularLinkedList circularList;
    circularList.insert(10);
    circularList.insert(20);
    circularList.insert(30);
    circularList.display();

    return 0;
}
