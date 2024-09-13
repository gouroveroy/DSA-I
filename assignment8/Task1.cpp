#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Build2DFence
{
    vector<pair<int, int>> trees;
    vector<pair<int, int>> convexPolygon;
    int pointNo;

    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first < p2.first)
        {
            return true;
        }
        if (p1.first > p2.first)
        {
            return false;
        }
        return p1.second < p2.second;
    }

    bool isOutsideConvexPolygon(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
    {
        if ((((p.second - p1.second) * (p2.first - p1.first)) - ((p.first - p1.first) * (p2.second - p1.second))) > 0)
        {
            return true;
        }
        return false;
    }

    int distanceFromLine(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
    {
        return abs(((p.second - p1.second) * (p2.first - p1.first)) - ((p.first - p1.first) * (p2.second - p1.second)));
    }

    void buildConvexPolygon(pair<int, int> p1, pair<int, int> p2, bool isRightSide)
    {
        int index = INT_MIN;
        int maxDistance = 0;

        for (int i = 0; i < pointNo; i++)
        {
            int distance = distanceFromLine(p1, p2, trees[i]);
            if (isOutsideConvexPolygon(p1, p2, trees[i]) == isRightSide && distance > maxDistance)
            {
                index = i;
                maxDistance = distance;
            }
        }

        if (index == INT_MIN)
        {
            convexPolygon.push_back(p1);
            convexPolygon.push_back(p2);
            return;
        }

        buildConvexPolygon(p1, trees[index], !isOutsideConvexPolygon(p1, trees[index], p2));
        buildConvexPolygon(p2, trees[index], !isOutsideConvexPolygon(p2, trees[index], p1));
    }

public:
    Build2DFence(vector<pair<int, int>> &coordinates, int N)
    {
        trees = coordinates;
        pointNo = N;
    }

    void printConvexPolygon()
    {
        sort(trees.begin(), trees.end(), compare);
        pair<int, int> minPointX = trees[0];
        pair<int, int> maxPointX = trees[trees.size() - 1];

        buildConvexPolygon(minPointX, maxPointX, true);
        buildConvexPolygon(minPointX, maxPointX, false);

        sort(convexPolygon.begin(), convexPolygon.end(), compare);
        auto iterator = unique(convexPolygon.begin(), convexPolygon.end());
        convexPolygon.erase(iterator, convexPolygon.end());

        if (convexPolygon.size() < 3)
        {
            cout << "This point's can't form a Convex Polygon" << endl;
        }

        for (pair<int, int> p : convexPolygon)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int N;
    cin >> N;
    vector<pair<int, int>> coordinates(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    Build2DFence bf(coordinates, N);
    bf.printConvexPolygon();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
