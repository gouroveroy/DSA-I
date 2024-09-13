#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool flag = true;
    for (int i = 0; i < s.length(); i += 2)
    {
        if (s[i] != s[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        for (int i = 0; i < s.length(); i += 2)
        {
            cout << s[i];
        }
        cout << " ";
        for (int i = s.length() - 1; i > 0; i -= 2)
        {
            cout << s[i];
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}