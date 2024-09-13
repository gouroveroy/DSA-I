#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
    List A;
    List B;
    int m, n;
    cin >> m >> n;
    int a;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        A.append(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        B.append(a);
    }
    if (m > n)
    {
        B.moveToStart();
        for (int i = 0; i < m - n; i++)
        {
            B.insert(0);
        }
    }
    if (m < n)
    {
        A.moveToStart();
        for (int i = 0; i < n - m; i++)
        {
            A.insert(0);
        }
    }
    int sum = 0;
    int l = A.length();
    int arr[l + 2];
    for (int i = 0; i < l; i++)
    {
        A.moveToPos(l - i - 1);
        B.moveToPos(l - i - 1);
        int s = sum + A.getValue() + B.getValue();
        if (s >= 10)
        {
            arr[i] = s % 10;
            sum = s / 10;
        }
        else
        {
            arr[i] = s;
            sum = s / 10;
        }
    }
    int size = l;
    if (sum != 0)
    {
        arr[size] = sum;
        size = l + 1;
    }
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}