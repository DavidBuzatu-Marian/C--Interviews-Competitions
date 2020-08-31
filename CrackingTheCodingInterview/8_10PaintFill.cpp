#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <time.h>

bool isSameColor(char currentC, char initC)
{
    return currentC == initC;
}

bool isInMatrix(int rows, int cols, int i, int j)
{
    return (i < rows && j < cols && i >= 0 && j >= 0);
}

void BFS(std::vector<std::vector<char>> &mat, int startI, int endI, char color)
{
    std::queue<std::pair<int, int>> q;
    if (startI > mat.size() || endI > mat[0].size() || startI < 0 || endI < 0)
    {
        return;
    }
    char initC = mat[startI][endI];
    int positionsI[] = {0, 0, -1, 1};
    int positionsJ[] = {-1, 1, 0, 0};
    mat[startI][endI] = color;
    q.push({startI, endI});
    while (!q.empty())
    {
        auto point = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int newI = point.first + positionsI[k];
            int newJ = point.second + positionsJ[k];
            if (isInMatrix(mat.size(), mat[0].size(), newI, newJ) && isSameColor(mat[newI][newJ], initC))
            {
                mat[newI][newJ] = color;
                q.push({newI, newJ});
            }
        }
    }
}

void print_matrix(std::vector<std::vector<char>> matrix)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int sI, eI;
    std::vector<std::vector<char>> matrix(10);
    srand(time(NULL));
    char r;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            r = rand() % 3 + 97; // generate character. small seed for similar letters
            matrix[i].push_back(r);
        }
    }
    print_matrix(matrix);
    std::cin >> sI >> eI;
    BFS(matrix, sI, eI, 'a');
    print_matrix(matrix);
    return 0;
}