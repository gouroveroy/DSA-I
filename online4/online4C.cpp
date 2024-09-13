#include <iostream>
#include <algorithm>
#include <string>
#include "2105017_2_stack.h"
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Queue<int> A, C;
    Stack<int> B;
    string s;
    while (1)
    {
        getline(cin, s);
        int a;
        if (s[0] == 'A' || s[0] == 'B')
        {
            string st;
            int i = s.length() - 1;
            while (s[i] >= 48 && s[i] <= 57)
            {
                st.push_back(s[i]);
                i--;
            }
            reverse(st.begin(), st.end());
            a = stoi(st);
        }
        if (s[0] == 'A')
        {
            A.enqueue(a);
            cout << "A takes card " << a << " from deck" << endl;
        }
        else if (s[0] == 'B')
        {
            B.push(a);
            cout << "B takes card " << a << " from deck" << endl;
        }
        else
        {
            if (s[s.length() - 1] == 'A')
            {
                if (A.is_empty())
                {
                    cout << "A has no cards" << endl;
                    continue;
                }
                C.enqueue(A.dequeue());
                cout << "C takes card " << C.back() << " from A" << endl;
            }
            else if (s[s.length() - 1] == 'B')
            {
                if (B.isEmpty())
                {
                    cout << "B has no cards" << endl;
                    continue;
                }
                C.enqueue(B.pop());
                cout << "C takes card " << C.back() << " from B" << endl;
            }
            else
            {
                while(C.length() != 0)
                {
                    cout << "C returns card " << C.dequeue() << endl;
                }
                return 0;
            }
        }
    }
}