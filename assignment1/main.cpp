#include <iostream>
// #include "LL.cpp"
#include "Arr.cpp"
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
            L.insert(P);
            L.print_list();
            cout << -1 << endl;
        }

        else if (Q == 2)
        {
            int R = L.remove();
            L.print_list();
            cout << R << endl;
        }

        else if (Q == 3)
        {
            L.moveToStart();
            L.print_list();
            cout << -1 << endl;
        }

        else if (Q == 4)
        {
            L.moveToEnd();
            L.print_list();
            cout << -1 << endl;
        }

        else if (Q == 5)
        {
            L.prev();
            L.print_list();
            cout << -1 << endl;
        }

        else if (Q == 6)
        {
            L.next();
            L.print_list();
            cout << -1 << endl;
        }

        else if (Q == 7)
        {
            L.print_list();
            cout << L.length() << endl;
        }

        else if (Q == 8)
        {
            L.print_list();
            cout << L.currPos() << endl;
        }

        else if (Q == 9)
        {
            L.print_list();
            L.moveToPos(P);
            cout << -1 << endl;
        }

        else if (Q == 10)
        {
            L.print_list();
            cout << L.getValue() << endl;
        }

        else
        {
            cout << "Invalid input" << endl;
        }
    }
    return 0;
}
