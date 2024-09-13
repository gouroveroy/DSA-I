#include <iostream>
using namespace std;

template <class E>
class List
{
    E *Arr;
    int curr, len, chunk_size;
    int back;
    int front;
    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        E *new_Arr = new E[new_chunk_size];
        int index = front;
        for (int i = 0; i < len; i++)
        {
            new_Arr[i + 1] = Arr[index];
            index = (index + 1) % chunk_size;
        }
        front = 1;
        back = len;
        delete[] Arr;
        Arr = new_Arr;
        chunk_size = new_chunk_size;
    }

public:
    // constructor
    List(int X = 1)
    {
        chunk_size = X + 1;
        Arr = new E[chunk_size];
        len = 0;
        curr = 1;
        front = 1;
        back = 0;
    }
    // destructor
    ~List()
    {
        delete[] Arr;
        front = 1;
        back = 0;
        len = 0;
        curr = 1;
        chunk_size = 0;
    }
    // initialize
    void init(E item)
    {
        if (len + 1 == chunk_size)
        {
            increase_chunk_size();
        }
        back = (back + 1) % chunk_size;
        Arr[back] = item;
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
            cout << "<";
            int index = front;
            for (int i = 0; i < len - 1; i++)
            {
                cout << Arr[index] << ", ";
                index = (index + 1) % chunk_size;
            }
            cout << Arr[index] << ">" << endl;
        }
    }

    void reverse_print()
    {
        if (len == 0)
        {
            cout << "<>" << endl;
        }
        else
        {
            cout << "<";
            int index = back;
            for (int i = 0; i < len - 1; i++)
            {
                cout << Arr[index] << ", ";
                index = (index - 1 + chunk_size) % chunk_size;
            }
            cout << Arr[index] << ">" << endl;
        }
    }

    // Inserts an element at the current location.
    // No need for this assignment
    void insert(E item)
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

    E remove()
    {
        if (curr == back)
        {
            E iter = Arr[curr];
            back = (back - 1 + chunk_size) % chunk_size;
            curr = back;
            len--;
            return iter;
        }
        // only this else if portion will be needed for this assignment
        else if (curr == front)
        {
            E iter = Arr[curr];
            E *new_Arr = new E[chunk_size];
            front = (front + 1) % chunk_size;
            int index = front;
            len--;
            for (int i = 0; i < len; i++)
            {
                new_Arr[i + 1] = Arr[index];
                index = (index + 1) % chunk_size;
            }
            front = 1;
            back = len;
            delete[] Arr;
            Arr = new_Arr;
            curr = front;
            return iter;
        }
        else
        {
            E iter = Arr[curr];
            E *new_Arr = new E[chunk_size];
            for (int i = front; i < curr; i++)
            {
                new_Arr[i] = Arr[i];
            }
            for (int i = curr; i < back; i++)
            {
                new_Arr[i] = Arr[i + 1];
            }
            delete[] Arr;
            Arr = new_Arr;
            len--;
            return iter;
        }
    }

    // Set the current position to the start of the list

    void moveToStart()
    {
        if (len == 0)
        {
            return;
        }
        curr = front;
    }

    // Set the current position to the end of the list

    void moveToEnd()
    {
        if (len == 0)
        {
            return;
        }
        curr = back;
    }

    // Move the current position one step left. No change if already at the beginning.

    void prev()
    {
        if (curr > front)
        {
            curr = (curr - 1 + chunk_size) % chunk_size;
        }
    }

    // Move the current position one step right. No change if already at the end.

    void next()
    {
        if (curr < back)
        {
            curr = (curr + 1) % chunk_size;
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
        if (pos >= 0 && pos < len)
        {
            curr = (front + pos) % chunk_size;
        }
        else
        {
            cout << "Incorrect position." << endl;
        }
    }

    // Return the current element.

    E getValue()
    {
        if (len == 0)
        {
            cout << "The container is empty.Returned value 0." << endl;
            return 0;
        }
        return Arr[curr];
    }

    // Clear contents from the list, to make it empty. <> means an empty list.

    void clear()
    {
        delete[] Arr;
        chunk_size = 2;
        Arr = new E[chunk_size];
        front = 1;
        back = 0;
        curr = front;
        len = 0;
    }

    // Appends an element at the end of the list.

    void append(E item)
    {
        if ((back + 2) % chunk_size == front)
        {
            increase_chunk_size();
        }
        back = (back + 1) % chunk_size;
        Arr[back] = item;
        len++;
    }

    // Search returns the position of the element item or -1 if not found.

    int Search(E item)
    {
        if (Arr[0] == item)
        {
            return 0;
        }
        else if (Arr[len - 1] == item)
        {
            currPos();
            return len - 1;
        }
        else
        {
            int pos = currPos();
            moveToStart();
            int count = 0;
            while (getValue() != item && curr != len - 1)
            {
                next();
                count++;
            }
            moveToPos(pos);
            if (count == len - 1)
            {
                return -1;
            }
            else
            {
                return count;
            }
        }
    }
};
