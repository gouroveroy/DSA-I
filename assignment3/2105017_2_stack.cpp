#include <iostream>
// #include "2105017_1_a_queue.cpp"
#include "2105017_1_ll_queue.cpp"

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
    void clear()
    {
        st.clear();
        size = 0;
    }
    
    // making push costly

    // void push(E item)
    // {
    //     q.enqueue(item);
    //     while (!st.is_empty())
    //     {
    //         q.enqueue(st.dequeue());
    //     }
    //     while (!q.is_empty())
    //     {
    //         st.enqueue(q.dequeue());
    //     }
    //     size++;
    // }
    // E pop()
    // {
    //     if (st.length() == 0)
    //     {
    //         cout << "Stack is empty." << endl;
    //         return 0;
    //     }
    //     E it = st.dequeue();
    //     size--;
    //     return it;
    // }
    // E topValue()
    // {
    //     return st.front();
    // }
    // void print()
    // {
    //     st.reverse_print();
    // }

    // making pop costly
    
    void push(E item)
    {
        st.enqueue(item);
        size++;
    }
    E pop()
    {
        size--;
        int l = size;
        while (l--)
        {
            q.enqueue(st.dequeue());
        }
        E it = st.dequeue();
        while (!q.is_empty())
        {
            st.enqueue(q.dequeue());
        }
        return it;
    }
    E topValue()
    {
        return st.back();
    }
    void print()
    {
        st.print();
    }

    int length()
    {
        return size;
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
