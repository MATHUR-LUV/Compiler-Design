#include <bits/stdc++.h>
using namespace std;

bool solve1(string &s)
{
    int n = s.length();
    if (n < 2)
    {
        return false;
    }

    for (char c : s)
    {
        if (c == 'a' || c == 'b')
            continue;
        else
            return false;
    }

    if ((s[n - 1] == 'a' && s[n - 2] == 'a') || (s[n - 1] == 'b' && s[n - 2] == 'b'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool solve3(string &s)
{
    if (s.length() == 0)
    {
        return true;
    }

    /*
    for (char c : s) {
        if (c == 'a' || c == 'b' || c == 'c') continue;
        else return false;
    }
    */

    int i = 0;
    if (s[i] == 'a')
    {
        while (s[i] == 'a')
        {
            i++;
        }

        while (s[i] == 'b')
        {
            if (s[i] == 'a')
            {
                return false;
            }
            i++;
        }

        while (s[i] == 'c')
        {
            if (s[i] == 'a' || s[i] == 'c')
            {
                return false;
            }
            i++;
        }
    }
    else if (s[i] == 'b')
    {

        while (s[i] == 'b')
        {
            if (s[i] == 'a')
            {
                return false;
            }
            i++;
        }

        while (s[i] == 'c')
        {
            if (s[i] == 'a' || s[i] == 'c')
            {
                return false;
            }
            i++;
        }
    }
    else if (s[i] == 'c')
    {

        while (s[i] == 'c')
        {
            if (s[i] == 'a' || s[i] == 'c')
            {
                return false;
            }
            i++;
        }
    }

    return true;
}

bool star(int s, int &i, char c, string &str)
{
    i = s;
    while (i < str.length() && str[i] == c)
    {
        i++;
    }
    return i > s;
}

bool solve4(string &s)
{
    int i = 0;
    int n = s.length();

    bool f1 = false, f2 = false, f3 = false;

    if (s[0] == 'a' && star(1, i, 'b', s) && i < n && s[i] == 'c')
    {
        i++;
        f1 = (i == n);
    }
    i = 0;

    if (star(0, i, 'a', s) && i < n && s[i] == 'b')
    {
        i++;
        if (i < n && s[i] == 'c')
        {
            i++;
            f2 = (i == n);
        }
    }
    i = 0;

    if (s[0] == 'a' && s[1] == 'b' && star(2, i, 'c', s))
    {
        f3 = (i == n);
    }

    return f1 || f2 || f3;
}

bool solve5(string &s)
{
    if (s[0] == 'a')
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == 'a')
            {
                return false;
            }
        }
    }

    if (s[0] == 'b')
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == 'b')
            {
                return false;
            }
        }
    }

    if (s[0] == 'c')
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == 'c')
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    bool first = solve1(s);
    cout << first << endl;

    bool third = solve3(s);
    cout << third << endl;

    bool fourth = solve4(s);
    cout << fourth << endl;

    bool fifth = solve5(s);
    cout << fifth << endl;

    return 0;
}