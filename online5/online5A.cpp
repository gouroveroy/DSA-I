#include <iostream>
#include <string>
using namespace std;

template <class E>
class Node
{
public:
    E data;
    Node<E> *left_child;
    Node<E> *right_child;
    int count;
    Node()
    {
        data = 0;
        left_child = NULL;
        right_child = NULL;
        count = 0;
    }
};

template <class E>
class BST
{
    Node<E> *root;
    int nodecount;

    Node<E> *allocate(Node<E> *left_child, E item, Node<E> *right_child)
    {
        Node<E> *new_Node = new Node<E>;
        new_Node->data = item;
        new_Node->left_child = left_child;
        new_Node->right_child = right_child;
        new_Node->count++;
        return new_Node;
    }

    void printBSThelp(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }

        else if (root->left_child == NULL && root->right_child == NULL)
        {
            if (root->count == 1)
            {
                cout << root->data;
            }
            else
            {
                cout << root->data << "[" << root->count << "]";
            }
        }

        else if (root->left_child != NULL && root->right_child == NULL)
        {
            if (root->count == 1)
            {
                cout << root->data;
            }
            else
            {
                cout << root->data << "[" << root->count << "]";
            }
            cout << "(";
            printBSThelp(root->left_child);
            cout << ",)";
        }

        else if (root->left_child == NULL && root->right_child != NULL)
        {
            if (root->count == 1)
            {
                cout << root->data;
            }
            else
            {
                cout << root->data << "[" << root->count << "]";
            }
            cout << "(,";
            printBSThelp(root->right_child);
            cout << ")";
        }

        else if (root->left_child != NULL && root->right_child != NULL)
        {
            if (root->count == 1)
            {
                cout << root->data;
            }
            else
            {
                cout << root->data << "[" << root->count << "]";
            }
            cout << "(";
            printBSThelp(root->left_child);
            cout << ",";
            printBSThelp(root->right_child);
            cout << ")";
        }
    }

    Node<E> *Inserthelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            root = allocate(NULL, item, NULL);
        }

        else if (item == root->data)
        {
            root->count++;
        }

        else if (item < root->data)
        {
            if (root->left_child != NULL)
            {
                root->left_child = Inserthelp(root->left_child, item);
            }

            else
            {
                Node<E> *new_Node = allocate(NULL, item, NULL);
                root->left_child = new_Node;
            }
        }

        else if (item > root->data)
        {
            if (root->right_child != NULL)
            {
                root->right_child = Inserthelp(root->right_child, item);
            }

            else
            {
                Node<E> *new_Node = allocate(NULL, item, NULL);
                root->right_child = new_Node;
            }
        }
        return root;
    }

    Node<E> *Find_inorder_succesor(Node<E> *root)
    {
        Node<E> *new_Node = root->right_child;
        while (new_Node->left_child != NULL)
        {
            new_Node = new_Node->left_child;
        }
        return new_Node;
    }

    Node<E> *Deletehelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            return root;
        }

        else if (item != root->data)
        {
            if (item < root->data)
            {
                root->left_child = Deletehelp(root->left_child, item);
            }

            else if (item > root->data)
            {
                root->right_child = Deletehelp(root->right_child, item);
            }
        }

        else if (item == root->data)
        {
            if (root->count > 1)
            {
                root->count--;
                return root;
            }

            else if (root->left_child == NULL && root->right_child == NULL)
            {
                delete root;
                return NULL;
            }

            else if (root->left_child != NULL && root->right_child == NULL)
            {
                Node<E> *new_Node = root;
                root = root->left_child;
                delete new_Node;
            }

            else if (root->left_child == NULL && root->right_child != NULL)
            {
                Node<E> *new_Node = root;
                root = root->right_child;
                delete new_Node;
            }

            else if (root->left_child != NULL && root->right_child != NULL)
            {
                Node<E> *new_Node = Find_inorder_succesor(root);
                root->data = new_Node->data;
                root->right_child = Deletehelp(root->right_child, new_Node->data);
            }
        }
        return root;
    }

    int Findhelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (item != root->data)
        {
            if (item < root->data)
            {
                return Findhelp(root->left_child, item);
            }

            else if (item > root->data)
            {
                return Findhelp(root->right_child, item);
            }
        }

        else if (item == root->data)
        {
            return root->count;
        }
        return 0;
    }

    void preorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->count == 1)
        {
            cout << root->data << " ";
        }

        else
        {
            cout << root->data << "[" << root->count << "] ";
        }
        preorder(root->left_child);
        preorder(root->right_child);
    }

    void inorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left_child);
        if (root->count == 1)
        {
            cout << root->data << " ";
        }

        else
        {
            cout << root->data << "[" << root->count << "] ";
        }
        inorder(root->right_child);
    }

    void postorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left_child);
        postorder(root->right_child);
        if (root->count == 1)
        {
            cout << root->data << " ";
        }

        else
        {
            cout << root->data << "[" << root->count << "] ";
        }
    }

public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }

    ~BST()
    {
        root = NULL;
        nodecount = 0;
    }

    void printBST()
    {
        cout << "(";
        printBSThelp(root);
        cout << ")" << endl;
    }

    void Insert(E item)
    {
        root = Inserthelp(root, item);
        nodecount++;
    }

    void Delete(E item)
    {
        if (!Find(item))
        {
            return;
        }
        root = Deletehelp(root, item);
        nodecount--;
    }

    int Find(E item)
    {
        return Findhelp(root, item);
    }

    void Traversal(string order)
    {
        if (order == "In")
        {
            inorder(root);
            cout << endl;
        }

        else if (order == "Pre")
        {
            preorder(root);
            cout << endl;
        }

        else if (order == "Post")
        {
            postorder(root);
            cout << endl;
        }
    }
};

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
            int f = bst.Find(item);
            if (f)
            {
                cout << "found " << f << endl;
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