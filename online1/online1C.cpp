#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
    }
    int s = 0;
    int i = 1;
    int k = n + 1;
    while (k--)
    {
        s += i;
        i += 2;
    }
    cout << s - sum << endl;
    return 0;
}