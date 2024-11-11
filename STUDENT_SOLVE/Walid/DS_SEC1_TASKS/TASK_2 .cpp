/*

Swap Two Numbers Using Pointers

Define a function void swap(int *x, int *y) that swaps the values of x and y using their pointers.

In main(), declare two integers,

pass their addresses to the swap function, and print their values before and after the swap.

*/
#include <iostream>
#include <string>
using namespace std;

int main(){
int *p1 , *p2 ,a ,b ;
a= 5;
b = 10;
p1 = &a;
p2 = &b;

cout << "a:"<<*p1<<endl;
cout << "b:"<<*p2<<endl;

cout<<"After Swap------->"<<endl;
swap(a,b);

cout << "a:"<<*p1<<endl;
cout << "b:"<<*p2<<endl;

}
