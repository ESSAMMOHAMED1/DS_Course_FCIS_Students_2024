#include <iostream>
using namespace std;

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
    }
}

int main()
{
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);

    cout << "Selection Sort Result: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
