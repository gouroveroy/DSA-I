#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define WEIGHT 1

class Graph
{
    vector<vector<int>> graph;
    vector<int> color;
    vector<int> parent;
    vector<int> distance;
    vector<int> path;
    bool destinationFound;

public:
    // Constructor
    Graph(int vertices)
    {
        graph.resize(vertices);
        color.assign(vertices, WHITE);
        parent.assign(vertices, -1);
        distance.assign(vertices, INT_MAX);
        path.resize(vertices);
        destinationFound = false;
    }

    Graph(vector<vector<int>> &inputGraph)
    {
        graph = inputGraph;
        int vertices = 0;
        for (vector<int> v : graph)
        {
            vertices += v.size();
        }
        color.assign(vertices, WHITE);
        parent.assign(vertices, -1);
        distance.assign(vertices, INT_MAX);
        destinationFound = false;
    }

    void setDistanceAndPath(int source)
    {
        distance[source] = 0;
        path.clear();
    }

    void DFS(int source, int destination)
    {
        color[source] = GRAY;
        path.push_back(source);
        if (source == destination)
        {
            destinationFound = true;
            return;
        }
        for (int child : graph[source])
        {
            if (color[child] == WHITE)
            {
                parent[child] = source;
                color[child] = GRAY;
                distance[child] = distance[source] + WEIGHT;
                DFS(child, destination);
            }
            else
            {
                continue;
            }
        }
        color[source] = BLACK;
    }

    void DFSprint()
    {
        if (destinationFound)
        {
            cout << path.size() - 1 << endl;
            for (int vertex : path)
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<vector<int>> graph;
    int vertices, edges;
    cin >> vertices >> edges;
    graph.resize(vertices);
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    Graph Graph(graph);
    int source, destination;
    cin >> source >> destination;
    Graph.setDistanceAndPath(source);
    Graph.DFS(source, destination);
    Graph.DFSprint();

    return 0;
}
