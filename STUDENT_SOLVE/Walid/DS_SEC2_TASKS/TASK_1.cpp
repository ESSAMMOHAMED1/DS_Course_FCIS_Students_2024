// write all 3 Quadratic Sorting Algorithms
/*

selection sort ------>

#include <iostream>
using namespace std;

void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int arr[] = {18, 2, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection(arr, n);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
*/


/*

Insertion ---------->

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {1, 3, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;

}
*/
/*


bubble ------------------------------->

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {1,11, 5, 2, 19, 1, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int num : arr) {
        cout << num << "   ";
    }
    cout << endl;
    return 0;
}
*/
