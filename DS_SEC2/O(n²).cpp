#include <iostream>
using namespace std;

void printAllPairs(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "(" << array[i] << ", " << array[j] << ")" << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAllPairs(arr, size);

    return 0;
}
