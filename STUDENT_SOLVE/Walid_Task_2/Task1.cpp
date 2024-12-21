#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool search(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deleteElement(T value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            cout << "Element " << value << " deleted from the list." << endl;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Element " << value << " deleted from the list." << endl;
        } else {
            cout << "Element " << value << " not found in the list." << endl;
        }
    }

    void printList() {
        Node<T>* temp = head;
        if (!temp) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    SinglyLinkedList<int> list;
    int choice, value;

    while (true) {
        cout << "1. Add element\n";
        cout << "2. Search element\n";
        cout << "3. Delete element\n";
        cout << "4. Display list\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to add: ";
                cin >> value;
                list.add(value);
                cout << "Element " << value << " added to the list." << endl;
                break;

            case 2:
                cout << "Enter element to search for-: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Element " << value << " found in the list." << endl;
                } else {
                    cout << "Element " << value << " not found in the list." << endl;
                }
                break;

            case 3:
                cout << "Enter element to delete-: ";
                cin >> value;
                list.deleteElement(value);
                break;

            case 4:
                cout << "List contents-: ";
                list.printList();
                break;

            case 5:
                cout << "Goodbye............!" << endl;
                return 0;

            default:
                cout << "< Invalid option >" << endl;
        }
    }

    return 0;
}
