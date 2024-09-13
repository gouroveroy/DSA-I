#include <iostream>
#include "2105017_1_a_queue.cpp"
// #include "2105017_1_ll_queue.cpp"

using namespace std;

int main()
{
    // int K, X;
    // cout << "Chunk size = ";
    // cin >> X;
    // cout << "The initial length of the queue = ";
    // cin >> K;
    Queue<int> queue;
    int P, type;
    queue.print();
    // for(int i = 0; i < K; i++)
    // {
    // int element;
    // cin >> element;
    // queue.enqueue(element);
    // }
    // queue.print();
    cout << "Select any of them." << endl;
    cout << "0.Exit the program." << endl;
    cout << "1.enqueue(item)" << endl;
    cout << "2.dequeue()" << endl;
    cout << "3.length()" << endl;
    cout << "4.front()" << endl;
    cout << "5.back()" << endl;
    cout << "6.is_empty()" << endl;
    cout << "7.clear()" << endl;
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
            cin >> P;
            queue.enqueue(P);
            queue.print();
        }
        else if (Q == 2)
        {
            type = queue.dequeue();
            queue.print();
            cout << type << endl;
        }
        else if (Q == 3)
        {
            queue.print();
            cout << queue.length() << endl;
        }
        else if (Q == 4)
        {
            queue.print();
            cout << queue.front() << endl;
        }
        else if (Q == 5)
        {
            queue.print();
            cout << queue.back() << endl;
        }
        else if (Q == 6)
        {
            if (queue.is_empty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is non-empty." << endl;
            }
            queue.print();
        }
        else if (Q == 7)
        {
            queue.clear();
            queue.print();
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    }
}
