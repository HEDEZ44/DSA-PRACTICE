#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d;
    cin >> d;
    vector<int> hated;
    for (int i = 0; i < d; i++)
    {
        int k;
        cin >> k;
        hated.push_back(k);
    }
    sort(hated.begin(), hated.end());
    long long N;
    cin >> N;
    int base = 10 - d;
    vector<int> notHated;
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i != hated[j])
            notHated.push_back(i);
        if (i == hated[j])
            j++;
    }

    vector<int> ans;
    while (N > 0)
    {
        int temp = N % base;
        ans.push_back(temp);
        N /= base;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = notHated[ans[i]];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}