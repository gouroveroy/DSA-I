#include <iostream>
using namespace std;

#define MAXSIZE 1

template <class E>
class Priority_Queue
{
    E *Arr;
    int chunk_size;
    int heapsize;

    void Swap(E &a, E &b)
    {
        E temp = a;
        a = b;
        b = temp;
    }

    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        E *new_Arr = new E[new_chunk_size]();
        for (int i = 0; i < heapsize; i++)
        {
            new_Arr[i] = Arr[i];
        }
        if (heapsize > 0)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
        chunk_size = new_chunk_size;
    }

    int left_child(int index)
    {
        return 2 * index + 1;
    }

    int right_child(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void Maxheapify(int index)
    {
        if (heapsize == 0 && index < heapsize)
        {
            return;
        }

        int tempindex;
        int leftchild = left_child(index);
        int rightchild = right_child(index);

        if (leftchild < heapsize && Arr[leftchild] > Arr[index])
        {
            tempindex = leftchild;
        }

        else
        {
            tempindex = index;
        }

        if (rightchild < heapsize && Arr[rightchild] > Arr[tempindex])
        {
            tempindex = rightchild;
        }

        if (tempindex != index)
        {
            Swap(Arr[index], Arr[tempindex]);
            Maxheapify(tempindex);
        }

        else
        {
            return;
        }
    }

    int height(int index)
    {
        if (heapsize == 0)
        {
            return -1;
        }

        else if (index >= heapsize)
        {
            return 0;
        }

        else
        {
            int lheight = height(left_child(index));
            int rheight = height(right_child(index));

            if (lheight > rheight)
            {
                return ++lheight;
            }

            else
            {
                return ++rheight;
            }
        }
    }

    void printCurrentLevel(int index, int level)
    {
        if (heapsize == 0)
        {
            return;
        }

        else if (index >= heapsize)
        {
            return;
        }

        else if (level == 0)
        {
            cout << Arr[index] << "\t";
        }

        else
        {
            printCurrentLevel(left_child(index), level - 1);
            printCurrentLevel(right_child(index), level - 1);
        }
    }

public:
    Priority_Queue(int maxsize = MAXSIZE)
    {
        chunk_size = maxsize;
        Arr = new E[chunk_size]();
        heapsize = 0;
    }

    ~Priority_Queue()
    {
        chunk_size = 0;
        delete[] Arr;
        heapsize = 0;
    }

    void Insert(E key)
    {
        if (heapsize == chunk_size)
        {
            increase_chunk_size();
        }
        Arr[heapsize] = key;
        heapsize++;
        int curr = heapsize - 1;
        while (curr != 0 && Arr[curr] > Arr[parent(curr)])
        {
            Swap(Arr[curr], Arr[parent(curr)]);
            curr = parent(curr);
        }
    }

    E FindMax()
    {
        return Arr[0];
    }

    E ExtractMax()
    {
        if (heapsize == 0)
        {
            cout << "Priority queue is empty.Returned value 0." << endl;
            E rt = 0;
            return rt;
        }
        E max = Arr[0];
        Arr[0] = Arr[--heapsize];
        E *new_Arr = new E[chunk_size]();
        for (int i = 0; i < heapsize; i++)
        {
            new_Arr[i] = Arr[i];
        }
        if (heapsize > 0)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
        Maxheapify(0);
        return max;
    }

    void IncreaseKey(int index, E newKey)
    {
        if (newKey <= Arr[index])
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }
        Arr[index] = newKey;
        int curr = index;
        while (curr != 0 && Arr[curr] > Arr[parent(curr)])
        {
            Swap(Arr[curr], Arr[parent(curr)]);
            curr = parent(curr);
        }
        cout << "Key increased!" << endl;
    }

    void DecreaseKey(int index, E newkey)
    {
        if (newkey >= Arr[index])
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }
        Arr[index] = newkey;
        Maxheapify(index);
        cout << "Key decreased!" << endl;
    }

    void Print()
    {
        if (heapsize != 0)
        {
            cout << "No of elements: " << heapsize << endl;
            int h = height(0);
            cout << Arr[0] << endl;
            for (int i = 1; i < h; i++)
            {
                printCurrentLevel(0, i);
                cout << endl;
            }
        }
    }

    void Sort()
    {
        int size = heapsize;
        for (int i = heapsize - 1; i >= 1; i--)
        {
            Swap(Arr[0], Arr[i]);
            heapsize--;
            Maxheapify(0);
        }
        heapsize = size;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    Priority_Queue<int> heap;
    while (1)
    {
        // cout << "1.Insert(item)" << endl;
        // cout << "2.FindMax()" << endl;
        // cout << "3.ExtractMax()" << endl;
        // cout << "4.IncreaseKey(index, newKey)" << endl;
        // cout << "5.DecreaseKey(index, newKey)" << endl;
        // cout << "6.Print()" << endl;
        // cout << "7.exit" << endl;
        // cout << "Enter choice : ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int key;
            cin >> key;
            heap.Insert(key);
        }

        else if (choice == 2)
        {
            cout << "Max: " << heap.FindMax() << endl;
        }

        else if (choice == 3)
        {
            cout << "Max: " << heap.ExtractMax() << " has been extracted." << endl;
        }

        else if (choice == 4)
        {
            int index, newkey;
            cin >> index >> newkey;
            heap.IncreaseKey(index - 1, newkey);
        }

        else if (choice == 5)
        {
            int index, newkey;
            cin >> index >> newkey;
            heap.DecreaseKey(index - 1, newkey);
        }

        else if (choice == 6)
        {
            heap.Print();
        }

        else if (choice == 7)
        {
            heap.Sort();
            heap.Print();
            return 0;
        }

        else
        {
            cout << "Invalid input." << endl;
        }
    }
}