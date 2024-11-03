#include <iostream>
using namespace std;
int main() {
int *ptr1; // Pointer syntax for data type int
float *ptr2; // Pointer syntax for data type float
char *ptr3; // Pointer syntax for data type char
double *ptr4; // Pointer syntax for data type double

int a = 10;
ptr1 = &a; // Assign address of 'a' to ptr1

float b = 10.5;
ptr2 = &b; // Assign address of 'b' to ptr2

char c = 'x';
ptr3 = &c; // Assign address of 'c' to ptr3

double d = 1.345;
ptr4 = &d; // Assign address of 'd' to ptr4

cout << *ptr1 << endl;
cout << *ptr2 << endl;
cout << *ptr3 << endl;
cout << *ptr4 << endl;

return 0;
}




