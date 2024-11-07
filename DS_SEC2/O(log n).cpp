#include <iostream>
using namespace std;

bool binarySearch(const int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return true;
        }
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}





int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    if (binarySearch(arr, size, target)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
