#include <iostream>
using namespace std;
void shellSort(int arr[], int n)
{
    // Calculate the gap sequence
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform an insertion sort on each subarray
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto n = end(arr) - begin(arr);
    shellSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}



// j >= gap:

// Ensures j doesn’t go out of bounds when subtracting the gap.
// tmp < a[j - gap]:

// Compares the value being sorted (tmp) with the value at the position gap steps before (a[j - gap]).
// If the current element (tmp) is smaller, we need to shift the larger element (a[j - gap]) forward.
// j -= gap:

// Moves j backward by the gap to continue comparing elements in the "gap group."
// a[j] = a[j - gap];:

// Shifts the larger element in the "gap group" forward by gap.
// This loop shifts elements in the "gap group" until the correct position for tmp is found.