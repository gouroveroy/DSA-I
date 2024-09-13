#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrainSchedule
{
    vector<pair<int, int>> v;
    int TrainNo;
    int platForm;
    int answer;

    // reset variables before switching another function
    void reset()
    {
        platForm = 1;
        answer = 1;
    }

    // this funtion returns maximum of two elements
    int max(int &a, int &b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

public:
    // constructor
    TrainSchedule(vector<pair<int, int>> &v, int N)
    {
        this->v = v;
        TrainNo = N;
        platForm = 1;
        answer = 1;
    }

    // this funtion works with O(n^2) complexity
    int NumberOfPlatform1()
    {
        reset();
        for (int i = 0; i < TrainNo; i++)
        {
            platForm = 1;
            for (int j = 0; j < TrainNo; j++)
            {
                if (i != j)
                {
                    if (v[i].first >= v[j].first && v[i].first <= v[j].second)
                    {
                        platForm++;
                    }
                }
            }
            answer = max(answer, platForm);
        }
        return answer;
    }

    // this funtion works with O(nlogn) complexity
    int NumberOfPlatform2()
    {
        reset();
        vector<int> arrival(TrainNo);
        vector<int> departure(TrainNo);

        for (int i = 0; i < TrainNo; i++)
        {
            arrival[i] = v[i].first;
            departure[i] = v[i].second;
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        for (int i = 1, j = 0; i < TrainNo && j < TrainNo;)
        {
            if (arrival[i] < departure[j])
            {
                platForm++;
                i++;
            }

            else if (arrival[i] >= departure[j])
            {
                platForm--;
                j++;
            }

            answer = max(answer, platForm);
        }
        return answer;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    TrainSchedule ts(v, N);
    // int platForm = ts.NumberOfPlatform1();
    int platForm = ts.NumberOfPlatform2();
    cout << platForm << endl;
    
    fclose(stdin);
    return 0;
}
