#include <iostream>
#include <vector>
#include <set>

std::vector<std::pair<int, int>> findPath(std::vector<std::vector<int>> mat)
{
    if (mat.size() == 0)
    {
        return {};
    }
    std::vector<std::pair<int, int>> path;
    std::set<std::pair<int, int>> visited;
    if (getPath(mat, 0, 0, path, visited))
    {
        return path;
    }
    return {};
}

bool getPath(std::vector<std::vector<int>> mat, int row, int col, std::vector<std::pair<int, int>> &path, std::set<std::pair<int, int>> visited)
{
    if (row >= mat.size() || col >= mat.size() || !mat[row][col])
    {
        return false;
    }

    if (visited.find({row, col}) != visited.end())
    {
        return false;
    }

    if (isAtEnd(row, col, mat.size() - 1, mat[0].size() - 1) || getPath(mat, row + 1, col, path, visited) || getPath(mat, row, col + 1, path, visited))
    {
        path.push_back({row, col});
        return true;
    }

    visited.insert({row, col});
    return false;
}

bool isAtEnd(int row, int col, int n, int m)
{
    return row == n && col == m;
}

int main()
{

    return 0;
}