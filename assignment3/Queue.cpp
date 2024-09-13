#include <iostream>
using namespace std;

template <class E>
class Queue
{
    E *Arr;
    int chunk_size;
    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        E *new_Arr = new E[new_chunk_size];
        int i = 0;
        while (i <= back)
        {
            new_Arr[i] = Arr[i];
            i++;
        }
        if ((back + 1) % chunk_size != front)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
        chunk_size = new_chunk_size;
    }

public:
    Queue(int X = 1)
    {
        chunk_size = X + 1;
        Arr = new E[chunk_size];
        front = 1;
        back = 0;
    }

    ~Queue()
    {
        delete[] Arr;
        front = 1;
        back = 0;
    }

    void enqueue(E item)
    {
        if ((back + 2) % chunk_size == front)
        {
            increase_chunk_size();
        }
        back = (back + 1) % chunk_size;
        Arr[back] = item;
    }

    E dequeue()
    {
        if (length() == 0)
        {
            cout << "Queue is empty." << endl;
            return 0;
        }
        E it = Arr[front];
        front = (front + 1) % chunk_size;
        return it;
    }

    int length()
    {
        return back - front + 1;
    }

    E front()
    {
        return Arr[front];
    }

    E back()
    {
        return Arr[back];
    }

    bool is_empty()
    {
        if (length() == 0)
        {
            return true;
        }
        return false;
    }

    void clear()
    {
        while (length() > 0)
        {
            dequeue();
        }
    }

    void print()
    {
        if (length() == 0)
        {
            cout << "<>" << endl;
        }
        else
        {
            cout << "<";
            for (int i = front; i < back; i++)
            {
                cout << Arr[i] << ", ";
            }
            cout << Arr[back] << ">" << endl;
        }
    }
};
