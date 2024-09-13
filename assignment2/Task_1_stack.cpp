#include <iostream>
using namespace std;

template <class E>
class Stack
{
    int top;
    E *Arr;
    int chunk_size;
    void increase_chunk_size()
    {
        int new_chunk_size = 2 * chunk_size;
        E *new_Arr = new E[new_chunk_size];
        int i = 0;
        while (i < top)
        {
            new_Arr[i] = Arr[i];
            i++;
        }
        if (top > 0)
        {
            delete[] Arr;
        }
        Arr = new_Arr;
        chunk_size = new_chunk_size;
    }

public:
    Stack(int X = 1)
    {
        top = 0;
        chunk_size = X;
        Arr = new E[chunk_size];
    }

    ~Stack()
    {
        top = 0;
        chunk_size = 0;
        delete[] Arr;
    }

    void print_stack()
    {
        if (top == 0)
        {
            cout << "<>" << endl;
        }
        else
        {
            cout << '<';
            for (int i = 0; i < top - 1; i++)
            {
                cout << Arr[i] << ", ";
            }
            cout << Arr[top - 1] << '>';
            cout << endl;
        }
    }

    // Reinitialize the stack, i.e., make it (logically) empty stack. <> means an empty stack.

    void clear()
    {
        while (top > 0)
        {
            pop();
        }
    }

    // Pushes an element.

    void push(E item)
    {
        if (top == chunk_size)
        {
            increase_chunk_size();
        }
        Arr[top] = item;
        top++;
    }

    // Pop the top element.

    E pop()
    {
        if (top == 0)
        {
            return 0;
        }
        else
        {
            top--;
            E rt = Arr[top - 1];
            E *new_Arr = new E[chunk_size];
            top--;
            for(int i = 0; i < top; i++)
            {
                new_Arr[i] = Arr[i];
            }
            if(top > 0)
            {
                delete[] Arr;
            }
            Arr = new_Arr;
            return rt;
        }
    }

    // Return the number of elements in the list.

    int length()
    {
        return top;
    }

    // Return the top element.

    E topValue()
    {
        if (top == 0)
        {
            E topvalue = 0;
            cout << "Returned value is 0.";
            return topvalue;
        }
        return Arr[top - 1];
    }

    // If we have an empty stack, then this function will return true; otherwise, it will return false.
    bool isEmpty()
    {
        if (top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    cout << "what type of stack you would like to construct?" << endl;
    cout << "1.int" << endl
         << "2.char" << endl;
    int stack_type;
    cin >> stack_type;
    if (stack_type == 1)
    {
        int X, K;
        cout << "Chunk size = ";
        cin >> X;
        cout << "The initial length of the stack = ";
        cin >> K;
        Stack<int> stack(X);
        for (int i = 0; i < K; i++)
        {
            int element;
            cin >> element;
            stack.push(element);
        }
        stack.print_stack();
        cout << "Select any of them." << endl;
        cout << "0.Exit the program." << endl;
        cout << "1.clear()" << endl;
        cout << "2.push(item)" << endl;
        cout << "3.pop()" << endl;
        cout << "4.length()" << endl;
        cout << "5.topValue()" << endl;
        cout << "6.isEmpty()" << endl;
        while (1)
        {
            int Q, P;
            cin >> Q;
            if (Q == 0)
            {
                return 0;
            }
            else if (Q == 1)
            {
                stack.clear();
                stack.print_stack();
            }
            else if (Q == 2)
            {
                cin >> P;
                stack.push(P);
                stack.print_stack();
            }
            else if (Q == 3)
            {
                int pop = stack.pop();
                stack.print_stack();
                if (pop == 0)
                {
                    cout << "Stack is empty.Can't pop." << endl;
                }
                else
                {
                    cout << pop << endl;
                }
            }
            else if (Q == 4)
            {
                int len = stack.length();
                stack.print_stack();
                cout << len << endl;
            }
            else if (Q == 5)
            {
                int topvalue = stack.topValue();
                stack.print_stack();
                cout << topvalue << endl;
            }
            else if (Q == 6)
            {
                if (stack.isEmpty())
                {
                    stack.print_stack();
                    cout << "Stack is empty." << endl;
                }
                else
                {
                    stack.print_stack();
                    cout << "Stack is non-empty." << endl;
                }
            }
        }
    }
    else if (stack_type == 2)
    {
        int X, K;
        cout << "Chunk size = ";
        cin >> X;
        cout << "The initial length of the stack = ";
        cin >> K;
        Stack<char> stack(X);
        for (int i = 0; i < K; i++)
        {
            char element;
            cin >> element;
            stack.push(element);
        }
        stack.print_stack();
        cout << "Select any of them." << endl;
        cout << "0.Exit the program." << endl;
        cout << "1.clear()" << endl;
        cout << "2.push(item)" << endl;
        cout << "3.pop()" << endl;
        cout << "4.length()" << endl;
        cout << "5.topValue()" << endl;
        cout << "6.isEmpty()" << endl;
        while (1)
        {
            int Q;
            char P;
            cin >> Q;
            if (Q == 0)
            {
                return 0;
            }
            else if (Q == 1)
            {
                stack.clear();
                stack.print_stack();
            }
            else if (Q == 2)
            {
                cin >> P;
                stack.push(P);
                stack.print_stack();
            }
            else if (Q == 3)
            {
                char pop = stack.pop();
                stack.print_stack();
                if (pop == '0')
                {
                    cout << "Stack is empty.Can't pop." << endl;
                }
                else
                {
                    cout << pop << endl;
                }
            }
            else if (Q == 4)
            {
                int len = stack.length();
                stack.print_stack();
                cout << len << endl;
            }
            else if (Q == 5)
            {
                char topvalue = stack.topValue();
                stack.print_stack();
                cout << topvalue << endl;
            }
            else if (Q == 6)
            {
                if (stack.isEmpty())
                {
                    stack.print_stack();
                    cout << "Stack is empty." << endl;
                }
                else
                {
                    stack.print_stack();
                    cout << "Stack is non-empty." << endl;
                }
            }
        }
    }
}