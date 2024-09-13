#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define WEIGHT 1

class RIDER
{
    int rows, columns, riderNo;
    vector<vector<pair<int, vector<int>>>> graph;
    vector<vector<int>> distance;
    vector<pair<int, int>> movements;
    vector<vector<int>> color;

    bool isValid(int x, int y, int rows, int columns)
    {
        return x >= 0 && x < rows && y >= 0 && y < columns;
    }

public:
    RIDER(int n, int m, int q, vector<vector<pair<int, vector<int>>>> &inputGraph)
    {
        rows = n;
        columns = m;
        riderNo = q;
        graph = inputGraph;
        distance.assign(n, vector<int>(m, INT_MAX));
        movements = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
        color.assign(n, vector<int>(m, WHITE));
    }

    void reset()
    {
        distance.assign(rows, vector<int>(columns, INT_MAX));
        color.assign(rows, vector<int>(columns, WHITE));
    }

    void RiderBFS(int X, int Y)
    {
        queue<pair<int, int>> coordinate;
        coordinate.push({X, Y});
        color[X][Y] = GRAY;
        distance[X][Y] = 0;
        graph[X][Y].first++;
        graph[X][Y].second.push_back(0);
        while (!coordinate.empty())
        {
            pair<int, int> p = coordinate.front();
            coordinate.pop();
            for (auto movement : movements)
            {
                int childX = movement.first + p.first;
                int childY = movement.second + p.second;
                if (!isValid(childX, childY, rows, columns))
                {
                    continue;
                }
                if (color[childX][childY] == WHITE)
                {
                    coordinate.push({childX, childY});
                    color[childX][childY] = GRAY;
                    distance[childX][childY] = distance[p.first][p.second] + WEIGHT;
                    graph[childX][childY].first++;
                    graph[childX][childY].second.push_back(distance[childX][childY]);
                }
            }
            color[p.first][p.second] = BLACK;
        }
    }

    void Print(vector<int> &rider)
    {
        int minimum = INT_MAX;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (graph[i][j].first == riderNo)
                {
                    int sumation = 0;
                    for (int k = 0; k < rider.size(); k++)
                    {
                        sumation += ceil(graph[i][j].second[k] * 1.0 / rider[k]);
                    }
                    minimum = min(minimum, sumation);
                }
            }
        }
        if (minimum == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << minimum << endl;
        }
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, vector<int>>>> Graph(n, vector<pair<int, vector<int>>>(m, {0, vector<int>()}));
    RIDER rider(n, m, q, Graph);
    int x, y;
    vector<int> k(q);
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y >> k[i];
        rider.RiderBFS(x, y);
        rider.reset();
    }
    rider.Print(k);
    return 0;
}
