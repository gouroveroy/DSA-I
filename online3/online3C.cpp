#include <iostream>
#include <string>
#include "Task_1_stack.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    Stack<char> st;
    int max = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else if (s[i] == ')')
        {
            st.pop();
            count--;
        }
    }
    cout << max << endl;
    return 0;
}