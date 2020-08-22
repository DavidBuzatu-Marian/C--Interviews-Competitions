#include <iostream>

int computeProductRec(int smaller, int bigger);
int computeProduct(int a, int b);

int computeProduct(int a, int b)
{
    int bigger = a > b ? a : b;
    int smaller = a > b ? b : a;
    return computeProductRec(smaller, bigger);
}

int computeProductRec(int smaller, int bigger)
{
    if (smaller == 0)
    {
        return 0;
    }
    if (smaller == 1)
    {
        return bigger;
    }

    int halfS = smaller >> 1;
    int prod = computeProduct(halfS, bigger);
    if (smaller % 2 == 1)
    {
        return prod + prod + bigger;
    }
    else
    {
        return prod + prod;
    }
}

int main()
{
    std::cout << computeProduct(15, 16) << "\n";
    std::cout << computeProduct(4, 8);
    return 0;
}