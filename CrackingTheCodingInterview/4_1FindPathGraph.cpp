#include <iostream>
#include <vector>
#include <queue>

std::vector<int> adjList[100];

bool searchPath(std::vector<int> adjList[], int startNode, int endNode)
{
    if (startNode == endNode)
    {
        return true;
    }
    std::queue<int> nodesQ;
    int visited[100] = {0};

    nodesQ.push(startNode);
    while (!nodesQ.empty())
    {
        int curNode = nodesQ.front();
        nodesQ.pop();

        for (int neigh : adjList[curNode])
        {
            if (!visited[neigh])
            {
                if (neigh == endNode)
                {
                    return true;
                }
                nodesQ.push(neigh);
            }
        }
        visited[curNode] = 1;
    }
    return false;
}

void addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 4);
    // addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    std::cout << searchPath(adjList, 0, 2);
}