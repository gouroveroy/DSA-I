#include <iostream>
using namespace std;

template <class E>
class Stack
{
    int top;
    E *Arr;
    int chunk_size;
    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        E *new_Arr = new E[new_chunk_size];
        int i = 0;
        while (i < top)
        {
            new_Arr[i] = Arr[i];
            i++;
        }
        if (top > 0)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
        chunk_size = new_chunk_size;
    }

public:
    Stack(int X = 1)
    {
        top = 0;
        chunk_size = X;
        Arr = new E[chunk_size];
    }

    ~Stack()
    {
        top = 0;
        chunk_size = 0;
        delete[] Arr;
    }

    void print_stack()
    {
        if (top == 0)
        {
            cout << "<>" << endl;
        }
        else
        {
            cout << '<';
            for (int i = 0; i < top - 1; i++)
            {
                cout << Arr[i] << ", ";
            }
            cout << Arr[top - 1] << '>';
            cout << endl;
        }
    }

    // Reinitialize the stack, i.e., make it (logically) empty stack. <> means an empty stack.

    void clear()
    {
        while (top > 0)
        {
            pop();
        }
    }

    // Pushes an element.

    void push(E item)
    {
        if (top == chunk_size)
        {
            increase_chunk_size();
        }
        Arr[top] = item;
        top++;
    }

    // Pop the top element.

    E pop()
    {
        if (top == 0)
        {
            return 0;
        }
        else
        {
            top--;
            E rt = Arr[top - 1];
            E *new_Arr = new E[chunk_size];
            top--;
            for(int i = 0; i < top; i++)
            {
                new_Arr[i] = Arr[i];
            }
            if(top > 0)
            {
                delete[] Arr;
            }
            Arr = new_Arr;
            return rt;
        }
    }

    // Return the number of elements in the list.

    int length()
    {
        return top;
    }

    // Return the top element.

    E topValue()
    {
        if (top == 0)
        {
            E topvalue = 0;
            cout << "Returned value is 0.";
            return topvalue;
        }
        return Arr[top - 1];
    }

    // If we have an empty stack, then this function will return true; otherwise, it will return false.
    bool isEmpty()
    {
        if (top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};