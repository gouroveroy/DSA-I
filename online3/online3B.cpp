#include <iostream>
#include <string>
#include "Task_1_stack.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    int index;
    cin >> index;
    Stack<char> st;
    for (int i = index; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ']')
        {
            st.pop();
        }
        if (st.length() == 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}