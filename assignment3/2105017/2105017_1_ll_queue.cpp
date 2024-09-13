#include <iostream>
#include "2105017_1_ll_queue.h"
using namespace std;

template <class E>
class Queue
{
    List<E> q;

public:
    void enqueue(E item)
    {
        q.append(item);
    }

    E dequeue()
    {
        if (q.length() == 0)
        {
            cout << "Queue is Empty(returned value from function is 0)." << endl;
            return 0;
        }
        q.moveToStart();
        E it = q.remove();
        return it;
    }

    int length()
    {
        return q.length();
    }

    E front()
    {
        if (q.length() == 0)
        {
            cout << "Queue is empty.Returned value -1." << endl;
            return -1;
        }
        q.moveToStart();
        return q.getValue();
    }

    E back()
    {
        if (q.length() == 0)
        {
            cout << "Queue is empty.Returned value -1." << endl;
            return -1;
        }
        q.moveToEnd();
        return q.getValue();
    }

    bool is_empty()
    {
        if (q.length() == 0)
        {
            return true;
        }
        return false;
    }

    void clear()
    {
        q.clear();
    }

    void print()
    {
        q.print_list();
    }

    void reverse_print()
    {
        q.reverse_print();
    }
};
