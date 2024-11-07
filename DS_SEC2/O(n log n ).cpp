#include <iostream>
#include <algorithm>  // For std::sort
using namespace std;

int main() {
    int array[] = {5, 3, 8, 1, 2};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, array + size);  // O(n log n)
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
