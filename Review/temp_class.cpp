#include <iostream>
using namespace std;
template <class T> // we can replace typename with class (not a problem in class or function)
class Box
{
private:
    T value; // Variable to store the value of any type

public:
    Box(T v) : value(v) {} // Constructor to initialize the Box with a value
    void setValue(T v)     // Method to set the value
    {
        value = v;
    }
    T getValue() const // Method to get the value
    {
        return value;
    }
};
int main(){
    // Creating a Box for an integer
    Box<int> intBox(42); // in class we must sent the type as a paramter (template instantiation.) why 🤔 ?? (Ex 1)
    cout << "Integer Box holds: " << intBox.getValue() << endl;
    // Creating a Box for a double
    Box<double> doubleBox(3.14);
    cout << "Double Box holds: " << doubleBox.getValue() << endl;
    // Creating a Box for a string
    Box<string> stringBox("Hello");
    cout << "String Box holds: " << stringBox.getValue() << endl;
    return 0;
}