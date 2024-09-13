#include <iostream>
#include <algorithm>
#include <string>
#include "2105017_1_ll_queue.cpp"
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Queue<int> A, B, C;
    string s;
    while (1)
    {
        getline(cin, s);
        if (s[0] == 'e')
        {
            int a;
            string st;
            int i = s.length() - 1;
            while (s[i] >= 48 && s[i] <= 57)
            {
                st.push_back(s[i]);
                i--;
            }
            reverse(st.begin(), st.end());
            a = stoi(st);
            if (B.length() <= C.length())
            {
                B.enqueue(a);
                cout << "Customer " << B.back() << " enters queue B" << endl;
            }
            else
            {
                C.enqueue(a);
                cout << "Customer " << C.back() << " enters queue C" << endl;
            }
        }
        else if (s[0] == 'A')
        {
            if (A.is_empty())
            {
                cout << "Queue A was already empty" << endl;
                continue;
            }
            cout << "Customer " << A.front() << " gets the loan" << endl;
            A.dequeue();
        }
        else if (s[0] == 'B')
        {
            if (s[2] == 'a')
            {
                if (B.is_empty())
                {
                    cout << "Queue B was already empty" << endl;
                    continue;
                }
                if (B.length() >= C.length())
                {
                    B.enqueue(B.dequeue());
                    cout << "Customer " << B.back() << " enters queue B" << endl;
                }
                else
                {
                    C.enqueue(B.dequeue());
                    cout << "Customer " << C.back() << " enters queue C" << endl;
                }
            }
            else if (s[2] == 'r')
            {
                if (B.is_empty())
                {
                    cout << "Queue B was already empty" << endl;
                    continue;
                }
                C.enqueue(B.dequeue());
                cout << "Customer " << C.back() << " enters queue C" << endl;
            }
        }
        else if (s[0] == 'C')
        {
            if (s[2] == 'a')
            {
                if (C.is_empty())
                {
                    cout << "Queue C was already empty" << endl;
                    continue;
                }
                A.enqueue(C.dequeue());
                cout << "Customer " << A.back() << " enters queue A" << endl;
            }
            else if (s[2] == 'r')
            {
                if (C.is_empty())
                {
                    cout << "Queue C was already empty" << endl;
                    continue;
                }
                if(B.length() >= C.length())
                {
                    B.enqueue(C.dequeue());
                    cout << "Customer " << B.back() << " enters queue B" << endl;
                }
                else
                {
                    C.enqueue(C.dequeue());
                    cout << "Customer " << C.back() << " enters queue C" << endl;
                }
            }
        }
        else
        {
            return 0;
        }
    }
}