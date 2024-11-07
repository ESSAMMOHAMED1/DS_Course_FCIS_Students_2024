#include <iostream>
using namespace std;

void printFirstElement(const int array[], int size) {
    if (size > 0) {
        cout << array[0] << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printFirstElement(arr, size);
    return 0;
}
