#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <class E>
class Node
{
public:
    E data;
    Node<E> *left_child;
    Node<E> *right_child;
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
            cout << root->data;
        }

        else if (root->left_child != NULL && root->right_child == NULL)
        {
            cout << root->data << "(";
            printBSThelp(root->left_child);
            cout << ",)";
        }

        else if (root->left_child == NULL && root->right_child != NULL)
        {
            cout << root->data << "(,";
            printBSThelp(root->right_child);
            cout << ")";
        }

        else if (root->left_child != NULL && root->right_child != NULL)
        {
            cout << root->data << "(";
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
        Node<E> *new_Node = root;
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

        if (item != root->data)
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
            if (root->left_child == NULL && root->right_child == NULL)
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
                Node<E> *new_Node = Find_inorder_succesor(root->right_child);
                root->data = new_Node->data;
                root->right_child = Deletehelp(root->right_child, new_Node->data);
            }
        }
        return root;
    }

    bool Findhelp(Node<E> *root, E item)
    {
        if (root == NULL)
        {
            return false;
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
            return true;
        }
        return false;
    }

    void preorder(Node<E> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
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
        cout << root->data << " ";
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
        cout << root->data << " ";
    }

    bool subListhelp(Node<E> *root, queue<int> &q)
    {
        if (root == NULL)
        {
            return true;
        }

        if(q.empty())
        {
            return true;
        }

        if (!subListhelp(root->left_child, q))
        {
            return false;
        }

        if (!q.empty() && root->data == q.front())
        {
            q.pop();
        }
        else
        {
            return false;
        }

        return subListhelp(root->right_child, q);
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

    bool Find(E item)
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

    bool subList(queue<int> q)
    {
        return subListhelp(root, q);
    }
};

bool subSequence(BST<int> &bst, queue<int> &q)
{
    bool subS = true;
    while (!q.empty())
    {
        if (!bst.Find(q.front()))
        {
            subS = false;
            break;
        }
        else
        {
            q.pop();
        }
    }
    return subS;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    queue<int> q;
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
        else if (key == 'C')
        {
            int len;
            cin >> len;
            for (int i = 0; i < len; i++)
            {
                int a;
                cin >> a;
                q.push(a);
            }
            if (bst.subList(q))
            {
                cout << "sublist" << endl;
            }
            else if (subSequence(bst, q))
            {
                cout << "subsequence" << endl;
            }
            else
            {
                cout << "none" << endl;
            }
        }
    }
    return 0;
}
