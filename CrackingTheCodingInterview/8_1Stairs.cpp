#include <iostream>
#include <vector>

int countSteps(int n)
{
    std::vector<int> steps(n + 1, 0);
    steps[0] = 1;
    steps[1] = 1;
    steps[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        steps[i] = steps[i - 3] + steps[i - 2] + steps[i - 1];
    }
    return steps[n];
}

int main()
{
    std::cout << countSteps(8);
    return 0;
}