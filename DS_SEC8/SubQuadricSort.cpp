#include <iostream>
using namespace std;

// Step 1: Implement Merge Sort
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Step 2: Implement Shell Sort
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
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

// Step 3: Implement Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Step 4: Demonstrate Sorting Algorithms
int main()
{
    cout << "\n--- Merge Sort ---\n";
    int mergeArr[] = {38, 27, 43, 3, 9, 82, 10};
    int mergeN = sizeof(mergeArr) / sizeof(mergeArr[0]);

    cout << "Original array: ";
    for (int i = 0; i < mergeN; i++)
    {
        cout << mergeArr[i] << " ";
    }
    cout << "\n";

    mergeSort(mergeArr, 0, mergeN - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < mergeN; i++)
    {
        cout << mergeArr[i] << " ";
    }
    cout << "\n";

    cout << "\n--- Shell Sort ---\n";
    int shellArr[] = {12, 34, 54, 2, 3};
    int shellN = sizeof(shellArr) / sizeof(shellArr[0]);

    cout << "Original array: ";
    for (int i = 0; i < shellN; i++)
    {
        cout << shellArr[i] << " ";
    }
    cout << "\n";

    shellSort(shellArr, shellN);

    cout << "Sorted array: ";
    for (int i = 0; i < shellN; i++)
    {
        cout << shellArr[i] << " ";
    }
    cout << "\n";

    cout << "\n--- Quick Sort ---\n";
    int quickArr[] = {10, 7, 8, 9, 1, 5};
    int quickN = sizeof(quickArr) / sizeof(quickArr[0]);

    cout << "Original array: ";
    for (int i = 0; i < quickN; i++)
    {
        cout << quickArr[i] << " ";
    }
    cout << "\n";

    quickSort(quickArr, 0, quickN - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < quickN; i++)
    {
        cout << quickArr[i] << " ";
    }
    cout << "\n";

    return 0;
}
