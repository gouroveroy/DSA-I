#include <iostream>
//#include "LL.h"
#include"Arr.h"
using namespace std;

int main()
{
    int K, X;
    cin >> K >> X;
    List L(X);
    for (int i = 0; i < K; i++)
    {
        int element;
        cin >> element;
        L.init(element);
    }
    L.print_list();
    int S;
    cout << "Number of several line : ";
    cin >> S;
    while (S--)
    {
        int Q, P;
        cin >> Q >> P;
        if (Q == 0)
        {
            return 0;
        }
        else if (Q == 1)
        {
            L.clear();
            cout << -1 << endl;
        }
        else if (Q == 2)
        {
            L.append(P);
            L.print_list();
            cout << -1 << endl;
        }
        else if (Q == 3)
        {
            int s = L.Search(P);
            L.print_list();
            cout << s << endl;
        }
    }
    return 0;
}