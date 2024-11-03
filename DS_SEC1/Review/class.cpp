#include <iostream>
using namespace std;
class EX // Class declaration
{
private:
    string data; // Private data

public:
    string v; // Public variable
    // Default constructor
    EX() : data("") {} // Initialize data to an empty string by Initializer list

    // Constructor with parameter to set v and data
    EX(const string &value) : v(value), data(value) {} // Initialize v and data

    // Member function to get data
    string getData()
    {
        return data;
    }

    // Destructor
    ~EX()
    {
        cout << "Exiting ... " << endl;
    }
};

int main()
{
    EX obj1;                // Default constructor
    EX obj2("Hello World"); // Parameterized constructor

    cout << "Data from obj1: " << obj1.getData() << endl; // Should show empty string
    cout << "Data from obj2: " << obj2.getData() << endl; // Should show "Hello World"

    return 0;
}
