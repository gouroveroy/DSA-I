#include <iostream>
#include "2105017_1_a_queue.cpp"
// #include "2105017_1_ll_queue.cpp"

using namespace std;

template <class E>
class Stack
{
    Queue<E> st;
    Queue<E> q;
    int size;

public:
    Stack()
    {
        size = 0;
    }
    void print()
    {
        st.reverse_print();
    }
    void clear()
    {
        st.clear();
        size = 0;
    }
    void push(E item)
    {
        q.enqueue(item);
        while (!st.is_empty())
        {
            q.enqueue(st.dequeue());
        }
        while (!q.is_empty())
        {
            st.enqueue(q.dequeue());
        }
        size++;
    }
    E pop()
    {
        if (st.length() == 0)
        {
            cout << "Stack is empty." << endl;
            return 0;
        }
        E it = st.dequeue();
        size--;
        st.reverse_print();
        return it;
    }
    int length()
    {
        return size;
    }
    E topValue()
    {
        return st.front();
    }
    bool isEmpty()
    {
        if (st.is_empty())
        {
            return true;
        }
        return false;
    }
};
