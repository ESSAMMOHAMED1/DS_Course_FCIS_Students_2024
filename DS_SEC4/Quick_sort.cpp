#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Pointer for elements smaller than the pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]); // Swap smaller element with the pivot region
        }
    }

    // Place the pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return pivot index
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Call Quick Sort
    quickSort(arr, 0, arr.size() - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
