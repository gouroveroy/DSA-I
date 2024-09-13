#include <iostream>
#include <string>
#include "BST.h"

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    BST<int> bst;
    char key;
    while (cin >> key)
    {
        string str;
        cin >> str;
        if (key == 'I')
        {
            int item = stoi(str);
            bst.Insert(item);
            bst.printBST();
        }
        else if (key == 'D')
        {
            int item = stoi(str);
            bst.Delete(item);
            bst.printBST();
        }
        else if (key == 'F')
        {
            int item = stoi(str);
            if (bst.Find(item))
            {
                cout << "found" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
        else if (key == 'T')
        {
            bst.Traversal(str);
        }
    }
    return 0;
}