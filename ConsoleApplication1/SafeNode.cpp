#include "SafeNode.h"

std::vector<bool> visited;
std::vector<bool> safe;

void SetVector(const int graphLength)
{
    visited = std::vector<bool>(graphLength, false);
    safe = std::vector<bool>(graphLength, false);
}

bool isSafeNode(const int node, std::vector<std::vector<int>>& graph)
{
    if (visited[node]) return safe[node];
    
    visited[node] = true;

    for (const int neighbor : graph[node]) if (!isSafeNode(neighbor,graph)) return false;

    safe[node] = true;
    return true;
}

std::vector<int> EventualSafeNodes(std::vector<std::vector<int>>& graph)
{
    std::vector<int> result;
    SetVector(graph.size());
    for (int i = 0; i < graph.size(); ++i)
    {
        if (isSafeNode(i,  graph))
        {
            result.push_back(i);
        }
    }
    return result;
}
