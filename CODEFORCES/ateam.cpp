#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n, s;
        cin >> n >> s;
        if (n > s)
        {
            cout << 0 << endl;
            continue;
        }
        int sum = s;
        int i = 1;
        vector<int> ans;
        while (sum > i * i)
        {
            ans.push_back(i * i);
            i++;
        }
        i--;
        int count = 0;
        while (sum - ans[i] >= 0 && i >= 0)
        {
            sum -= ans[i];
            count++;
            if (sum - ans[i] < 0)
                i--;
        }
        cout << count << endl;
    }
    return 0;
}