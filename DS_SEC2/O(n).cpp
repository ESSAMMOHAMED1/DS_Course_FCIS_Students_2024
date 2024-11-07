#include <iostream>
using namespace std;

void printAllElements(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAllElements(arr, size);

    return 0;
}
