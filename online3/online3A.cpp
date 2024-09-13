#include <iostream>
#include <string>
#include "Task_1_stack.h"
using namespace std;

bool isNumber(char c)
{
    if (c >= 48 && c <= 57)
    {
        return true;
    }
    return false;
}

bool isCharacter(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}

int Operation(int a, char c, int b)
{
    if (c == '+')
    {
        return a + b;
    }
    else if (c == '-')
    {
        return b - a;
    }
    else if (c == '*')
    {
        return a * b;
    }
    else if (c == '/')
    {
        return b / a;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    Stack<int> st(100);
    for (int i = 0; i < s.length(); i++)
    {
        if (isNumber(s[i]))
        {
            string s1;
            int j = i;
            while (j < s.length() && isNumber(s[j]))
            {
                s1.push_back(s[j]);
                j++;
            }
            int value = stoi(s1);
            st.push(value);
            i = j;
        }
        else if (isCharacter(s[i]))
        {
            char ch = s[i];
            int a = st.pop();
            int b = st.pop();
            int op = Operation(a, ch, b);
            st.push(op);
        }
        else if (s[i] == ' ')
        {
            continue;
        }
    }
    cout << st.topValue() << endl;
    return 0;
}