#include <iostream>
#include <vector>
void swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

void print_vector(std::vector<int> arr)
{
    for (int i = 1; i <= 7; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Implementation for max heap
void max_heapify(std::vector<int> &array, int pos, int size)
{
    int left = pos * 2;      // left child
    int right = pos * 2 + 1; // right child
    int maximum_pos = pos;   // used to swap value at max position. Initially is the current node

    std::cout << array[left] << " " << array[right] << " " << array[pos] << "\n";
    // check if there is a child with greater value
    if (left <= size && array[left] > array[pos])
    {
        maximum_pos = left;
    }

    if (right <= size && array[right] > array[maximum_pos])
    {
        maximum_pos = right;
    }

    if (maximum_pos != pos)
    {
        // we found a greater value that was not the root
        swap(array[maximum_pos], array[pos]);
        max_heapify(array, maximum_pos, size);
    }
}

// build the heap
void build_heap(std::vector<int> &array, int size)
{
    for (int i = size / 2; i >= 1; i--)
    {
        max_heapify(array, i, size);
        print_vector(array);
    }
}

int main()
{
    std::vector<int> arr(100);
    for (int i = 1; i <= 7; ++i)
    {
        std::cin >> arr[i];
    }

    build_heap(arr, 7);
    print_vector(arr);
    return 0;
}