#include <iostream>
#include <string>
//#include "Arr.cpp"
#include "LL.cpp"
using namespace std;

void print(List *crsList, int *garage, int Y)
{
    int *sort = new int[Y];
    for (int i = 0; i < Y; i++)
    {
        sort[i] = i + 1;
    }
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (sort[i] == garage[j])
            {
                int l = crsList[j].length();
                crsList[j].moveToStart();
                for (int k = 0; k < l; k++)
                {
                    int value = crsList[j].getValue();
                    cout << value << ' ';
                    crsList[j].next();
                }
                cout << endl;
                break;
            }
        }
    }
}

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    getchar();
    List *crsList = new List[Y];
    for (int i = 0; i < Y; i++)
    {
        string s1;
        string s2;
        getline(cin, s1);
        int j = 0;
        while (s1[j])
        {
            int l = 0;
            while (s1[j] != ' ' && s1[j])
            {
                s2[l] = s1[j];
                j++;
                l++;
            }
            s2[l] = '\0';
            int value = stoi(s2);
            crsList[i].init(value);
            if (s1[j] != '\0')
            {
                j++;
            }
            s1.clear();
            s2.clear();
        }
    }
    int *garage = new int[Y];
    for (int i = 0; i < Y; i++)
    {
        crsList[i].moveToStart();
        garage[i] = crsList[i].getValue();
        crsList[i].remove();
    }
    cout << endl
         << endl;
    print(crsList, garage, Y);
    string str;
    while (1)
    {
        for (int i = 0; i < Y; i++)
        {
            crsList[i].moveToStart();
        }
        cin >> str;
        if (str == "req")
        {
            int k = 1;
            int b = 0;
            for (int j = 0; j < Y; j++)
            {
                for (int i = 0; i < Y; i++)
                {
                    if (garage[i] == k)
                    {
                        if (crsList[i].length() == 0)
                        {
                            k++;
                            break;
                        }
                        else
                        {
                            int l = crsList[i].length();
                            int min = X + 1;
                            int pos;
                            while (l--)
                            {
                                if (crsList[i].getValue() < min)
                                {
                                    min = crsList[i].getValue();
                                    pos = crsList[i].currPos();
                                }
                                crsList[i].next();
                            }
                            crsList[i].moveToPos(pos);
                            crsList[i].remove();
                            b = 1;
                            break;
                        }
                    }
                }
                if (b == 1)
                {
                    break;
                }
            }
        }
        else if (str == "ret")
        {
            int car;
            cin >> car;
            int k = 4;
            int b = 0;
            for (int j = 0; j < Y; j++)
            {
                for (int i = 0; i < Y; i++)
                {
                    if (garage[i] == k)
                    {
                        if (crsList[i].length() == Z)
                        {
                            k--;
                            break;
                        }
                        else
                        {
                            int m;
                            int l = crsList[i].length();
                            int max = 0;
                            int pos = -1;
                            while (l--)
                            {
                                m = 0;
                                if (crsList[i].getValue() > max)
                                {
                                    max = crsList[i].getValue();
                                    pos = crsList[i].currPos();
                                    crsList[i].next();
                                    m = 1;
                                }
                                if(m == 0)
                                {
                                    crsList[i].next();
                                }
                            }
                            if(pos < crsList[i].length() - 1)
                            {
                                crsList[i].prev();
                            }
                            crsList[i].moveToPos(pos);
                            if (pos == crsList[i].length() - 1)
                            {
                                crsList[i].init(car);
                            }
                            else
                            {
                                crsList[i].next();
                                crsList[i].insert(car);
                            }
                            b = 1;
                            break;
                        }
                    }
                }
                if (b == 1)
                {
                    break;
                }
            }
        }
        else if (str == "end")
        {
            return 0;
        }
        print(crsList, garage, Y);
    }
}