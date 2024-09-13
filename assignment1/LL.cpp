#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class List
{
    Node *head;
    Node *tail;
    Node *curr;
    int len;
    Node *allocate(Node *prev, int item, Node *next)
    {
        Node *new_Node = new Node;
        new_Node->data = item;
        new_Node->prev = prev;
        new_Node->next = next;
        return new_Node;
    }

public:
    // constructor
    List(int X = 1)
    {
        head = NULL;
        tail = NULL;
        curr = NULL;
        len = 0;
    }
    // destructor
    ~List()
    {
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
        tail = NULL;
        curr = NULL;
        len = 0;
    }
    // initialize
    void init(int item)
    {
        if (head == NULL)
        {
            head = allocate(NULL, item, NULL);
            tail = head;
            curr = head;
        }
        else
        {
            Node *new_Node = allocate(NULL, item, NULL);
            new_Node->prev = tail;
            tail->next = new_Node;
            tail = new_Node;
        }
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
            if (curr == head)
            {
                Node *new_Node = head;
                cout << '<';
                cout << "| ";
                while (new_Node != tail)
                {
                    cout << new_Node->data << ", ";
                    new_Node = new_Node->next;
                }
                cout << new_Node->data;
                cout << '>' << endl;
            }
            else
            {
                Node *new_Node = head;
                cout << '<';
                while (new_Node->next != curr)
                {
                    cout << new_Node->data << ", ";
                    new_Node = new_Node->next;
                }
                cout << "| ";
                while (new_Node != tail)
                {
                    cout << new_Node->data << ", ";
                    new_Node = new_Node->next;
                }
                cout << new_Node->data;
                cout << '>' << endl;
            }
        }
    }

    // Inserts an element at the current location.

    void insert(int item)
    {
        if (head == NULL)
        {
            head = allocate(NULL, item, NULL);
            curr = head;
            tail = head;
        }
        else if (curr == head)
        {
            Node *new_Node = allocate(NULL, item, head);
            head->prev = new_Node;
            head = new_Node;
            curr = head;
        }
        else
        {
            Node *new_Node = allocate(curr->prev, item, curr);
            curr->prev->next = new_Node;
            curr->prev = new_Node;
            curr = new_Node;
        }
        len++;
    }

    // Remove and return the current element.

    int remove()
    {
        int rt;
        if(len == 0)
        {
            return -1;
        }
        else if (len == 1)
        {
            rt = head->data;
            delete head;
            head = tail = curr = NULL;
        }
        else if (curr == head)
        {
            rt = curr->data;
            Node *new_Node = head;
            head->next->prev = NULL;
            head = head->next;
            curr = head;
            delete new_Node;
        }
        else if (curr == tail)
        {
            rt = curr->data;
            Node *new_Node = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            curr = tail;
            delete new_Node;
        }
        else
        {
            rt = curr->data;
            Node *new_Node = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr = curr->next;
            delete new_Node;
        }
        len--;
        return rt;
    }

    // Set the current position to the start of the list

    void moveToStart()
    {
        curr = head;
    }

    // Set the current position to the end of the list

    void moveToEnd()
    {
        curr = tail;
    }

    // Move the current position one step left. No change if already at the beginning.

    void prev()
    {
        if (len > 0)
        {
            if (curr != head)
            {
                curr = curr->prev;
            }
        }
    }

    // Move the current position one step right. No change if already at the end.

    void next()
    {
        if (len > 0)
        {
            if (curr != tail)
            {
                curr = curr->next;
            }
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
        Node *new_Node = head;
        int count = 0;
        while (new_Node != curr)
        {
            new_Node = new_Node->next;
            count++;
        }
        return count;
    }

    // Set current position.

    void moveToPos(int pos)
    {
        if (pos >= 0 && pos < len)
        {
            Node *new_Node = head;
            int count = 0;
            while (count != pos)
            {
                new_Node = new_Node->next;
                count++;
            }
            curr = new_Node;
        }
    }

    // Return the current element.

    int getValue()
    {
        return curr->data;
    }
};