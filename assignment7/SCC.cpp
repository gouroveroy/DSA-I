#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2

class SCC
{
    vector<int> v1, v2;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, vector<int>> graphInv;
    vector<int> color;
    vector<int> colorInv;
    unordered_map<int, int> sccCompare;
    stack<int> st;
    int sccCount;
    int cnfNo;
    int varNo;

public:
    SCC(int m, int n, vector<int> &a, vector<int> &b)
    {
        v1 = a;
        v2 = b;
        cnfNo = n;
        varNo = m;
        color.assign(2 * varNo + 1, WHITE);
        colorInv.assign(2 * varNo + 1, WHITE);
        sccCount = 0;
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graphInv[v].push_back(u);
    }

    void firstDFS(int u)
    {
        if (color[u] != WHITE)
        {
            return;
        }
        color[u] = GRAY;
        for (int &v : graph[u])
        {
            firstDFS(v);
        }
        st.push(u);
    }

    void secondDFS(int u)
    {
        if (colorInv[u] != WHITE)
        {
            return;
        }
        colorInv[u] = GRAY;
        for (int &v : graphInv[u])
        {
            secondDFS(v);
        }
        sccCompare[u] = sccCount;
    }

    void isSatisfiable()
    {
        for (int i = 0; i < cnfNo; i++)
        {
            if (v1[i] == -v2[i])
            {
                addEdge(-v1[i], -v2[i]);
                continue;
            }
            addEdge(-v1[i], v2[i]);
            addEdge(-v2[i], v1[i]);
            // if(v1[i] > 0 && v2[i] > 0)
            // {
            //     addEdge(-v1[i], v2[i]);
            //     addEdge(-v2[i], v1[i]);
            // }
            // else if(v1[i] > 0 && v2[i] < 0)
            // {
            //     addEdge(-v1[i], v2[i]);
            //     addEdge(-v2[i], v1[i]);
            // }
            // if(v1[i] < 0 && v2[i] > 0)
            // {
            //     addEdge(-v1[i], v2[i]);
            //     addEdge(-v2[i], v1[i]);
            // }
            // if(v1[i] > 0 && v2[i] > 0)
            // {
            //     addEdge(-v1[i], v2[i]);
            //     addEdge(-v2[i], v1[i]);
            // }
            // cout << "HELLO " << i << endl;
        }

        for(pair<int, vector<int>> p : graph)
        {
            cout << p.first << " ";
            for(int v : p.second)
            {
                cout << v << " ";
            }
            cout << endl;
        }

        for (int i = 1; i <= varNo; i++)
        {
            firstDFS(i);
        }

        for(int i = -1; i >= -varNo; i--)
        {
            firstDFS(i);
        }

        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            cout << u << endl;
            sccCount++;
            secondDFS(u);
        }

        for(pair<int, int> p : sccCompare)
        {
            cout << p.first << " " << p.second << endl;
        }

        vector<bool> assignment(2 * cnfNo);
        for (int i = 1; i <= varNo; i++)
        {
            if (sccCompare[i] == sccCompare[-i])
            {
                cout << "No assignment possible" << endl;
                return;
            }
            else if (sccCompare[i] > sccCompare[-i])
            {
                assignment[i] = true;
            }
            else
            {
                assignment[i] = false;
            }
        }

        for (int i = 1; i <= varNo; i++)
        {
            cout << char('a' + i - 1) << " ";
            if (assignment[i])
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    vector<char> Unique;
    cin.ignore();

    for (int j = 0; j < n; j++)
    {
        string str;
        getline(cin, str);
        int count = 0;
        char ch1 = 'a', ch2 = 'a';
        bool k1 = false, k2 = false;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z' && count == 0)
            {
                if (i > 0 && str[i - 1] == '~')
                {
                    k1 = true;
                }
                ch1 = str[i];
                Unique.push_back(ch1);
                count++;
            }

            else if (str[i] >= 'a' && str[i] <= 'z' && count == 1)
            {
                if (i > 0 && str[i - 1] == '~')
                {
                    k2 = true;
                }
                ch2 = str[i];
                Unique.push_back(ch2);
                count++;
            }
        }

        if (count < 2)
        {
            if (k1)
            {
                v1[j] = -(ch1 - 'a' + 1);
                v2[j] = (ch1 - 'a' + 1);
            }

            else
            {
                v1[j] = (ch1 - 'a' + 1);
                v2[j] = -(ch1 - 'a' + 1);
            }
        }

        else
        {
            if (k1)
            {
                v1[j] = -(ch1 - 'a' + 1);
            }

            else
            {
                v1[j] = (ch1 - 'a' + 1);
            }

            if (k2)
            {
                v2[j] = -(ch2 - 'a' + 1);
            }

            else
            {
                v2[j] = (ch2 - 'a' + 1);
            }
        }
    }

    // for(int v : v1)
    // {
    //     cout << v << " ";
    // }
    // cout << endl;
    // for(int v : v2)
    // {
    //     cout << v << " ";
    // }
    // cout << endl;

    sort(Unique.begin(), Unique.end());
    auto unq = unique(Unique.begin(), Unique.end());
    Unique.erase(unq, Unique.end());
    int m = Unique.size();

    SCC scc(m, n, v1, v2);
    scc.isSatisfiable();
    return 0;
}
