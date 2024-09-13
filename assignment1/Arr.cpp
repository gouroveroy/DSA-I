#include <iostream>
using namespace std;

class List
{
    int *Arr;
    int curr, len, chunk_size;
    int *allocate(int *new_Arr, int X)
    {
        new_Arr = new int[X]();
        return new_Arr;
    }

    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        int *new_Arr = allocate(new_Arr, new_chunk_size);
        int i = 0;
        while (i < len)
        {
            new_Arr[i] = Arr[i];
            i++;
        }
        if (len > 0)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
    }

public:
    // constructor

    List(int X = 1)
    {
        Arr = new int[X]();
        len = 0;
        chunk_size = X;
        curr = 0;
    }

    // destructor

    ~List()
    {
        delete[] Arr;
        len = 0;
        chunk_size = 1;
        curr = 0;
    }

    // initialize

    void init(int item)
    {
        if (len == chunk_size)
        {
            increase_chunk_size();
        }
        Arr[len] = item;
        len++;
    }

    // prints the list

    void print_list()
    {
        if (len == 0)
        {
            cout << "<>" << endl;
        }

        else
        {
            if (curr == 0)
            {
                int i;
                cout << '<';
                cout << "| ";
                for (i = curr; i < len - 1; i++)
                {
                    cout << Arr[i] << ", ";
                }
                cout << Arr[i];
                cout << '>' << endl;
            }

            else
            {
                int i;
                cout << '<';
                for (i = 0; i < curr - 1; i++)
                {
                    cout << Arr[i] << ", ";
                }
                cout << Arr[i];
                cout << " | ";
                for (i = curr; i < len - 1; i++)
                {
                    cout << Arr[i] << ", ";
                }
                cout << Arr[i];
                cout << '>' << endl;
            }
        }
    }

    // Inserts an element at the current location.

    void insert(int item)
    {
        if (len == chunk_size)
        {
            increase_chunk_size();
        }
        for (int i = len - 1; i >= curr; i--)
        {
            Arr[i + 1] = Arr[i];
        }
        Arr[curr] = item;
        len++;
    }

    // Remove and return the current element.

    int remove()
    {
        if(len == 0)
        {
            return -1;
        }

        if (len > 1 && curr == len - 1)
        {
            curr--;
        }

        else if (curr == 0)
        {
            if (len == 1)
            {
                int *new_Arr = allocate(new_Arr, chunk_size);
                delete[] Arr;
                new_Arr = Arr;
            }

            else
            {
                for (int i = curr; i < len - 1; i++)
                {
                    Arr[i] = Arr[i + 1];
                }
            }
        }

        else
        {
            int *new_Arr = allocate(new_Arr, chunk_size);
            for (int i = 0; i < curr; i++)
            {
                new_Arr[i] = Arr[i];
            }
            for (int i = curr; i < len - 1; i++)
            {
                new_Arr[i] = Arr[i + 1];
            }
            delete[] Arr;
            Arr = new_Arr;
        }
        len--;
        return Arr[curr];
    }

    // Set the current position to the start of the list

    void moveToStart()
    {
        curr = 0;
    }

    // Set the current position to the end of the list

    void moveToEnd()
    {
        curr = len - 1;
    }

    // Move the current position one step left. No change if already at the beginning.

    void prev()
    {
        if (curr > 0)
        {
            curr--;
        }
    }

    // Move the current position one step right. No change if already at the end.

    void next()
    {
        if (curr < len - 1)
        {
            curr++;
        }
    }

    // Return the number of elements in the list.

    int length()
    {
        return len;
    }

    // Return the position (in the list) of the current element.

    int currPos()
    {
        return curr;
    }

    // Set current position.

    void moveToPos(int pos)
    {
        if (pos >= 0 && pos <= len - 1)
        {
            curr = pos;
        }
    }

    // Return the current element.

    int getValue()
    {
        return Arr[curr];
    }
};
