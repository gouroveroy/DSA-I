#include <iostream>
using namespace std;

template <class E>
class Node
{
public:
    E data;
    Node<E> *prev;
    Node<E> *next;
};

template <class E>
class List
{
    Node<E> *head;
    Node<E> *tail;
    Node<E> *curr;
    Node<E> *allocate(Node<E> *prev, E item, Node<E> *next)
    {
        Node<E> *new_Node = new Node<E>;
        new_Node->data = item;
        new_Node->prev = prev;
        new_Node->next = next;
        return new_Node;
    }
    int len;

public:
    // constructor
    List()
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
    void init(E item)
    {
        if (head == NULL)
        {
            head = allocate(NULL, item, NULL);
            tail = head;
            curr = head;
        }
        else
        {
            Node<E> *new_Node = allocate(NULL, item, NULL);
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
            Node<E> *new_Node = head;
            cout << '<';
            while (new_Node != tail)
            {
                cout << new_Node->data << ", ";
                new_Node = new_Node->next;
            }
            cout << new_Node->data;
            cout << '>' << endl;
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
            Node<E> *new_Node = tail;
            cout << '<';
            while (new_Node != head)
            {
                cout << new_Node->data << ", ";
                new_Node = new_Node->prev;
            }
            cout << new_Node->data;
            cout << '>' << endl;
        }
    }

    // Inserts an element at the current location.

    void insert(E item)
    {
        if (head == NULL)
        {
            head = allocate(NULL, item, NULL);
            curr = head;
            tail = head;
        }
        else if (curr == head)
        {
            Node<E> *new_Node = allocate(NULL, item, head);
            head->prev = new_Node;
            head = new_Node;
            curr = head;
        }
        else
        {
            Node<E> *new_Node = allocate(curr->prev, item, curr);
            curr->prev->next = new_Node;
            curr->prev = new_Node;
            curr = new_Node;
        }
        len++;
    }

    // Remove and return the current element.

    E remove()
    {
        if (len == 0)
        {
            return 0;
        }
        if (len == 1)
        {
            E it = curr->data;
            delete head;
            curr = NULL;
            head = tail = curr;
            len--;
            return it;
        }
        else if (curr == head)
        {
            E it = curr->data;
            Node<E> *new_Node = head;
            head->next->prev = NULL;
            head = head->next;
            curr = head;
            delete new_Node;
            len--;
            return it;
        }
        else if (curr == tail)
        {
            Node<E> *new_Node = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            curr = tail;
            delete new_Node;
        }
        else
        {
            Node<E> *new_Node = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr = curr->next;
            delete new_Node;
        }
        return curr->data;
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
        Node<E> *new_Node = head;
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
            Node<E> *new_Node = head;
            int count = 0;
            while (1)
            {
                if (count == pos)
                {
                    break;
                }
                new_Node = new_Node->next;
                count++;
            }
            curr = new_Node;
        }
    }

    // Return the current element.

    E getValue()
    {
        if(len == 0)
        {
            cout << "The container is empty.Returned value 0." << endl;
            return 0;
        }
        return curr->data;
    }

    // Clear contents from the list, to make it empty. <> means an empty list.

    void clear()
    {
        moveToStart();
        while (curr->next != NULL)
        {
            remove();
            next();
        }
        remove();
        curr = head = tail = NULL;
        len = 0;
    }

    // Appends an element at the end of the list.

    void append(E item)
    {
        if (head == NULL)
        {
            head = new Node<E>;
            head->prev = NULL;
            head->data = item;
            head->next = NULL;
            curr = tail = head;
        }
        else
        {
            Node<E> *new_Node = allocate(NULL, item, NULL);
            new_Node->prev = tail;
            tail->next = new_Node;
            tail = new_Node;
        }
        len++;
    }

    // Search returns the position of the element or -1 if not found.

    int Search(E item)
    {
        if (head->data == item)
        {
            currPos();
            return 0;
        }
        else if (tail->data == item)
        {
            currPos();
            return len - 1;
        }
        else
        {
            int pos = currPos();
            moveToStart();
            int count = 0;
            while (getValue() != item && curr != tail)
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