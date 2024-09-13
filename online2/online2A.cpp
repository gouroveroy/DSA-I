#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
    int m;
    cin >> m;
    List L(m);
    for (int i = 0; i < m; i++)
    {
        int element;
        cin >> element;
        L.init(element);
    }
    int l = 0;
    for (int j = m - 1; j > m / 2; j--)
    {
        L.moveToEnd();
        int curr = L.getValue();
        L.remove();
        L.moveToPos(l + 1);
        l += 2;
        L.insert(curr);
    }
    L.print_list();
    return 0;
}