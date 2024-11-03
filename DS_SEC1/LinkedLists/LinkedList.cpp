#include <iostream>
using namespace std;

struct Node
{
    int data;   // data part
    Node *next; // link part
};

int main()
{

    Node a, b, c; // we creat 3 nodes
    a.next = &b;  // we point to b as next node
    a.data = 12;  // and so on ...... 
    b.data = 13;
    b.next = &c;
    c.data = 14;
    c.next = NULL; // we point to null to avoid gabeg values
    cout << a.next->next->data; // by next pointers we get the data of the last node in the list 
}