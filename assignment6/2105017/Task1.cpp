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
    void BFS(int source, int destination)
    {
        queue<int> vertex;
        vertex.push(source);
        color[source] = GRAY;
        distance[source] = 0;
        path.clear();

        while (!vertex.empty())
        {
            int currentVertex = vertex.front();
            vertex.pop();
            if (currentVertex == destination)
            {
                // Build the path
                int node = currentVertex;
                while (node != -1)
                {
                    path.push_back(node);
                    node = parent[node];
                }
                reverse(path.begin(), path.end());
                destinationFound = true;
                return;
            }
            for (int child : graph[currentVertex])
            {
                if (color[child] == WHITE)
                {
                    vertex.push(child);
                    color[child] = GRAY;
                    parent[child] = currentVertex;
                    distance[child] = distance[currentVertex] + WEIGHT;
                }
            }
            color[currentVertex] = BLACK;
        }
    }

    void BFSprint()
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
    Graph.BFS(source, destination);
    Graph.BFSprint();

    return 0;
}
