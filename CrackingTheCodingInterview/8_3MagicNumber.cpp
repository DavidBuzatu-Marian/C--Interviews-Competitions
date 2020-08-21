#include <iostream>
#include <vector>

int findMagicBinary(std::vector<int> arr, int start, int end)
{
    if (end < start)
    {
        return -1;
    }
    int middle = (start + end) / 2;
    if (arr[middle] == middle)
    {
        return middle;
    }
    else if (arr[middle] > middle)
    {
        return findMagicBinary(arr, start, middle - 1);
    }
    else
    {
        return findMagicBinary(arr, middle + 1, end);
    }
}

int main()
{
    std::vector<int> numbers = {-40, -20, -1, 1, 2, 3, 5, 8, 9, 12, 13};
    std::cout << findMagicBinary(numbers, 0, numbers.size());
    return 0;
}