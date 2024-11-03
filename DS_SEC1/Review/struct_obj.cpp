#include <iostream>
using namespace std;
struct P
{
    int t;
    char c;
    string s;
};

int main()
{
    P Obj;          // declear a object of struct
    P *pointer;     // declear a pointer of type struct
    pointer = &Obj; // point to Obj

    pointer->t; // now we can point to any member in the Obj
}
