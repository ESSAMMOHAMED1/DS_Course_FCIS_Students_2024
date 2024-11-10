
// Write a simple function (e.g., void greet() { cout << "Hello!"; }).

// Create a pointer to this function and call the function via the pointer.

#include <iostream>
#include <string>
using namespace std;

void greet()
{

    cout << "Hello!";

};
int main(){

void (*pointer)();

pointer = greet;
pointer();
}
