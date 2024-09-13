#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
    List L(1000);
    int n;
    cin >> n;
    char ch;
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        L.append(ch);
    }
    bool flag = true;
    for (int i = 0; i < n / 2; i++)
    {
        L.moveToPos(i);
        char curr = L.getValue();
        L.moveToPos(n - i - 1);
        if (curr != L.getValue())
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}