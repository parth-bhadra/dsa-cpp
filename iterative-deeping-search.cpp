// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int noOfNodes; // nodes are numbered from 0 to n-1;
    vector<vector<int>> adjacenyList;
    bool depthLimitSearch(int source, int destination, int maxDepth);

public:
    Graph(int noOfNodes);
    void addEdge(int u, int v);
    bool iterativeDeepeningSearch(int source, int destination, int allowedDepth);
};

Graph::Graph(int noOfNodes)
{
    this->noOfNodes = noOfNodes;
    adjacenyList.resize(noOfNodes);
}

void Graph::addEdge(int u, int v)
{ // this is a directed graph
    adjacenyList[u].push_back(v);
}

bool Graph::iterativeDeepeningSearch(int source, int destination, int allowedDepth)
{
    for (int i = 1; i <= allowedDepth; i++)
    {
        if (depthLimitSearch(source, destination, i))
        {
            return true;
        }
    }

    return false;
}

bool Graph::depthLimitSearch(int source, int destination, int allowedDepth)
{
    if (source == destination)
    {
        return true;
    }

    if (allowedDepth == 0)
    {
        return false;
    }

    for (int i = 0; i < adjacenyList[source].size(); ++i)
    {
        int localSource = adjacenyList[source][i];
        if (depthLimitSearch(localSource, destination, allowedDepth - 1))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    int target = 6, maxDepth = 3, src = 0;
    if (g.iterativeDeepeningSearch(src, target, maxDepth) == true)
        cout << "Target is reachable from source "
                "within max depth";
    else
        cout << "Target is NOT reachable from source "
                "within max depth";
    return 0;
}
