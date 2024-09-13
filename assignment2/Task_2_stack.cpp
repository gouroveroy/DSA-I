#include <iostream>
#include "Task_1_stack.h"
#include <string>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNumber(char c)
{
    if (c >= 48 && c <= 57)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValid(string s)
{
    Stack<char> stack(100);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (stack.isEmpty())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
    }
    if (!stack.isEmpty())
    {
        return false;
    }
    stack.clear();
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            if (isOperator(s[i]) && s[i + 1] == '-')
            {
                s.insert(i + 1, "(");
            }
        }
        if (i + 1 < s.length())
        {
            if (s[i] == ')' && s[i + 1] == '(')
                s.insert(i + 1, "*");
        }
        if (i + 1 < s.length())
        {
            if (s[i] == '(' && s[i + 1] == '-')
            {
                s.insert(i + 1, "0");
            }
        }
        if (i + 1 < s.length())
        {
            if (isNumber(s[i]) && s[i + 1] == '(')
            {
                s.insert(i + 1, "*");
            }
        }
        if (i + 1 < s.length())
        {
            if (s[i] == ')' && isNumber(s[i + 1]))
            {
                s.insert(i + 1, "*");
            }
        }
    }
    if (!(s[0] == '(' || isNumber(s[0])) || !(s[s.length() - 1] == ')' || isNumber(s[s.length() - 1])))
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            if (isOperator(s[i]) && s[i + 1] == ')')
            {
                return false;
            }
        }
        if (i + 1 < s.length())
        {
            if (isOperator(s[i]) && !(isNumber(s[i + 1]) || s[i + 1] == '('))
            {
                return false;
            }
        }
        if (i - 1 >= 0)
        {
            if (isOperator(s[i]) && !(isNumber(s[i - 1]) || s[i - 1] == ')'))
            {
                return false;
            }
        }
        if (i + 1 < s.length())
        {
            if (s[i] == '(' && !(isNumber(s[i + 1]) || s[i + 1] == '('))
            {
                return false;
            }
        }
        if (i - 1 >= 0)
        {
            if (s[i] == ')' && !(isNumber(s[i - 1]) || s[i - 1] == ')'))
            {
                return false;
            }
        }
    }
    return true;
}

float Operation(float operand1, char opa_tor, float operand2)
{
    if (opa_tor == '+')
    {
        return (operand1 + operand2);
    }
    else if (opa_tor == '-')
    {
        return (operand2 - operand1);
    }
    else if (opa_tor == '*')
    {
        return (operand1 * operand2);
    }
    else if (opa_tor == '/')
    {
        return (operand2 / operand1);
    }
    return 0;
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}

float Calculation(string s)
{
    Stack<float> Operand(100);
    Stack<char> Operator(100);
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            if (isOperator(s[i]) && s[i + 1] == '-')
            {
                s.insert(i + 1, "(");
            }
        }
        if (i + 1 < s.length())
        {
            if (s[i] == ')' && s[i + 1] == '(')
            {
                s.insert(i + 1, "*");
            }
        }
        if (i + 1 < s.length())
        {
            if (s[i] == '(' && s[i + 1] == '-')
            {
                s.insert(i + 1, "0");
            }
        }
        if (i + 1 < s.length())
        {
            if (isNumber(s[i]) && s[i + 1] == '(')
            {
                s.insert(i + 1, "*");
            }
        }
        if (i + 1 < s.length())
        {
            if (s[i] == ')' && isNumber(s[i + 1]))
            {
                s.insert(i + 1, "*");
            }
        }
    }
    for (int i = 0; i < s.length();)
    {
        if (isNumber(s[i]))
        {
            string s1(s.length() - i, ' ');
            int k = 0;
            int j = i;
            while (j < s.length() && isNumber(s[j]))
            {
                s1[k] = s[j];
                k++;
                j++;
            }
            try
            {
                float value = stof(s1);
                Operand.push(value);
                i = j;
            }
            catch (const std::exception &e)
            {
                // std::cerr << e.what() << '\n';
            }
        }
        else if (s[i] == '(')
        {
            Operator.push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while (!Operator.isEmpty() && Operator.topValue() != '(')
            {
                float operand1 = Operand.topValue();
                Operand.pop();
                char opa_tor = Operator.topValue();
                Operator.pop();
                float operand2 = Operand.topValue();
                Operand.pop();
                Operand.push(Operation(operand1, opa_tor, operand2));
            }
            if (!Operator.isEmpty() && Operator.topValue() == '(')
            {
                Operator.pop();
            }
            i++;
        }
        else if (isOperator(s[i]))
        {
            while (!Operator.isEmpty() && precedence(s[i]) <= precedence(Operator.topValue()))
            {
                float operand1 = Operand.topValue();
                Operand.pop();
                char opa_tor = Operator.topValue();
                Operator.pop();
                float operand2 = Operand.topValue();
                Operand.pop();
                Operand.push(Operation(operand1, opa_tor, operand2));
            }
            Operator.push(s[i]);
            i++;
        }
    }
    while (!Operator.isEmpty())
    {
        float operand1 = Operand.topValue();
        Operand.pop();
        char opa_tor = Operator.topValue();
        Operator.pop();
        float operand2 = Operand.topValue();
        Operand.pop();
        Operand.push(Operation(operand1, opa_tor, operand2));
        if (Operator.topValue() == '(')
        {
            Operator.pop();
        }
    }
    return Operand.topValue();
}

int main()
{
    string expression;
    cin >> expression;
    if (isValid(expression))
    {
        cout << "Valid expression." << endl;
        float value = Calculation(expression);
        // cout.precition(3);
        cout << "Computed value: " << value << endl;
        // printf("Computed value: %.2f", value);
    }
    else
    {
        cout << "Not valid." << endl;
    }
    return 0;
}