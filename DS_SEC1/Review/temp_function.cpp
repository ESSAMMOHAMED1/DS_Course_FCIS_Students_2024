#include <iostream>
using namespace std;

template <typename T> //define template
T getMax(T a, T b) // make a function that type of T (Generic type)
{
    return (a > b) ? a : b; // retern the max 
}

int main()
{
    cout << getMax(10, 20) << endl;    // Uses getMax<int>(10, 20)
    cout << getMax(10.5, 7.3) << endl; // Uses getMax<double>(10.5, 7.3)
    cout << getMax('a', 'z') << endl;  // Uses getMax<char>('a', 'z')
    return 0;
}