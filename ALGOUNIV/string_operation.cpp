#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    str.insert(0, "0");
    int m;
    cin >> m;
    int n = str.length();

    for (int it = 0; it < m; it++)
    {
        int a;
        cin >> a;
        int i = a;
        int j = n - i;
        while (i < j)
        {
            swap(str[i], str[j]);
        }
    }
    cout << str.substr(1);

    return 0;
}