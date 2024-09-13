#include <iostream>
#include "2105017_2_stack.h"
using namespace std;

int main()
{
    Stack<int> stack;
    int P, type;
    stack.print();
    cout << "Select any of them." << endl;
    cout << "0.Exit the program." << endl;
    cout << "1.clear()" << endl;
    cout << "2.push(item)" << endl;
    cout << "3.pop()" << endl;
    cout << "4.length()" << endl;
    cout << "5.topValue()" << endl;
    cout << "6.isEmpty()" << endl;
    while (1)
    {
        int Q;
        cin >> Q;
        if (Q == 0)
        {
            return 0;
        }
        else if (Q == 1)
        {
            stack.clear();
            stack.print();
        }
        else if (Q == 2)
        {
            cin >> P;
            stack.push(P);
            stack.print();
        }
        else if (Q == 3)
        {
            if (stack.length() == 0)
            {
                cout << "Stack is empty.Can't pop." << endl;
                stack.print();
            }
            else
            {
                type = stack.pop();
                stack.print();
                cout << type << endl;
            }
        }
        else if (Q == 4)
        {
            stack.print();
            cout << stack.length() << endl;
        }
        else if (Q == 5)
        {
            stack.print();
            cout << stack.topValue() << endl;
        }
        else if (Q == 6)
        {
            stack.print();
            if (stack.isEmpty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is non-empty." << endl;
            }
        }
    }
}
