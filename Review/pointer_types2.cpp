int a = 10;

// 1. Basic Pointer
int* ptr = &a;

// 2. Null Pointer
int* nullPtr = nullptr;

// 3. Void Pointer (generic pointer)
void* vPtr = &a;

// 4. Dangling Pointer (after deleting an allocated pointer)
int* danglingPtr = new int(20);
delete danglingPtr; // Now danglingPtr is a dangling pointer

// 5. Wild Pointer (uninitialized pointer)
int* wildPtr;

// 6. Constant Pointer (pointer to constant data)
const int* constDataPtr = &a;

// 7. Pointer to Constant (data cannot be changed, but pointer can)
int* const constPtr = &a;

// 8. Constant Pointer to Constant Data (neither pointer nor data can change)
const int* const constDataConstPtr = &a;

// 9. Pointer to Pointer
int** ptrToPtr = &ptr;

// 10. Function Pointer
void (*funcPtr)() = nullptr; // Example function pointer (for a void function)

// 11. Array Pointer
int arr[5] = {1, 2, 3, 4, 5};
int* arrPtr = arr; // Points to first element of array

// 12. Pointer to Struct
struct MyStruct { int x; };
MyStruct s;
MyStruct* structPtr = &s;

// 13. This Pointer (used inside class methods)
class MyClass {
public:
    void display() { cout << this << endl; }
};