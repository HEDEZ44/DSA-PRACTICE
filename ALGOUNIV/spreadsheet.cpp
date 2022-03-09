#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    int f = 0;
    cin >> s;
    for (int i = 1; i < s.size() && s[0] == 'R'; i++)
    {
        if (s[i] == 'C' && isdigit(s[i - 1]))
        {
            f = 1;
            break;
        }
    }
    if (f)
    {
        int r = 0, c = 0, id, k = 0;
        string str;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == 'C')
            {
                id = i;
                break;
            }
            r = r * 10 + s[i] - '0';
        }
        for (int i = id + 1; i < s.size(); i++)
        {
            c = c * 10 + s[i] - '0';
        }
        while (c > 0)
        {
            k = 0;
            if (c % 26)
                str += 'A' + c % 26 - 1;
            else
                str += 'Z', k = 1;
            c /= 26;
            if (k)
                c--;
        }
        reverse(str.begin(), str.end());
        cout << str << r;
    }
    else
    {
        int c = 0, r = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                r = r * 10 + s[i] - '0';
            }
            else
            {
                c = c * 26 + s[i] - 'A' + 1;
            }
        }
        cout << 'R' << r << 'C' << c;
    }
    cout << endl;
}

int main()
{
    long long k;
    cin >> k;
    while (k--)
    {
        solve();
    }

    return 0;
}