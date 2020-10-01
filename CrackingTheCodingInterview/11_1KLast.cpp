#include <iostream>
#include <fstream>
#include <vector>

void printLastK(char *path)
{
    std::ifstream f;
    f.open(path);
    const int K = 10;
    std::vector<std::string> circularArr(K);
    int size = 0;
    while (std::getline(f, circularArr[size % K]))
    {
        ++size;
    }
    int start = size > K ? size % K : 0;
    int cnt = std::min(size, K);
    for (int i = 0; i < cnt; ++i)
    {
        std::cout << circularArr[(start + i) % K] << '\n';
    }
}

int main()
{
    char path[100];
    std::cin >> path;
    printLastK(path);
    return 0;
}