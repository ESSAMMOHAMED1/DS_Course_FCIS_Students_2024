#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a struct for the heap
struct Heap
{
    vector<int> heap; // Vector to store heap elements
    bool isMaxHeap;   // Flag to determine whether it's a max-heap or min-heap

    // Constructor to initialize the heap type
    Heap(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    // Function to get the parent index
    int parent(int i) { return (i - 1) / 2; }

    // Function to get the left child index
    int leftChild(int i) { return 2 * i + 1; }

    // Function to get the right child index
    int rightChild(int i) { return 2 * i + 2; }

    // Function to compare values based on heap type
    bool compare(int a, int b)
    {
        return isMaxHeap ? (a > b) : (a < b);
    }

    // Function to heapify a subtree rooted at index i
    void heapify(int n, int i)
    {
        int extreme = i; // Initialize the root as the extreme (max/min)
        int left = leftChild(i);
        int right = rightChild(i);

        // Compare with left child
        if (left < n && compare(heap[left], heap[extreme]))
            extreme = left;

        // Compare with right child
        if (right < n && compare(heap[right], heap[extreme]))
            extreme = right;

        // If the extreme is not the root
        if (extreme != i)
        {
            swap(heap[i], heap[extreme]); // Swap root with extreme
            heapify(n, extreme);          // Recursively heapify the affected subtree
        }
    }

    // Function to insert a new value into the heap
    void insert(int value)
    {
        heap.push_back(value); // Add the new value to the end
        int i = heap.size() - 1;

        // Fix the heap property by bubbling up
        while (i != 0 && compare(heap[i], heap[parent(i)]))
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Function to delete the root
    void deleteRoot()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        // Replace root with the last element
        heap[0] = heap.back();
        heap.pop_back(); // Remove the last element

        // Restore the heap property
        heapify(heap.size(), 0);
    }

    // Function to build a heap from the current array
    void buildHeap()
    {
        int n = heap.size();
        for (int i = (n / 2) - 1; i >= 0; i--)
            heapify(n, i);
    }

    // Function to perform heap sort
    void heapSort()
    {
        buildHeap(); // Ensure the array is a valid heap
        int n = heap.size();
        for (int i = n - 1; i > 0; i--)
        {
            swap(heap[0], heap[i]); // Move root to the end
            heapify(i, 0);          // Restore the heap property for the reduced heap
        }
        // After sorting, reverse the array for min-heap to get ascending order
        if (!isMaxHeap)
            reverse(heap.begin(), heap.end());
    }

    // Function to print the heap
    void printHeap()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    // Example for max-heap
    Heap maxHeap(true); // Create a max-heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);

    cout << "Max-Heap after insertion: ";
    maxHeap.printHeap();

    maxHeap.deleteRoot();
    cout << "Max-Heap after deleting root: ";
    maxHeap.printHeap();

    maxHeap.heapSort();
    cout << "Max-Heap after heap sort: ";
    maxHeap.printHeap();

    // Example for min-heap
    Heap minHeap(false); // Create a min-heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(40);

    cout << "Min-Heap after insertion: ";
    minHeap.printHeap();

    minHeap.deleteRoot();
    cout << "Min-Heap after deleting root: ";
    minHeap.printHeap();

    minHeap.heapSort();
    cout << "Min-Heap after heap sort: ";
    minHeap.printHeap();

    return 0;
}
