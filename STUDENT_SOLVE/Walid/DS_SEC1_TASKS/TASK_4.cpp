//  Write a loop to traverse the entire linked list and print the data of each node.

// Use a Node* pointer to start at the head (a) and move through the list using next until you reach the end (nullptr).

// Print the data of each node as you traverse the list.

#include <iostream>
#include <string>
using namespace std;

struct node {
int data;
node *next;
node(int val):data(val),next(nullptr){}

};
void print(node*head){
while(head!=nullptr){

    cout<<head->data<<""<<endl;
    head = head->next;

}
cout<<endl;
}

void append (node*&head,int val){
if(head == nullptr){
    head= new node(val);
    return;
}
node*current = head;
while(current->next!=nullptr){
    current= current->next;

}
    current->next= new node(val);


}

int main(){

node*head=nullptr;
append(head, 1);

append(head, 2);
append(head, 3);
append(head, 4);
append(head, 5);
append(head, 6);
print(head);

}
