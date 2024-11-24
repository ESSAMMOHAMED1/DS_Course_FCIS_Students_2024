#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays
void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp; // Temporary array to store merged result
    int i = start, j = mid + 1;

    // Merge the two subarrays into temp
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Add remaining elements from the left subarray (if any)
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from the right subarray (if any)
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }
}

// Recursive function for Merge Sort
void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) return; // Base case: one or zero elements

    int mid = start + (end - start) / 2;

    // Recursively divide the array into two halves
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Merge the two sorted halves
    merge(arr, start, mid, end);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Call Merge Sort
    mergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
