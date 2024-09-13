#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    char s[1000];
    char s1[1500];
    char num[10];
    cin >> s;
    int n = strlen(s);
    int count = 0;
    int k = 0;
    for (int i = 0; i < n;)
    {
        count = 0;
        for (int j = i; j < n; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        s1[k] = s[i];
        k++;
        sprintf(num, "%d", count);
        for (int l = 0; l < strlen(num); l++)
        {
            s1[k] = num[l];
            k++;
        }
        i = i + count;
    }
    if (strlen(s) >= strlen(s1))
    {
        cout << s1 << endl;
    }
    else
    {
        cout << s1 << endl;
        cout << s << endl;
    }
    return 0;
}