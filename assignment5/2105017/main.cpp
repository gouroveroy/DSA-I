#include <iostream>
#include "Priority_Queue.h"
using namespace std;

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